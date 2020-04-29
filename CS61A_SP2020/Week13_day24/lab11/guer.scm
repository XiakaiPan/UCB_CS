;1.2
(define (merge s1 s2)
  (cond ((null? s1) s2)
	((null? s2) s1)
	(if (< (car s1) (car s2))
	  (cons (car s1) (merge (cdr s1) s2))
	  (cons (car s2) (merge s1 (cdr s2)))
	  )
	)
  )

