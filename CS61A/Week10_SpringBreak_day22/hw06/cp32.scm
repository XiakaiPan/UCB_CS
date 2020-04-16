(define (length items)
  (if (null? items)
      0
      (+ 1 (length (cdr items)))))

(define (getitem items n)
  (if (= n 0)
      (car items)
      (getitem (cdr items) (- n 1))))

(define squares (list 1 4 9 16 25))

(length squares)

(getitem squares 3)

(define a 1)

(define b 2)

(list a b)

(list 'a 'b)

(list 'a b)

(define (repeat k fn)
  (if (> k 0)
      (begin (fn) (repeat (- k 1) fn))
      nil))

(define (tri fn)
  (repeat 3 (lambda () (fn) (lt 120))))

(define (sier d k)
  (tri (lambda ()
         (if (= k 1)
             (fd d)
             (leg d k)))))

(define (leg d k)
  (sier (/ d 2) (- k 1))
  (penup)
  (fd d)
  (pendown))
