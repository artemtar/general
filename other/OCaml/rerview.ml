(* Sample Solutions to Selected Questions *)
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
(* 
val a : int = 17
val b : int * int = (17, 4)
val c : int * int = (42, 6)
val a' : int = 17
val b' : int * int = (42, 4)
 *)

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
(* val l1 : int list = [0; 1; 2; 6; 7; 8] *)

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
(* val fun3 : 'a -> int -> 'a list = <fun> *)

let a3 = fun3 true 4
let b3 = fun3 add 2
let c3 = fun3 (add 3) 2
let d3 = fun3 (fun3 false 3) 2

(* Question 3c. What are the types and values of a3, b3, c3, and d3? *)
(*
val a3 : bool list = [true; true; true; true]
val b3 : (int -> int -> int) list = [<fun>; <fun>]
val c3 : (int -> int) list = [<fun>; <fun>]
val d3 : bool list list = [[false; false; false]; [false; false; false]]
 *)
                   
let e3 = (1,false)
let f3 = [(1,false);(2,true)]
let g3 = ([1;2],[false;true])
let h3 = fun3 4.3
let i3 = fun x -> x < 5
let j3 = [add;mult]

(* Question 3d.  What are the types of e3, f3, g3, h3, i3, and j3? *)
(*
val e3 : int * bool = (1, false)
val f3 : (int * bool) list = [(1, false); (2, true)]
val g3 : int list * bool list = ([1; 2], [false; true])
val h3 : int -> float list = <fun>
val i3 : int -> bool = <fun>
val j3 : (int -> int -> int) list = [<fun>; <fun>]
 *)

(* Question 4. Lambda Calculus
Note: "lambda" is denoted "|"
Use lambda calculus reduction to fine a shorter expression for

(|x.|y.xy)(|x.xy)

Solution:
(|x.|y.xy)(|x.xy)
(|w.|z.wz)(|x.xy) =
[(|x.xy)/w](|z.wz) =
|z.((|x.xy)z) =
|z.([z/x](xy)) =
|z.(zy)
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

Solutions:
5a.   e        1 - (1 * 1)
     /|\
    e - e
   |    /|\
   n   e * e
   |   |   |
   1   n   n   
       |   |
       1   1   

5b.   e        (1 - 1) + 1
     /|\
    e + e
  /|\    |
 e - e   n
 |   |   |
 n   n   1
 |   |
 1   1   

5c. 1 - 1 + 1 - 1 + 1 (Here give higher precedence to + than to -)

                             e
                           / | \
                          /  |  \
                         e   -   e
                       /|\      /|\
                      e - e    e + e
                     |   /|\   |   |
                     n  e + e  n   n
                     |  |   |  |   |
                     1  n   n  1   1
                        |   |
                        1   1
 *)

(* Question 6: Anonymous Functions
What is the value of x6 ? *)
       
let rec guess (f:int -> int -> int) (l:int list) : int option =
  match l with
  | [] -> None
  | [a] -> Some a
  | a::b::l' -> guess f ((f a b)::l')

let x6 = guess (fun x -> fun y -> (x * x) + y) [2;3;5]
(* val x6 : int option = Some 54 *)

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
(* val q7a : int list = [5; 7; 3] *)

(* Question 7b. What is the type of q7_fun? *)
(* val q7_fun : ('a, 'b) newtype -> 'a list = <fun> *)

(* Question 7c. What does q7_fun do? *)

(* Question 7d. Write a function that takes an input of type
   "(int,float) newtype" and returns a pair of type "int * float"
   where the first element is the sum of all of the integer elements
   appearing in the input data structure and the second element is the
   sum of all of the float elements appearing in the input data
   structure. *)

let rec q7d_fun (xs:(int,float) newtype) : int * float =
  match xs with
  | New_const1 -> (0,0.0)
  | New_const2 (xs',xa,xb) ->
     let (result_a,result_b) = q7d_fun xs' in
     (xa + result_a, xb +. result_b)
       
(* Question 7e. Write an expression of type
   "(int,float) newtype" with 3 integers and 3 floats
   that can be used as input to the function from
   Question 7d. *)
let q7e = q7d_fun (New_const2 (New_const2 (New_const2 (New_const1,3,3.1),7,5.2),5,8.5))

(* Question 8 Imperative Abstract Data Types *)

module type IMP_QUEUE =
  sig
    type 'a queue

    val create : unit -> 'a queue
    val enqueue : 'a -> 'a queue -> unit
    val dequeue : 'a queue -> 'a option
  end

module ImpListQueue : IMP_QUEUE =
  struct
    type 'a queue = 'a list ref

    let create () : 'a queue = ref []

    let enqueue (elt: 'a) (q: 'a queue) : unit =
      let rec insert_at_end l =
        match l with
        | [] -> [elt]
        | hd::tl -> hd::insert_at_end tl in
      q := insert_at_end !q

    let dequeue (q: 'a queue) : 'a option =
      match !q with
      | [] -> None
      | hd::tl -> q := tl; Some hd
  end

let q = ImpListQueue.create()
let _ = ImpListQueue.enqueue 3 q
let _ = ImpListQueue.enqueue 4 q
let _ = ImpListQueue.enqueue 5 q
let _ = ImpListQueue.dequeue q (* Some 3 *)
let _ = ImpListQueue.dequeue q (* Some 4 *)
let _ = ImpListQueue.dequeue q (* Some 5 *)
