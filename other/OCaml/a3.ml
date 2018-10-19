(*** CSI 3120 Assignment 3 ***)
(*** YOUR NAME HERE ***)
(*** YOUR STUDENT ID HERE ***)
(*** OCAML VERSION USED FOR THIS ASSIGNMENT HERE ***)
(* If you use the version available from the lab machines via VCL, the
   version is 4.05.0 ***)

(*************)
(* PROBLEM 1 *)
(*************)

(* Below is a definition of a datatype for propositional logic with
   connectives for conjunction, (the AND operator written /\),
   disjunction (the OR operator written \/), and logical implication
   (written =>).  For example, the following is a formula of
   propositional logic.

   (p /\ q) => (r \/ s)

   Note that strings are used to represent propositional variables.

   The type env is used to map propositional variables to boolean values.
 *)

type prop = string

type form =
  | True
  | False
  | Prop of prop 
  | And of form * form
  | Or of form * form
  | Imp of form * form

type env = (prop * bool) list

(* Problem 1a: Write a function that takes a "prop list list" as input
   and returns its value as a "form" in conjunctive normal form (CNF).
   A CNF expression is represented as a series of OR expressions
   joined together by AND.

   e.g. transform this:

   [ ["x1"; "x2"]; ["x3"; "x4"; "x5"]; ["x6"] ]

   into an expression of type "form" that represents the formula

   (x1 \/ x2) /\ (x3 \/ x4 \/ x5) /\ x6

   Note that \/ and /\ are associative, so for example
   (x3 \/ x4 \/ x5) represents ((x3 \/ x4) \/ x5) and is equivalent
   to (x3 \/ (x4 \/ x5)), can thus be represented as
   Or (Or (Prop "x3",Prop "x4"),Prop "x5")  or
   Or (Prop "x3",Or (Prop "x4",Prop "x5"))

   If an inner list is empty, it should be replaced by False, e.g.,

   [ ["x1"; "x2"]; []; ["x6"] ] as input results in output:

   (x1 \/ x2) /\ False /\ x6

   If the input list is empty, return True.  

   Optional: you may want to use map (from class) and/or reduce
   (from Tutorial 1), which are included below *)

