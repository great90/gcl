;-*- Mode:     Lisp -*-
;;;; Author:   Paul Dietz
;;;; Created:  Tue Jan 27 20:57:05 2004
;;;; Contains: Tests of WITH-OPEN-FILE

(in-package :cl-test)

;;; For now, omit most of the options combinations, assuming they will
;;; be tested in OPEN.  The tests of OPEN should be ported to here at some
;;; point.

(deftest with-open-file.1
  (let ((pn #p"tmp.dat"))
    (delete-all-versions pn)
    (with-open-file (s pn :direction :output)))
  nil)

(deftest with-open-file.2
  (let ((pn #p"tmp.dat"))
    (delete-all-versions pn)
    (with-open-file
     (s pn :direction :output)
     (notnot-mv (output-stream-p s))))
  t)

(deftest with-open-file.3
  (let ((pn #p"tmp.dat"))
    (delete-all-versions pn)
    (with-open-file
     (s pn :direction :output)
     (values))))

(deftest with-open-file.4
  (let ((pn #p"tmp.dat"))
    (delete-all-versions pn)
    (with-open-file
     (s pn :direction :output)
     (values 1 2 3 4 5 6 7 8)))
  1 2 3 4 5 6 7 8)

(deftest with-open-file.5
  (let ((pn #p"tmp.dat"))
    (delete-all-versions pn)
    (with-open-file
     (s pn :direction :output)
     (declare (ignore s))))
  nil)

(deftest with-open-file.6
  (let ((pn #p"tmp.dat"))
    (delete-all-versions pn)
    (with-open-file
     (s pn (cdr '(nil . :direction)) (car '(:output)))
     (format s "foo!~%"))
    (with-open-file (s pn) (read-line s)))
  "foo!" nil)
