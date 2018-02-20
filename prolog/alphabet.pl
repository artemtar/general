:- dynamic letter/2.
alphabet([a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z]).

letter(A, Id):-
    alphabet(C),
    letter(A, C, Id),
    assert(letter(A, Id)).

letter(A, [A|_], 1), !, false.
letter(A, [C|B], Id):-
    \+ (A=B),
    letter(A, B, I),
    Id is I + 1.

maketable :- L = [0, 1, 2, 3, 4, 5, 6, 7 ,8, 9],
    member(X, L),
    member(Y, L),
    Z is X * Y,
    assert(product(X, Y, Z)),
    fail.