let rec map (f:'a -> 'b) (xs: 'a list) : 'b list =
  match xs with
  | [] -> []
  | hd::tl -> (f hd) :: (map f tl)

let rec reduce (f:'a -> 'b -> 'b) (u:'b) (xs:'a list) : 'b =
  match xs with
  | [] -> u
  | hd::tl -> f hd (reduce f u tl);;

let rec aux (x:prop list) : form =
    match x with
        [] -> False
        | h :: [] ->Prop h
        | h :: t -> Or(Prop h, (aux t))

let rec cnf (pll:prop list list) : form =
    match pll with 
        [] -> True
        | h :: [] -> aux h
        | h :: t ->
            And ( (aux h), (cnf t) )


let test1a_1 = cnf [ ["p"; "q"]; ["q"; "q"; "q"]; ["p"] ];;
let test1a_2 = cnf [];;
let test1a_3 = cnf [ ["x1"; "x2"]; []; ["x6"] ];;

let rec print_prop x =
    match x with
        | False -> print_string "F"
        | True -> print_string "T"
        | Prop a -> print_string a
        | And (a, b) -> (print_string " and("; print_prop a; print_prop b); print_string ")"
        | Or (a, b) -> (print_string " or("; print_prop a; print_prop b); print_string ")"
        | Imp (a, b) -> (print_string " Imp("; print_prop a; print_prop b); print_string ")" ;;

print_string "Test 1a---------";;   
print_string "\n";;
        
print_prop test1a_1;;
print_string "\n";;
print_prop test1a_2;;
print_string "\n";;
print_prop test1a_3;;
print_string "\n";;
print_prop (cnf [[]; []]);;
print_string "\n";;
print_prop (cnf [[]; ["42"; "meaning"]; []]);;
print_string "\n";;print_string "\n";;print_string "\n";;print_string "\n";;

(* Problem 1b: Define a new datatype called form' that replaces form,
   but is just like form except that it also represents negation (the
   NOT operator written ~).  Your code for both 1b and 1c operate only
   on the new type form' (which does not depend at all on the type
   form from a1).
   This should be easy. *)

type form' =
  | True
  | False
  | Prop of prop 
  | And of form' * form'
  | Or of form' * form'
  | Imp of form' * form'
  | Not of form'


(* Problem 1c: Define a function that takes a form' and an env as
   arguments and computes the truth value. For example, if

   e = [("p",true);("q",false);("r",true);("s",false)]

   then your function should return true for the formula mentioned above:
   (p /\ q) => (r \/ s)
   
   See the truth tables at https://en.wikipedia.org/wiki/Truth_table
   for information on how to compute truth values of propositional
   formulas.

   You may use the lookup function below.  Your function should return
   a bool. Assume that any of the variables in the input form' that do
   not appear in the input env have the value false.
 *)

(* return the value of proposition p in environment e *)

let rec lookup (e:env) (p:prop) : bool option =
  match e with
  | [] -> None
  | (hd_p,hd_b)::tl_e -> 
      if p=hd_p then Some hd_b
      else lookup tl_e p
let lookup2 (x: bool option): bool =
    match x with
        | None -> false
        | Some a -> a


let rec eval_prop (f:form') (e:env) : bool =
    match f with
        | True -> true
        | False -> false
        | Prop a -> lookup2 (lookup e a)
        | And (a, b) -> (eval_prop a e) && (eval_prop b e)
        | Or (a, b) -> (eval_prop a e) || (eval_prop b e)
        | Imp (a, b) -> (not (eval_prop a e)) || (eval_prop b e)
        | Not a ->
            match a with
                | True -> false
                | False -> true
                | Not b -> not (eval_prop b e)
                | Prop a -> not (lookup2 (lookup e a))
                | And (a, b) -> (not (eval_prop a e)) || (not (eval_prop b e))
                | Or (a, b) -> (not (eval_prop a e)) && (not (eval_prop b e))
                | Imp (a, b) -> (eval_prop a e) && (not (eval_prop b e))
    


let e = [("p",true);("q",false);("r",true);("s",false)]
let test1b (f:form') : unit = 
    let b = (eval_prop f e) in
        (match b with
            true -> (print_string "true")
            | false -> (print_string "false"));;
            
print_string "Test 1b---------";;   
print_string "\n";;

test1b  (Prop "zzz");;
print_string "\n";;
test1b (Or ((Prop "zzz"), (Prop "p")));;
print_string "\n";;
test1b True;;
print_string "\n";;
test1b  (Prop "q");;
print_string "\n";;
test1b (Not(Prop "q"));;
print_string "\n";;
test1b  (Imp ((Prop "q"), Not(Prop "q")));;
print_string "\n";;
test1b  (Imp (Not(Prop "q"), (Prop "q")));;
print_string "\n";;
test1b  (Not (Imp (Not(Prop "q"), (Prop "q"))));;
print_string "\n";;
test1b  (And (Not (Imp (Not(Prop "q"), (Prop "q"))), (Prop "s")));;
print_string "\n";;
test1b  (Or ((And (Not (Imp (Not(Prop "q"), (Prop "q"))), (Prop "s"))), (Prop "r")));;
print_string "\n";;
(*   (p /\ q) => (r \/ s)*)
test1b  (Imp(And ((Prop "p"), (Prop "q")), Or ((Prop "r"), (Prop "s"))));;
print_string "\n";;

    
(*
let eval_prop (f:form') (e:env) : bool =

The following may be useful for testing:
let e = [("p",true);("q",false);("r",true);("s",false)]
let test1b (f:form') : bool = eval_prop f e
 *)

(*************)
(* PROBLEM 2 *)
(*************)

(* Below is an implementation of a module that implements a dictionary
   data structure (also called associative array), see
   https://en.wikipedia.org/wiki/Associative_array.  In this
   implementation, keys are strings and dictionaries are lists.  (Note
   that there are many more efficient ways to implement this data
   structure, which we ignore here.) *)


module type DICT =
  sig
    type ('key,'value) dict
    val empty : unit -> ('key,'value) dict
    val lookup : ('key,'value) dict -> 'key -> 'value option
    val member : ('key,'value) dict -> 'key -> bool
    val insert : ('key,'value) dict -> 'key -> 'value -> ('key,'value) dict
    val remove : ('key,'value) dict -> 'key -> ('key,'value) dict
  end


(* TODO: Uncomment the module type in the line immediately following
   this comment after completing Problem 2c *) 
module ListDict: DICT  =
  struct
    type ('key,'value) dict = ('key * 'value) list

    (* Module invariant: the operations are implemented so that there
       is never more than one occurrence of a given key, and the list
       is always in sorted order. *)
              
    let empty (): ('key,'value) dict = []

    let rec lookup (d:('key,'value) dict) (k:'key): 'value option =
      match d with
      | [] -> None
      | (hd_k,hd_v)::tl -> if hd_k=k then Some hd_v
                           else lookup tl k

    let rec member (d:('key,'value) dict) (k:'key): bool =
      match d with
      | [] -> false
      | (hd_k,hd_v)::tl -> hd_k=k || member tl k

    let rec insert (d:('key,'value) dict) (k:'key) (v:'value): ('key,'value) dict =
      match d with
      | [] -> [(k,v)]
      | (hd_k,hd_v)::tl -> if (k < hd_k || k = hd_k)
                           then (k,v)::(hd_k,hd_v)::tl
                           else (hd_k,hd_v)::insert tl k v

    let rec remove (d:('key,'value) dict) (k:'key) = 
        match d with
            | [] -> []
            | (hd_k,hd_v)::tl -> if (k = hd_k)
                                    then remove tl k
                                    else
                                        if (k < hd_k)
                                        then (hd_k,hd_v)::remove tl k
                                            else d
  end

(* Problem 2a: Replace the implementation of "remove" with a correct
   one, i.e., one that removes an element from the dictionary if it is
   present in the dictionary, otherwise leaves the dictionary
   unchanged.  Note that because of the way that insert is
   implemented, there may be more than one value associated with a
   given key k, but because the dictionary is sorted, these pairs will
   appear next to each other in the list.  In other words, there could
   be a segment of the form 
   ...::(k,v1)::(k,v2)::...::(k,vn)::...
   in the dictionary where all keys to the left have lower value and
   all keys to the right have greater value.  Be sure to remove
   all pairs having key k. *)

(* Problem 2b: Note that when you load this file into OCaml, the types
   that are inferred include 'a and 'b.  This type is more general
   than we intend it to be.  Add types to all of the function
   headers in the ListDict module so that all occurrences of
   'a and 'b disappear.  Use instead the types 'key, 'value, and
   ('key,'value) dict.
 *)

(* Problem 2c: Complete the DICT signature above.  Include
   signature items for all of the functions that occur in
   ListDict.  Add comments describing what each operation is.
   Once you are done, remove the comment from the
   first line of the ListDict module definition.
 *)

(* Problem 2d: Reimplement your solution to Problem 1c using the
   following new definition of the lookup function.  Develop code for
   testing similar to what you did for Problem 1c.  env0 and env1
   below provide some initial code that you can build on.
   Note: This is a simple exercise, showing how easy it is to swap
   one implementation with another. *)
   
type prop = string

type form' =
  | True
  | False
  | Prop of prop 
  | And of form' * form'
  | Or of form' * form'
  | Imp of form' * form'
  | Not of form'

type env = (prop * bool) list

(* return the value of proposition p in environment e *)
type env' = (string,bool) ListDict.dict
let lookup' (e:env') (p:prop) : bool option =
  ListDict.lookup e p
 
let lookup2' (x: bool option): bool =
    match x with
        | None -> false
        | Some a -> a

let env0 = ListDict.empty()
let env1 = ListDict.insert env0 "p" true

let rec eval_prop (f:form') (e:env') : bool =
    match f with
        | True -> true
        | False -> false
        | Prop a -> lookup2' (lookup' e a)
        | And (a, b) -> (eval_prop a e) && (eval_prop b e)
        | Or (a, b) -> (eval_prop a e) || (eval_prop b e)
        | Imp (a, b) -> (not (eval_prop a e)) || (eval_prop b e)
        | Not a -> not (eval_prop a e) 



(* Problem 2e: Note that the above dictionary is a functional version.
   Design an imperative version of the DICT signature, but include
   only the empty, lookup, and insert operations.  (Omit member and
   remove.)  In this version, the empty operation creates and returns
   a mutable dictionary.  The insert operation takes a dictionary as
   input, but instead of returning a new dictionary, it modifies the
   input dictionary.  Note: there will only be very minor
   modifications, similar to the modifications made to STACK to get
   IMP_STACK in the course notes. *)

module type IMP_DICT =
  sig
    type ('key,'value) dict
    val empty : unit -> ('key,'value) dict
    val lookup : ('key,'value) dict -> 'key -> 'value option
    val insert : ('key,'value) dict -> 'key -> 'value -> unit
  end

(* Problem 2f: Implement a module with type IMP_DICT.  Hint: do so by
   making a copy of the contents of the ListDict module, removing the
   functions member and remove, and modifying the rest as needed.  *)


module ImpListDict : IMP_DICT =
  struct
    type ('key,'value) dict = ('key * 'value) list
    let empty (): ('key,'value) dict = []

    let rec lookup (d:('key,'value) dict) (k:'key): 'value option =
      match d with
      | [] -> None
      | (hd_k,hd_v)::tl -> if hd_k=k then Some hd_v
                           else lookup tl k

    let rec insert (d:('key,'value) dict) (k:'key) (v:'value): unit =
      match d with
      | [] -> d = [(k,v)]
      | (hd_k,hd_v)::tl -> if (k < hd_k || k = hd_k)
                           then d = (k,v)::(hd_k,hd_v)::tl
                           else d = (hd_k,hd_v)::insert tl k v
  end

type env'' = (string,bool) ImpListDict.dict
let lookup'' (e:env'') (p:prop) : bool option =
  ImpListDict.lookup e p

let e'' = ImpListDict.empty()
let _ = ImpListDict.insert e'' "p" true

  
