;;; CMPTYPE  Type information.
;;;
;; Copyright (C) 1994 M. Hagiya, W. Schelter, T. Yuasa

;; This file is part of GNU Common Lisp, herein referred to as GCL
;;
;; GCL is free software; you can redistribute it and/or modify it under
;;  the terms of the GNU LIBRARY GENERAL PUBLIC LICENSE as published by
;; the Free Software Foundation; either version 2, or (at your option)
;; any later version.
;; 
;; GCL is distributed in the hope that it will be useful, but WITHOUT
;; ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
;; FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Library General Public 
;; License for more details.
;; 
;; You should have received a copy of the GNU Library General Public License 
;; along with GCL; see the file COPYING.  If not, write to the Free Software
;; Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.


(in-package 'compiler)

;;; CL-TYPE is any valid type specification of Common Lisp.
;;;
;;; TYPE is a representation type used by KCL.  TYPE is one of:
;;;
;;;				T(BOOLEAN)
;;;
;;;	FIXNUM  CHARACTER  SHORT-FLOAT  LONG-FLOAT
;;;	(VECTOR T)  STRING  BIT-VECTOR  (VECTOR FIXNUM)
;;;	(VECTOR SHORT-FLOAT)  (VECTOR LONG-FLOAT)
;;;	(ARRAY T)  (ARRAY STRING-CHAR)  (ARRAY BIT)
;;;	(ARRAY FIXNUM)
;;;	(ARRAY SHORT-FLOAT)  (ARRAY LONG-FLOAT)
;;;	UNKNOWN
;;;
;;;				NIL
;;;
;;;
;;; immediate-type:
;;;	FIXNUM		int
;;;	CHARACTER	char
;;;	SHORT-FLOAT	float
;;;	LONG-FLOAT	double


;;; Check if THING is an object of the type TYPE.
;;; Depends on the implementation of TYPE-OF.
(defun object-type (thing)
  (let ((type (type-of thing)))
    (case type
      ((fixnum bignum) `(integer ,thing ,thing))
      ((short-float long-float) type)
      ((string-char standard-char character) 'character)
      ((string bit-vector) type)
      (vector (list 'vector (array-element-type thing)))
      (array (list 'array (array-element-type thing)))
      (t t))))   ;   'unknown ;; I can't see any use of this

(defun type-filter (type)
  (case type
        ((fixnum character short-float long-float) type)
        (single-float 'long-float)
	(boolean 'boolean)
        (double-float 'long-float)
        ((simple-string string) 'string)
        ((simple-bit-vector bit-vector) 'bit-vector)
	((nil t) t)
        (t (let ((type (si::normalize-type type)) element-type)
             (case (car type)
               ((simple-array array)
                (cond ((or (endp (cdr type))
                           (not (setq element-type
				      (cond ((eq '*  (cadr type)) nil)
					    ((si::best-array-element-type
					       (cadr type)))
					    (t t)))))
                       t)	; I don't know.
                      ((and (not (endp (cddr type)))
                            (not (eq (caddr type) '*))
			    (or (eql (caddr type) 1)
				(and (consp (caddr type))
				     (= (length (caddr type)) 1))))
                       (case element-type
                         (string-char 'string)
                         (bit 'bit-vector)
                         (t (list 'vector element-type))))
                      (t (list 'array element-type))))
               ((integer signed-byte unsigned-byte) type)
               ((short-float) 'short-float)
               ((long-float double-float single-float) 'long-float)
	       ((stream) 'stream)
               (t (cond ((subtypep type 'fixnum) 'fixnum)
			((subtypep type 'integer) 'integer)
                        ((subtypep type 'character) 'character)
                        ((subtypep type 'short-float) 'short-float)
                        ((subtypep type 'long-float) 'long-float)
                        ((subtypep type '(vector t)) '(vector t))
                        ((subtypep type 'string) 'string)
                        ((subtypep type 'bit-vector) 'bit-vector)
                        ((subtypep type '(vector fixnum)) '(vector fixnum))
                        ((subtypep type '(vector short-float))
                         '(vector short-float))
                        ((subtypep type '(vector long-float))
                         '(vector long-float))
                        ((subtypep type '(array t)) '(array t))
                        ((subtypep type '(array string-char))
                         '(array string-char))
                        ((subtypep type '(array bit)) '(array bit))
                        ((subtypep type '(array fixnum)) '(array fixnum))
                        ((subtypep type '(array short-float))
                         '(array short-float))
                        ((subtypep type '(array long-float))
                         '(array long-float))
			((eq (car type) 'values)
			 (if  (null (cddr type))
			     (list 'values (type-filter (second type)))
			   t))
			((and (eq (car type) 'satisfies)
			    (symbolp (second type))
			    (get (second type) 'type-filter)))
                        (t t)))
               )))))

(defun promoted-c-type (type)
  (let ((type (coerce-to-one-value type)))
    (if (integer-typep type)
	(cond ;((subtypep type 'signed-char) 'signed-char)
	 ((subtypep type 'fixnum) 'fixnum)
	 ((subtypep type 'integer) 'integer)
	 (t  (error "Cannot promote type ~S to C type~%" type)))
      type)))

(defun ash-propagator (f t1 t2)
  (and
   (type>= 'fixnum t1)
   (type>= '(integer #.most-negative-fixnum #.(integer-length most-positive-fixnum)) t2)
   (super-range f t1 t2)))

(defun floor-propagator (f t1 &optional (t2 '(integer 1 1)))
  (let ((t1 (coerce-to-integer-type t1))
	(t2 (coerce-to-integer-type t2)))
    (and t2
	 (let ((i21 (integerp (cadr t2)))
	       (i22 (integerp (caddr t2))))
	   (and i21 i22 (> (* (cadr t2) (caddr t2)) 0)
		(let ((sr (super-range f t1 t2)))
		  (and sr
		       (list 'values sr
			     (let ((outer (if (< (cadr t2) 0) (cadr t2) (caddr t2))))
			       (let ((a (cadr (multiple-value-list
					      (funcall (symbol-function f) 1 outer))))
				     (b (cadr (multiple-value-list
					       (funcall (symbol-function f) -1 outer))))
				     (c (cadr (multiple-value-list
					       (funcall (symbol-function f) (1+ outer) outer))))
				     (d (cadr (multiple-value-list
					       (funcall (symbol-function f) (1- outer) outer)))))
				 (let ((p (min a b c d)))
				   (if (< p 0)
				       (list (car t2) p 0)
				     (list (car t2) 0 (max a b c d))))))))))))))


(defun super-range (f t1 &optional (t2 nil t2p))
  (let ((t1 (coerce-to-integer-type t1)))
    (and t1
	 (let ((i11 (integerp (cadr t1)))
	       (i12 (integerp (caddr t1))))
	   (if (and i11 i12)
	       (if t2p
		   (let ((t2 (coerce-to-integer-type t2)))
		     (and t2 (eq (car t1) (car t2))
			  (let ((i21 (integerp (cadr t2)))
				(i22 (integerp (caddr t2))))
			    (if (and i21 i22)
				(let ((a (funcall (symbol-function f) (cadr t1) (cadr t2)))
				      (b (funcall (symbol-function f) (cadr t1) (caddr t2)))
				      (c (funcall (symbol-function f) (caddr t1) (cadr t2)))
				      (d (funcall (symbol-function f) (caddr t1) (caddr t2))))
				  (list (car t1) (min a b c d) (max a b c d)))
			      (list (car t1) '* '*)))))
		 (let ((a (funcall (symbol-function f) (cadr t1)))
		       (b (funcall (symbol-function f) (caddr t1))))
		   (list (car t1) (min a b) (max a b))))
	     (list (car t1) '* '*))))))

(defun integer-typep (type)
  (and (consp type)
       (member (car type) '(integer signed-byte unsigned-byte) :test #'eq)
       (let ((l (length type)))
	 (and (<= 1 l 3)
	      (or (< l 2) (integerp (cadr type)) (eq (cadr type) '*))
	      (or (< l 3) (integerp (caddr type)) (eq (caddr type) '*)))))))

(defun coerce-to-integer-type (t1)
  (if (integer-typep t1) t1
    (let ((t1 (si::normalize-type t1)))
      (if (integer-typep t1) t1))))

(defun integer-type-and (type1 type2)
  (let ((ct1 (coerce-to-integer-type type1))
	(ct2 (coerce-to-integer-type type2)))
    (and ct1 ct2
	 (eq (car ct1) (car ct2))
	 (let ((b1 (cadr ct1))
	       (e1 (caddr ct1))
	       (b2 (cadr ct2))
	       (e2 (caddr ct2)))
	   (let ((i11 (integerp b1))
		 (i12 (integerp e1))
		 (i21 (integerp b2))
		 (i22 (integerp e2)))
	     (let ((br (if i11 (if i21 (max b1 b2) b1) (if i21 b2 '*)))
		   (er (if i12 (if i22 (min e1 e2) e1) (if i22 e2 '*))))
	       (let ((t12 (and (eql br b1) (eql er e1) type1))
		     (t21 (and (eql br b2) (eql er e2) type2)))
		     (or (and t12 t21)
			 t12 t21
			 (and (or (eq br '*) (eq er '*) (<= br er))
			      (list (car ct1) br er))))))))))
    

(defun type-and (type1 type2)
  
  (cond ((equal type1 type2) type1)
	((and (consp type2) (eq (car type2) 'values))
	 (if (and (consp type1) (eq (car type1) 'values))
	     (let ((r (list 'values)))
	       (do ((t1 (cdr type1) (cdr t1))
		    (t2 (cdr type2) (cdr t2)))
		   ((not (and (consp t1) (consp t2))) (nreverse r))
		 (push (type-and (car t1) (car t2)) r)))
	   (type-and type1 (second type2))))
	((and (consp type1) (eq (car type1) 'values))
	   (type-and (second type1) type2))
        ((eq type1 t) type2)
	((eq type1 '*) type2)
	((eq type1 'object) type2)
	((eq type2 'object) type1)
        ((eq type2 t) type1)
	((eq type2 '*) type1)
	((or (integer-typep type1) (integer-typep type2))
	 (integer-type-and type1 type2))
        ((consp type1)
         (case (car type1)
               (array
                (case (cadr type1)
                      (string-char (if (eq type2 'string) type2 nil))
                      (bit (if (eq type2 'bit-vector) type2 nil))
                      (t (if (and (consp type2)
                                  (eq (car type2) 'vector)
                                  (eq (cadr type1) (cadr type2)))
                             type2 nil))))
               (vector
                (if (and (consp type2) (eq (car type2) 'array)
                         (eq (cadr type1) (cadr type2)))
                    type1 nil))
               (t nil)))
        (t (case type1
                 (string
                  (if (and (consp type2) (eq (car type2) 'array)
                           (eq (cadr type2) 'string-char))
                      type1 nil))
                 (bit-vector
                  (if (and (consp type2) (eq (car type2) 'array)
                           (eq (cadr type2) 'bit))
                      type1 nil))
                 (fixnum-float
                  (if (member type2 '(fixnum float short-float long-float))
                      type2 nil))
                 (float
                  (if (member type2 '(short-float long-float))
                      type2 nil))
                 ((long-float short-float)
                  (if (member type2 '(fixnum-float float))
                      type1 nil))
		 ((signed-char unsigned-char signed-short)
		  (if (eq type2 'fixnum) type1 nil))
		 ((unsigned-short)
		  (if (subtypep type1 type2) type1 nil))
		 (integer
		  (case type2
		    (fixnum type2)))
		 (fixnum
		   (case type2
		     ((integer fixnum-float) 'fixnum)
		     ((signed-char unsigned-char signed-short bit)
		      type2)
		     ((unsigned-short)
		      (if (subtypep type2 type1) type2 nil))))
		 ))))

(defun type>= (type1 type2)
  (equal (type-and type1 type2) type2))

(defun reset-info-type (info)
  (if (info-type info)
      (let ((info1 (copy-info info)))
           (setf (info-type info1) t)
           info1)
      info))

(defun and-form-type (type form original-form &aux type1)
  (setq type1 (type-and type (info-type (cadr form))))
  (when (null type1)
        (cmpwarn "The type of the form ~s is not ~s." original-form type))
  (if (eq type1 (info-type (cadr form)))
      form
      (let ((info (copy-info (cadr form))))
           (setf (info-type info) type1)
           (list* (car form) info (cddr form)))))

(defun check-form-type (type form original-form)
  (when (null (type-and type (info-type (cadr form))))
        (cmpwarn "The type of the form ~s is not ~s." original-form type)))

(defun default-init (type)
  (case (promoted-c-type type)
        (fixnum (cmpwarn "The default value of NIL is not FIXNUM."))
        (character (cmpwarn "The default value of NIL is not CHARACTER."))
        (long-float (cmpwarn "The default value of NIL is not LONG-FLOAT."))
        (short-float (cmpwarn "The default value of NIL is not SHORT-FLOAT."))
	(integer (cmpwarn "The default value of NIL is not INTEGER"))
	
        )
  (c1nil))
