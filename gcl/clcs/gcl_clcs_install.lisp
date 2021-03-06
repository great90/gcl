;;; -*- Mode: Lisp; Syntax: Common-Lisp; Package: "CONDITIONS"; Base: 10 -*-

(in-package :conditions)

(eval-when
 (compile load eval)
 (mapc (lambda (x) (setf (symbol-function (intern (concatenate 'string "OLD-" (symbol-name x)))) (symbol-function x)))
       '(compile-file compile import open delete-package load)))

(eval-when 
 (load eval)

 (defun compile-file (file &rest args)
   (let (warnings failures)
     (handler-bind
      ((warning (lambda (c) 
		  (setq warnings t) 
		  (unless (typep c 'style-warning)
		   (setq failures t))
		  (when (not compiler::*compile-verbose*) 
		    (invoke-restart (find-restart 'muffle-warning c)))))
       (error (lambda (c)
		(declare (ignore c))
		(setq failures t))))
      (loop 
       (with-simple-restart 
	(retry "Retry compiling file ~S." file)
	(let ((res (apply 'old-compile-file file args)))
	  (when compiler::*error-p* 
	    (error 'program-error 
		   :format-control "Compilation of ~s failed."
		   :format-arguments (list file)))
	  (return (values res warnings failures))))))))
 
 (defun compile (name &optional def)
   (let (warnings failures)
     (handler-bind
      ((warning (lambda (c) 
		  (setq warnings t) 
		  (unless (typep c 'style-warning)
		    (setq failures t))
		  (when (not compiler::*compile-verbose*) 
		    (invoke-restart (find-restart 'muffle-warning c)))))
       (error (lambda (c)
		(declare (ignore c))
		(setq failures t))))
      (loop 
       (with-simple-restart 
	(retry "Retry compiling ~S." (list name def))
	(let ((res (old-compile name def)))
	  (when compiler::*error-p* (error 'program-error :format-control "Compilation of ~s failed." 
					   :format-arguments (list (list name def))))
	  (return (values res warnings failures))))))))
 
 (defun import (s &optional (p *package*))
   (loop (with-simple-restart 
	  (retry "Retry importing ~S into ~S." s p)
	  (return (old-import s p)))))
 
 (defun delete-package (p)
   (loop (with-simple-restart 
	  (retry "Retry deleting ~S." p)
	  (return (old-delete-package p)))))
 
 (defun load (pn &rest args)
   (loop (with-simple-restart 
	  (retry "Retry loading file ~S." (car args))
	  (return (apply 'old-load pn args)))))
 
 (defun open (pn &rest args)
   (loop (with-simple-restart 
	  (retry "Retry opening file ~S." (car args))
	  (return (apply 'old-open pn args))))))

