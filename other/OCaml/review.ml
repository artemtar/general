(* Review Question 1: References *)

type point = int ref * int ref

let f (p1:point) (p2:point) : int =
  match (p1,p2) with
  | (x1,y1),(x2,y2) ->
              (x1 := 17;
               let z = !x1 in
               x2 := 42;
               z)

let point1 = (ref 3, ref 4)
let point2 = (ref 8, ref 6)
let a = f point1 point2
let b = match point1 with
    (x,y) -> (!x,!y)
let c = match point2 with
    (x,y) -> (!x,!y)

let a' = f point1 point1
let b' = match point1 with
    (x,y) -> (!x,!y)

(* What are the values of a, b, c, a', and b'? *)

(* Review Question 2: Inductive Data Types *)

type tree = 
  | Empty
  | Node of tree * int * tree

(* helper function for constructing trees *)
let leaf (i:int) : tree =
  Node(Empty, i, Empty)

let t1 = 
  Node(Node(leaf 2, 1, Empty),
       0,
       Node(leaf 7, 6, leaf 8))

(* Question 2a. Draw the tree represented by t1. *)
(* Question 2b. What does the following function do? *)

let fun_2b (t:tree) : bool =
  begin match t with
  | Node(Empty,_,Empty) -> true
  | _ -> false
  end

(* Question 2c. What is the value of l1 below?
   What does the function fun_2c do? *)

let rec fun_2c (t:tree) : int list =
  begin match t with
  | Empty -> []
  | Node(l,n,r) -> n::(fun_2c l)@(fun_2c r)
  end

let l1 = fun_2c t1

(* Question 3. Polymorphic Higher-Order Programming *)

let add (x:int) (y:int) : int = x + y
let mult (x:int) (y:int) : int = x * y
           
let rec fun3 x n =
  match n with
  | 0 -> []
  | n -> if n < 0 then []
         else x::(fun3 x (n-1))

(* Question 3a. What does the fun3 function do? *)
(* Question 3b. What is the type of fun3? *)

let a3 = fun3 true 4
let b3 = fun3 add 2
let c3 = fun3 (add 3) 2
let d3 = fun3 (fun3 false 3) 2
                   
(* Question 3c. What are the types and values of a3, b3, c3, and d3? *)

let e3 = (1,false)
let f3 = [(1,false);(2,true)]
let g3 = ([1;2],[false;true])
let h3 = fun3 4.3
let i3 = fun x -> x < 5
let j3 = [add;mult]

(* Question 3d.  What are the types of e3, f3, g3, h3, i3, j3? *)

(* Question 4. Lambda Calculus
Note: "lambda" is denoted "|"
Use lambda calculus reduction to fine a shorter expression for

(|x.|y.xy)(|x.xy)

 *)

(* Question 5. Parsing and Precedence

Draw parse trees for the following epressions, assuming the grammar
and precedence described in class:

Multipication ("*") has a higher precedence than addition ("+") or
subtraction ("-").  All 3 operators associate to the left.

Use the following grammar for expressions:
e ::= n | e+e | e-e | e*e
n ::= 1

5a. 1 - 1 * 1
5b. 1 - 1 + 1
5c. 1 - 1 + 1 - 1 + 1 (Here give higher precedence to + than to -)

 *)

(* Question 6: Anonymous Functions
What is the value of x6 ? *)
       
let rec guess (f:int -> int -> int) (l:int list) : int option =
  match l with
  | [] -> None
  | [a] -> Some a
  | a::b::l' -> guess f ((f a b)::l')

let x6 = guess (fun x -> fun y -> (x * x) + y) [2;3;5]

(* Question 7: More Inductive Data Types *)
;
type ('a,'b) newtype =
    New_const1
  | New_const2 of (('a,'b) newtype * 'a * 'b)

let rec q7_fun (xs:('a,'b) newtype) =
  match xs with
  | New_const1 -> []
  | New_const2 (xs',xa,xb) -> (xa::q7_fun xs')

let q7a = q7_fun (New_const2 (New_const2 (New_const2 (New_const1,3,true),7,false),5,false))

(* Question 7a. What is the value of q7a? *)
(* Question 7b. What is the type of q7_fun? *)
(* Question 7c. What does q7_fun do? *)
(* Question 7d. Write a function that takes an input of type
   "(int,float) newtype" and returns a pair of type "int * float"
   where the first element is the sum of all of the integer elements
   appearing in the input data structure and the second element is the
   sum of all of the float elements appearing in the input data
   structure.
 *)
(* Question 7e. Write an expression of type
   "(int,float) newtype" with 3 integers and 3 floats
   that can be used as input to the function from
   Question 7d. *)

(* Question 8 Imperative Abstract Data Types *)

module type IMP_QUEUE =
  sig
    type 'a queue

    val create : unit -> 'a queue
    val enqueue : 'a -> 'a queue -> unit
    val dequeue : 'a queue -> 'a option
  end

    (* Complete the implementation of the module below.  A queue is
       represented as a pointer to a list.  The create operation
       creates a new empty queue.  The enqueue operation adds a new
       element to the end of the list.  The dequeue operation removes
       an element from the front of the list if there is one, and returns
       it as the output of the function. *)

(* module ImpListQueue : IMP_QUEUE =
  struct
    type 'a queue = 'a list ref

  end

let q = ImpListQueue.create()
let _ = ImpListQueue.enqueue 3 q
let _ = ImpListQueue.enqueue 4 q
let _ = ImpListQueue.enqueue 5 q
let _ = ImpListQueue.dequeue q (* Some 3 *)
let _ = ImpListQueue.dequeue q (* Some 4 *)
let _ = ImpListQueue.dequeue q (* Some 5 *)
 *)
