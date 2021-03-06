;; -*-Lisp-*-
;;This file is included as a demonstration of how to link in low level
;;C code.   It is also useful! [comments by wfs]
;;Author: Mark Ring  (ring@cs.utexas.edu)

;; In the next comment we explain how to link in the file
;; and then a sample usage.

#|
If you have si::faslink you may use: 
(si::faslink "/public/gcl/lsp/littleXlsp.o" "/public/gcl/o/littleXwin.o -lX11 -lc")

To avoid using faslink which is much less portable, 
when building the gcl image you may add
EXTRAS=${ODIR}/littleXwin.o
LIBS= -lX -lm -lg
to the h/machine.defs, redo the add-defs machine, and remake so that
the low level X code will be linked in.
Then you may simply
(load "/public/gcl/lsp/littleXlsp.o")

;;Now you may try the following examples: 



(setq W1 (open-window))
(setq W2 (open-window))
(resize-window w1 200 150)
(resize-window w2 240 225)

(set-background w1 "red")
(clear-window w1)
(set-foreground "blue")

(draw-line w1 5 5 100 5)
(draw-line w1 100 100 100 5)
(draw-line w1 100 100 5 100)
(dotimes (i 20)
  (draw-line w1 5 (* i 5) (* i 5) (* i 5)))
(dotimes (i 20)
  (erase-line w1 (+ 7 (* i 5)) 10 (+ 7 (* i 5)) 95))
(use-font "fixed")
(draw-text w1 "A Design" 10 112)
(clear-text w1 "De" 22 112)

(dotimes (i 25)
  (set-background w2 (format nil "#~2,'0X~2,'0X~2,'0X" (* i 10) (* i 10) (* i 10)))
  (clear-window w2))

(set-foreground "black")
(dotimes (i 20)
  (draw-arc w2 5 100 100 (- 100 (* i 5)) 0 (* 360 64)))
(dotimes (i 20)
  (draw-arc w2 5 (- 100 (* i 5)) 100 (* i 5) 0 (* 360 64)))
