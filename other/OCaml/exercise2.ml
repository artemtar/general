(* 

  Agenda:
   * tuples and lists
   * options
   * higher order functions

*)

(* An employee is a tuple of name, age, and boolean indicating marriage status *)
type employee = string * int * bool;;
                                 
(* 1. Write a function that takes an employee, and prints out the information in some readable form. *)

(*
let print_employee_info t = 
*) 

(* 2. Reimplement the OCaml standard functions List.length and List.rev *)

(* 
let rec length (l:'a list) : int = 
  match l with
    | [] -> 0
    | _::t -> 1 + length t;;

print_int (length [1;2;3]);;
print_string "iam running";;

let next (l: 'a list) : 'a = 
  match l with
    | [] -> []
    | h :: t -> h

let rev (l:'a list) : 'a list = 
  {
  let rec aux acc ls =
    match ls with
      | [] -> acc
      | h::t -> aux (h::acc) t;
  aux [] l;
  } *)



(* 3. Remove the kth element from a list. Assume indexing from 0 *)
(* example: rmk 2 ["to" ; "be" ; "or" ; "not" ; "to" ; "be"] 
 * results in: [["to" ; "be" ; "not" ; "to" ; "be"] *)
let rmk (k:int) (l:'a list) : 'a list = 
  let rec rem count ls = 
    match ls with
      | [] -> []
      | h :: t ->
        if count < k then h :: (rem (count + 1) t)
        else t
    in rem 0 l;;



(* 4. Write a function to return the smaller of two int options, or None
 * if both are None. If exactly one argument is None, return the other. Do 
 * the same for the larger of two int options.*)


let min_option (x: int option) (y: int option) : int option = 
  match x, y with
  |None, None -> None
  |Some a, None -> x
  |None, Some b -> y
  |Some a, Some b ->
    if a > b then x
    else y;;


(*
let max_option (x: int option) (y: int option) : int option = om
*)

(* 5. Write a function that returns the integer buried in the argument
 * or None otherwise *)  
(* 
let get_option (x: int option option option option) : int option = 
*)

(* 6. Write a function to return the boolean AND/OR of two bool options,
 * or None if both are None. If exactly one is None, return the other. *)


let and_option (x:bool option) (y: bool option) : bool option = 
  match x, y with
    | None, None -> None
    | None, a | a, None -> a
    | Some a, Some b -> Some (a && b);;


(*
let or_option (x:bool option) (y: bool option) : bool option = 
*)

(* What's the pattern? How can we factor out similar code? *)

(* 7. Write a higher-order function for binary operations on options.
 * If both arguments are present, then apply the operation.
 * If both arguments are None, return None.  If one argument is (Some x)
 * and the other argument is None, function should return (Some x) *)
(* What is calc_option's function signature? *)


let calc_option (f: 'a->'a->'a) (x: 'a option) (y: 'a option) : 'a option = 
  match x, y with
    | None, None -> None
    | None, a | a, None -> a
    | Some a, Some b -> Some (f a b)


(* 8. Now rewrite the following functions using the above higher-order function
 * Write a function to return the smaller of two int options, or None
 * if both are None. If exactly one argument is None, return the other. *)

let minim (x: 'a) (y: 'a) : 'a = 
  if x > y then y
  else x;;

let min_option2 (x: int option) (y: int option) : int option = 
  calc_option minim x y;;

(*
let max_option2 (x: int option) (y: int option) : int option = 
*)

(* 9. Write a function that returns the final element of a list, 
   if it exists, and None otherwise *)

let rec final (l: 'a list) : 'a option = 
  match l with
  | [] -> None
  | h :: [] -> Some h
  | h :: t -> final t;;
