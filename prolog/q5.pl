%There are two versions of bouquet function:
%bouquetA/1 and bouquetB/1(I am not sure which one is needed)
%bouquetA/1 check the data and produce one list of the first occurrence of
%flowers that are satisfying the requirements. Color is included, so it easier to check.
%bouquetB/1 Do same as bouquetA/1, but returns a full list of bouquet's sets,
%that are available in the dataset.


bouquetA(L):-
    L = [[F1, C1], [F2, C2], [F3, C3]],
    flower(F1, C1),
    flower(F2, C2),
    C1 = red, C2 = red,
    \+ (flower(F1, C1) = flower(F2, C2)),
    flower(F3, C3),    
    \+ (flower(F1, C1) = flower(F3, C3)),
    \+ (flower(F3, C3) = flower(F2, C2)),!.

bouquetA(L):-
	L = [F1, F2, F3],
    flower(F1, _),
    flower(F2, _),
    \+ (F1 = F2),
    flower(F3, _),    
    \+ (F2 = F3),
    \+ (F1 = F3),!.


flowerHelper1(L):-
	L = [F1, F2, F3],
    flower(F1, C1),
    flower(F2, C2),
    C1 = red, C2 = red,
    \+ (flower(F1, C1) = flower(F2, C2)),
    flower(F3, C3),    
    \+ (flower(F1, C1) = flower(F3, C3)),
    \+ (flower(F3, C3) = flower(F2, C2)).

flowerHelper2(L):-
	L = [F1, F2, F3],
    flower(F1, _),
    flower(F2, _),
    \+ (F1 = F2),
    flower(F3, _),    
    \+ (F2 = F3),
    \+ (F1 = F3).

bouquetB(L):-
    setof(X, flowerHelper1(X), L),!.

bouquetB(L):-
    setof(X, flowerHelper2(X), L).