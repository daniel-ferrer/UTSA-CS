;;; p3LispRun.txt begins ...
;; test +=
(setf x 10 y 5)
(+= x 5)
(print x)
(+= y x)
(print y)


;; iterate
(iterate i 1 5 1
     (print (list 'one i) )
)

(setf n 5)
  
(iterate i 1 n 1
     (print (list 'two i n))
     (+=  i 1)
)

(setf n 5)

(iterate i 1 n 1
     (print (list 'three i n))
     (+= n 1)
)

(setf n 5)
(setf inc 2)

(iterate i 1 n inc
     (print (list 'three i n inc))
     (+= inc 1)
)

(setf n 5)
(setf inc 2)
(iterate i 1 (+ n 2) inc
     (print (list 'four i n inc))
     (+= n 1)
     (+= i 1)
     (+= inc 1)
)