(set-arc-mode 'pie)
(dotimes (i 10)
  (fill-arc w2 115 5 100 100 (* i 64 36) (* 64 18)))
(set-arc-mode 'chord)
(dotimes (i 10)
  (fill-arc w2 115 105 100 100 (* i 64 36) (* 64 36 3)))
(dotimes (i 5)
  (clear-arc w2 115 105 100 100 (* i 64 36 2) (* 64 36 2)))
(use-font "-b&h-lucidabright-demibold-i-normal--18-180-75-75-p-107-iso8859-1")
(draw-text w2 "A Bunch of Wierd Things" 2 220)

(clear-window w1)

(close-window w1)
(close-window w2)
|#





;;; Open a window.  Return window ID as an Integer
(defentry open-window () (int open_window))

;;; Close given window.
;;;   Parameter 1:  Window ID.
(defentry close-window (int) (int close_window))

;;; Clear a window of its contents.
;;;   Parameter 1:  Window ID.
(defentry clear-window (int) (int clear_window))

;;; Draw a line in a window.
;;;   Parameter 1:  Window ID.
;;;   Parameter 2:  left-most x coordinate
;;;   Parameter 3:  top-most y coordinate
;;;   Parameter 4:  right-most x coordinate
;;;   Parameter 5:  bottom-most y coordinate
(defentry draw-line (int int int int int) (int draw_line))

;;; Erase a line from a window.
;;;   Parameter 1:  Window ID.
;;;   Parameter 2:  left-most x coordinate
;;;   Parameter 3:  top-most y coordinate
;;;   Parameter 4:  right-most x coordinate
;;;   Parameter 5:  bottom-most y coordinate
(defentry erase-line (int int int int int) (int erase_line))

;;; Draw an arc in a window. (See X Documentation).
;;;   Parameter 1:  Window ID.
;;;   Parameter 2:  left-most x coordinate
;;;   Parameter 3:  top-most y coordinate
;;;   Parameter 4:  width of square
;;;   Parameter 5:  height of square
;;;   Parameter 6:  starting position: angle 1 (from 3:00)
;;;   Parameter 7:  ending position: angle 2 (from angle 1)
;;;        Angles are specified in 64ths of a degree and go counter-clockwise
(defentry draw-arc (int int int int int int int) (int draw_arc))

;;; Clear an arc from a window. (See X Documentation).
;;;   Parameter 1:  Window ID.
;;;   Parameter 2:  left-most x coordinate
;;;   Parameter 3:  top-most y coordinate
;;;   Parameter 4:  width of square
;;;   Parameter 5:  height of square
;;;   Parameter 6:  starting position: angle 1 (from 3:00)
;;;   Parameter 7:  ending position: angle 2 (from angle 1)
;;;        Angles are specified in 64ths of a degree and go counter-clockwise
(defentry clear-arc (int int int int int int int) (int clear_arc))

;;; Draw a filled arc in a window. (See X Documentation).
;;;   Parameter 1:  Window ID.
;;;   Parameter 2:  left-most x coordinate
;;;   Parameter 3:  top-most y coordinate
;;;   Parameter 4:  width of square
;;;   Parameter 5:  height of square
;;;   Parameter 6:  starting position: angle 1 (from 3:00)
;;;   Parameter 7:  ending position: angle 2 (from angle 1)
;;;        Angles are specified in 64ths of a degree and go counter-clockwise
(defentry fill-arc  (int int int int int int int) (int fill_arc))

;;; Resize a window.
;;;   Parameter 1:  Window ID.
;;;   Parameter 2:  new width
;;;   Parameter 3:  new height
(defentry resize-window (int int int) (int resize_window))

;;; Raise a window to the front.
;;;   Parameter 1:  Window ID.
(defentry raise-window (int) (int raise_window))

;;; Draw Text in a window.
;;;   Parameter 1:  Window ID.
;;;   Parameter 2:  text string
;;;   Parameter 3:  left-most x coordinate
;;;   Parameter 4:  top-most y coordinate 
(defentry draw-text-2 (int object int int) (int draw_text))
(defun    draw-text (window string x y)
  (draw-text-2 window (get-c-string string) x y))

;;; Clear text from a window
;;;   Parameter 1:  Window ID
;;;   Parameter 2:  text string
;;;   Parameter 3:  left-most x coordinate
;;;   Parameter 4:  top-most y coordinate 
(defentry clear-text-2 (int object int int) (int erase_text))
(defun    clear-text (window string x y)
  (clear-text-2 window (get-c-string string) x y))

;;; Set arc-mode to be Pie or Chord
;;;   Parameter 1:  'PIE or 'CHORD
(defentry set-arc-mode-2 (int) (int set_arc_mode))
(defun    set-arc-mode (pie-or-chord)
  (if (eq pie-or-chord 'pie)
      (set-arc-mode-2 1)
      (set-arc-mode-2 0)))

;;; Use a particular font in a given window
;;;   Parameter 1:  font name
(defentry use-font-2 (object) (int use_font))
(defun    use-font (string)
  (use-font-2 (get-c-string string)))

;;; Set background color of window
;;;   Parameter 1:  Window ID
;;;   Parameter 2:  color name (string)
(defentry set-background-2 (int object) (int set_background))
(defun    set-background   (window string)
  (set-background-2 window (get-c-string string)))

;;; Set foreground color 
;;;   Parameter 1:  color name (string)
(defentry set-foreground-2 (object) (int set_foreground))
(defun    set-foreground   (string)
  (set-foreground-2 (get-c-string string)))

;;;----------------------------------------------------------------------
;;; General routines.
(defCfun "object get_c_string(s) object s;" 0
  " return(s->st.st_self);"
  )
(defentry get_c_string_2 (object) (object get_c_string))

/* make sure string is null terminated */
(defun get-c-string (string)
  (get_c_string_2 (concatenate 'string string " ")))

