let rec mult (l : (int * int) list) : int list =
  begin
    match l with
      | [] -> []
      | (x, y) :: t -> (x * y) :: mult t
  end;;

let rec print_list (l: int list) : unit = 
  begin 
    match l with
    | [] -> ()
    | h :: t -> print_int h; print_list t
  end;;

print_list( mult ([(2, 2); (2, 3)]));;

let rec list_size l : int =
  begin 
  match l with
    | [] -> 0
    | h::t -> 1 + list_size t
  end;;

let rec insert(x : int)(ls : int list) : int list =
  
  match ls with
  | [] -> x :: []
  | hd :: tail ->
  if hd < x then
    hd :: insert x tail
  else x :: tail;;
    
insert 3 [2;4;5];;