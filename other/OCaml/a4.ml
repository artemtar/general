(*** CSI 3120 Assignment 4 ***)
(*** YOUR NAME HERE ***)
(*** YOUR STUDENT ID HERE ***)
(*** OCAML VERSION USED FOR THIS ASSIGNMENT HERE ***)
(* If you use the version available from the lab machines via VCL, the
   version is 4.05.0 ***)

(**********************)
(* PROBLEMS 1a and 1b *)
(**********************)

(* See the PDF file for instructions *)

type prop = string

type form =
  | True
  | False
  | Prop of prop 
  | And of form * form
  | Or of form * form
  | Imp of form * form
  | Neg of form

let rec pretty_print_form (f:form) : string = 
    match f with
      | True -> "T"
      | False -> "F"
      | Prop p -> p
      | And(a, b) -> "(" ^ pretty_print_form(a) ^ " ^ " ^ pretty_print_form(b) ^ ")"
      | Or(a,b) -> "(" ^ pretty_print_form(a) ^ " v " ^ pretty_print_form(b) ^ ")"
      | Imp(a,b) -> "(" ^ pretty_print_form(a) ^ " => " ^ pretty_print_form(b) ^ ")"
      | Neg(a) -> "(" ^ "~" ^ pretty_print_form(a) ^ ")"
      

let form1 = Imp (And (Prop "p",Prop "q"),Or (Prop "r",Prop "s"))
let form2 = And (Or (Prop "p", Prop "q"), Prop "r")
let form3 = Or (Or( Or( Or (Prop "p1",Neg (Prop "p2")), 
    Imp( And(Prop "p3", Prop "p4"), Prop "r")), 
    Imp(Prop "p5", Prop "q")), Or(Prop "p6", Prop "p"))

(* TODO: Problem 1b: Complete the above definition of form3 and
                     uncomment the 3 lines of test code below.*)


let s1: string = "((p ^ q) => (r v s))";;
let s2: string = "((p v q) ^ r)";;
let s3: string = "((((p1 v (~p2)) v ((p3 ^ p4) => r)) v (p5 => q)) v (p6 v p))";;

assert(s1 = (pretty_print_form form1));;
assert(s2 = (pretty_print_form form2));;
assert(s3 = (pretty_print_form form3));;
