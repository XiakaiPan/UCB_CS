;Multiply x by y
(define (mult x y)
  (if (= y 0)
    0
    (+ x (mult x (- y 1)))
  )
)


(define (mult_ x y)
  (define (helper x y total)
    (if (= 0 y)
      total 
      (helper x (- y 1) (+ total x)))))

(define (true1 n)
  (if (= n 0)
    #t
    (and #t (true1 (- n 1)))
    )
  )

(define (true2 n)
  (if (= n 0)
    #t
    (or (true2 (- n 1)) #f)
    )
  )

(define (true2_ n)
  (if (= n 0)
    #t
    (true2_ (- n 1))
    )
  )

; Returns true if x is not in lst
(define (constains lst x)
  (cond
    ((null? lst)		#f)
    ((equal? (car lst) x)	#t)
    ((contains (cdr lst) x)	#t)
    (else			#f)
    )
  )

(define (contains lst x)
  (cond 
    ((null? lst) 		#f)
    ((equal? (car lst) x)	#t)
    (else	(contains (cdr lst) x))
    )
  )

(define (sum-satisfied-k lst f k)
  (define (sum-helper lst k total)
    (cond 
      ((= k 0)		total)
      ((null? lst)	0)
      ((f (car lst))	(sum-helper (cdr lst) (- k 1) (+ total (car lst))))
      (else		(sum-helper (cdr lst) k total))
      )
    )
  (sum-helper lst k 0)
  )

(define (sum-satisfied-k_ lst f k)
  (define (sum-helper lst k total)
    (cond
      ((= 0 k)		total)
      ((null? lst)	0)
      ((f (car lst))	(sum-helper (cdr lst) (- k 1) (+ total (car lst))))
      (else		(sum-helper (cdr lst) k total))
      )
    )
  (sum-helper lst k 0)
  )

; wrong answer: index from i to j, not value
(define (remove-range lst i j)
  (cond
    ((null? lst)	())
    ((or (> i (car lst)) (< j (car lst))) (cons (car lst) (remove-range (cdr lst) i j)))
    (else (remove-range (cdr lst) i j))
    )
  )

(define (remove-range_ lst i j)
  (define (remove-tail lst index so-far)
    (cond 
      ((> index j)	(append so-far lst))
      ((>= index i)	(remove-tail (cdr lst) (+ index 1) so-far))
      (else		(remove-tail (cdr lst) (+ index 1) (append so-far (list (car lst)))))
      )
    (remove-tail lst 0 nil)
    )
  )

(define-macro (evaller y) (list (list 'lambda '(x) '(* 2 x)) y))
