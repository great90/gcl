;;; -*- Mode: Lisp; Syntax: Common-Lisp; Package: "CONDITIONS"; Base: 10 -*-

(in-package :CONDITIONS)

(DEFVAR *DEBUG-LEVEL* 0)
(DEFVAR *DEBUG-ABORT* NIL)
(DEFVAR *DEBUG-CONTINUE* NIL)
(DEFVAR *DEBUG-CONDITION* NIL)
(DEFVAR *DEBUG-RESTARTS* NIL)
(DEFVAR *NUMBER-OF-DEBUG-RESTARTS* 0)
(DEFVAR *DEBUG-EVAL* 'EVAL)
(DEFVAR *DEBUG-PRINT* #'(LAMBDA (VALUES) (FORMAT T "~&~{~S~^,~%~}" VALUES)))

(DEFMACRO DEBUG-COMMAND                (X) `(GET ,X 'DEBUG-COMMAND))
(DEFMACRO DEBUG-COMMAND-ARGUMENT-COUNT (X) `(GET ,X 'DEBUG-COMMAND-ARGUMENT-COUNT))

(DEFMACRO DEFINE-DEBUG-COMMAND (NAME BVL &REST BODY)
  `(PROGN (SETF (DEBUG-COMMAND ',NAME) #'(LAMBDA ,BVL ,@BODY))
          (SETF (DEBUG-COMMAND-ARGUMENT-COUNT ',NAME) ,(LENGTH BVL))
          ',NAME))

(DEFUN READ-DEBUG-COMMAND ()
  (FORMAT T "~&Debug ~D> " *DEBUG-LEVEL*)
  (COND ((CHAR= (PEEK-CHAR T) #\:)
	 (READ-CHAR) ;Eat the ":" so that ":1" reliably reads a number.
	 (WITH-INPUT-FROM-STRING (STREAM (READ-LINE))
	   (LET ((EOF (LIST NIL)))
	     (DO ((FORM (LET ((*PACKAGE* (FIND-PACKAGE "KEYWORD")))
			  (READ STREAM NIL EOF))
			(READ STREAM NIL EOF))
		  (L '() (CONS FORM L)))
		 ((EQ FORM EOF) (NREVERSE L))))))
	(T
	 (LIST :EVAL (READ)))))
                   
(DEFINE-DEBUG-COMMAND :EVAL (FORM)
  (FUNCALL *DEBUG-PRINT* (MULTIPLE-VALUE-LIST (FUNCALL *DEBUG-EVAL* FORM))))

(DEFINE-DEBUG-COMMAND :ABORT ()
  (IF *DEBUG-ABORT*
      (INVOKE-RESTART-INTERACTIVELY *DEBUG-ABORT*)
      (FORMAT T "~&There is no way to abort.~%")))

(DEFINE-DEBUG-COMMAND :CONTINUE ()
  (IF *DEBUG-CONTINUE*
      (INVOKE-RESTART-INTERACTIVELY *DEBUG-CONTINUE*)
      (FORMAT T "~&There is no way to continue.~%")))

(DEFINE-DEBUG-COMMAND :ERROR ()
  (FORMAT T "~&~A~%" *DEBUG-CONDITION*))

(DEFINE-DEBUG-COMMAND :HELP ()
  (FORMAT T "~&You are in a portable debugger.~
             ~%Type a debugger command or a form to evaluate.~
             ~%Commands are:~%")
  (SHOW-RESTARTS *DEBUG-RESTARTS* *NUMBER-OF-DEBUG-RESTARTS* 16)
  (FORMAT T "~& :EVAL form     Evaluate a form.~
             ~% :HELP          Show this text.~%")
  (IF *DEBUG-ABORT*    (FORMAT T "~& :ABORT         Exit by ABORT.~%"))
  (IF *DEBUG-CONTINUE* (FORMAT T "~& :CONTINUE      Exit by CONTINUE.~%"))
  (FORMAT T "~& :ERROR         Reprint error message.~%"))



(defvar *debug-command-prefix* ":")

(DEFUN SHOW-RESTARTS (&OPTIONAL (RESTARTS *DEBUG-RESTARTS*)
		      		(MAX *NUMBER-OF-DEBUG-RESTARTS*)
				TARGET-COLUMN)
  (UNLESS MAX (SETQ MAX (LENGTH RESTARTS)))
  (WHEN RESTARTS
    (DO ((W (IF TARGET-COLUMN
		(- TARGET-COLUMN 3)
		(CEILING (LOG MAX 10.0))));FIXME
         (P RESTARTS (CDR P))
         (I 0 (1+ I)))
        ((OR (NOT P) (= I MAX)))
      (FORMAT T "~& ~A~A "
	      *debug-command-prefix*
	      (LET ((S (FORMAT NIL "~D" (+ I 1))))
		(WITH-OUTPUT-TO-STRING (STR)
		  (FORMAT STR "~A" S)
		  (DOTIMES (I (- W (LENGTH S)))
		    (WRITE-CHAR #\Space STR)))))
      (IF (EQ (CAR P) *DEBUG-ABORT*) (FORMAT T "(Abort) "))
      (IF (EQ (CAR P) *DEBUG-CONTINUE*) (FORMAT T "(Continue) "))
      (FORMAT T "~A" (CAR P))
      (FORMAT T "~%"))))

(defvar *DEBUGGER-HOOK* nil)
(defvar *debugger-function* 'STANDARD-DEBUGGER)

(DEFUN INVOKE-DEBUGGER (condition)
  (WHEN *DEBUGGER-HOOK*
	(LET ((HOOK *DEBUGGER-HOOK*)
	      (*DEBUGGER-HOOK* NIL))
	     (FUNCALL HOOK CONDITION HOOK)))
  (funcall *debugger-function* CONDITION)
  (throw si::*quit-tag* si::*quit-tag*))

(DEFUN STANDARD-DEBUGGER (CONDITION)
  (LET* ((*DEBUG-LEVEL* (1+ *DEBUG-LEVEL*))
	 (*DEBUG-RESTARTS* (COMPUTE-RESTARTS))
	 (*NUMBER-OF-DEBUG-RESTARTS* (LENGTH *DEBUG-RESTARTS*))
	 (*DEBUG-ABORT*    (FIND-RESTART 'ABORT))
	 (*DEBUG-CONTINUE* (OR (LET ((C (FIND-RESTART 'CONTINUE)))
				 (IF (OR (NOT *DEBUG-CONTINUE*)
					 (NOT (EQ *DEBUG-CONTINUE* C)))
				     C NIL))
			       (LET ((C (IF *DEBUG-RESTARTS*
					    (FIRST *DEBUG-RESTARTS*) NIL)))
				 (IF (NOT (EQ C *DEBUG-ABORT*)) C NIL))))
	 (*DEBUG-CONDITION* CONDITION))
    (FORMAT T "~&~A~%" CONDITION)
    (SHOW-RESTARTS)
    (DO ((COMMAND (READ-DEBUG-COMMAND)
		  (READ-DEBUG-COMMAND)))
	(NIL)
      (EXECUTE-DEBUGGER-COMMAND (CAR COMMAND) (CDR COMMAND) *DEBUG-LEVEL*))))

(DEFUN EXECUTE-DEBUGGER-COMMAND (CMD ARGS LEVEL)
  (WITH-SIMPLE-RESTART (ABORT "Return to debug level ~D." LEVEL)
    (COND ((NOT CMD))
	  ((INTEGERP CMD)
	   (COND ((AND (PLUSP CMD)
		       (< CMD (+ *NUMBER-OF-DEBUG-RESTARTS* 1)))
		  (LET ((RESTART (NTH (- CMD 1) *DEBUG-RESTARTS*)))
		    (IF ARGS
			(APPLY #'INVOKE-RESTART RESTART (MAPCAR *DEBUG-EVAL* ARGS))
			(INVOKE-RESTART-INTERACTIVELY RESTART))))
		 (T
		  (FORMAT T "~&No such restart."))))
	  (T
	   (LET ((FN (DEBUG-COMMAND CMD)))
	     (IF FN
		 (COND ((NOT (= (LENGTH ARGS) (DEBUG-COMMAND-ARGUMENT-COUNT CMD)))
			(FORMAT T "~&Too ~:[few~;many~] arguments to ~A."
				(> (LENGTH ARGS) (DEBUG-COMMAND-ARGUMENT-COUNT CMD))
				CMD))
		       (T
			(APPLY FN ARGS)))
		 (FORMAT T "~&~S is not a debugger command.~%" CMD)))))))

