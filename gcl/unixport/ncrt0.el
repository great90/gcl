(setq case-replace nil)
(setq case-fold-search nil)
(insert-file "/lib/crt0.o")
(replace-string "_moncontrol" "_Moncontrol")
(goto-char (point-min))
(replace-string " mcount " " Mcount ")
(write-file "ncrt0.o")



