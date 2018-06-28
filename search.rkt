#lang racket

(define (print-row row)
  ; Print to standard output the specified row of integers, each separated by
  ; a space, right aligned to two characters, and all ending with a newline.
  (displayln
    (string-join 
      (map (lambda (n) (~a n #:width 2 #:align 'right))
           row)
      " ")))
           
(define N 12)
      
(define (print-interval-tone-rows)
  ; Print to standard output all of the interval tone rows that can be composed
  ; from N distinct tones.
  ; A tone interval row is a permutation of the integers [0, N) where the
  ; absolute value of the difference between two adjecent members of the 
  ; permutation is distinct, i.e. all of the intervals are different.
  (let loop ([notes '()] [intervals '()])
    (match (length notes)
      ; If we already have N notes, then we found one.
      [(== N)
       (print-row notes)]
      ; If we have no notes, then try each possible first note.
      [0
       (for ([n (range N)])
         (loop (list n) intervals))]
      ; Otherwise, try each note as the next one.
      [_
       (for ([n (range N)])
         (unless (member n notes)
           (let ([interval (abs (- n (first notes)))])
             (unless (member interval intervals)
               (loop (cons n notes) (cons interval intervals))))))])))

(print-interval-tone-rows)