littleHelper([], []).
littleHelper([H|T], [H|L]):-
    littleHelper(T, L).
absDiffA([],[],[]):- !.
absDiffA(A,[],L):- 
    littleHelper(A, L),!.
absDiffA([],B,L):- 
    littleHelper(B, L),!.
absDiffA([A|B], [C|D], [N|L]):-
    N is abs(A - C),
    absDiffA(B, D, L).


absDiffB([],[],[]):- !.
absDiffB(_,[],[]):- !.
absDiffB([],_,[]):- !.
absDiffB([A|B], [C|D], [N|L]):-
    N is abs(A - C),
    absDiffB(B, D, L).