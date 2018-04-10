#lang racket
;ran code with rollowing command
;(saveRoute(findRoute "input.txt")"solution.txt")

(define pi 3.14159265359)

(define (angle x)
  (/ ( * x pi) 180))

(define (add-last ls child)
  (if (null? (cdr ls))
      (cons (car ls) (cons child null))
      (cons (car ls)(add-last (cdr ls) child))))

(define (distance n1 n2)         
  (let* ([a (sin (/ (- (angle (cadr n1)) (angle (cadr n2))) 2))]
        [c (sin (/ (- (angle (caddr n1)) (angle (caddr n2))) 2))]
        [b (* (cos (angle (cadr n1))) (cos (angle (cadr n2))))])
   (let([A (* a a)]
        [B (* b (* c c))]        
        ) (* (* 2 ( asin (sqrt (+ A B)))) 6371)
     )))

(define (build-list-from-file some-file)
  (let ((p (open-input-file some-file)))
    (let f ((x (read p)))
      (if (eof-object? x)
          (begin
            (close-input-port p)
            '())
          (cons x (f (read p)))))))

(define (make-node x)
  (list x null))

(define (add-child node child)
  (if (null? (cadr node))
      (list (car node) (list child))
      (list (car node) (add-last (cadr node) child))))

(define (find-closest graph node closest)
  (if (null? graph)
      closest
  (if (< (distance (caar graph) node) (distance closest node))
       (find-closest (cdr graph) node (caar graph))
       (find-closest (cdr graph) node closest))))

(define (get-parent graph node)
  (if (equal? (caar graph) node)
      (car graph)
      (get-parent (cdr graph) node)))

(define (insert-into-graph graph parent toAdd)
  (if (equal? (caar graph) parent)
      (cons toAdd (cdr graph))
      (cons (car graph) (insert-into-graph (cdr graph) parent toAdd))))

(define (add-to-graph graph parent child)
    (let ((toAdd (add-child (get-parent graph parent) child)))
     (insert-into-graph graph parent toAdd)))

(define (graph start rest)
  (if (null? rest)
      start
  (let((parent (find-closest start (car rest) (caar start))))
    (let ((newGraph (add-to-graph start parent (car rest))))
      (graph (add-last newGraph (make-node (car rest)))(cdr rest))))))

(define (build-gragh root rest)  
  (let ((next (sort rest (lambda (a b)
               (< (distance a root) (distance b root))))))
    (let ((start (let((groot root) (gnext (car next)))         
                 ;;graph
                   (cons (add-child (make-node groot) gnext) (list (make-node gnext))))))
      (graph start (sort (cdr next) (lambda (a b)
                  (< (caddr a) (caddr b))))))))

(define (find-node graph name)    
  (if (equal? (caar graph) name)
      (car graph)
      (find-node (cdr graph) name)))

(define (trace-horizontaly graph children)
   (if (null? children)
      null
      (cons (trace graph (car children))
             (trace-horizontaly graph (cdr children)))))

(define (trace graph name)
  (if (null? name)
     null  
  (let ((node (find-node graph name)))
    (cons name (trace-horizontaly graph (cadr node))))))

(define (flatten x)
  (cond ((null? x) '())
        ((pair? x) (append (flatten (car x)) (flatten (cdr x))))
        (else (list x))))

(define (build-output-list output ls dist)
  (if (equal? 3 (length ls))
      output
      (let ((n1 ls) (n2 (cdddr ls)))
        (let ((d2nodes (distance (list (car n1)(cadr n1)(caddr n1))(list (car n2)(cadr n2)(caddr n2)))))
                    (let ((newoutput (append output (list (list (car n2)(+ dist d2nodes)"\r\n")))))
                               (build-output-list newoutput n2 (+ dist d2nodes)))))))
        

(define (make-output-list ls)
  (let ((first (list (list (car ls) 0 "\r\n"))))
    (build-output-list first ls 0)))
    

(define (findRoute file)
  (let ((input (build-list-from-file file)))
    (let ((sorted (sort input (lambda (a b)
                  (< (caddr a) (caddr b))))))
      (let ((root (car sorted)))
      (let ((graph (build-gragh root (cdr sorted))))
        (let ((ready-for-output (make-output-list(flatten (trace graph root)))))
          ready-for-output))))))

(define (saveRoute solution file)
  (begin
    (call-with-output-file file
  (lambda (output-port)
    (display (flatten solution) output-port))))#t)


    

;(saveRoute(findRoute "input.txt")"solution.txt")
