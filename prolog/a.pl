
child(martha,charlotte). 
child(charlotte,caroline). 
child(caroline,laura). 
child(laura,rose). 
age(harry,13). 
age(draco,14). 
age(ron,13). 
age(hermione,13). 
age(dumbledore,60). 
age(hagrid,30).

descend(X,Y)  :-  child(X,Y).     
descend(X,Y)  :-  child(X,Z), 
    descend(Z,Y).


                                

a(X):-
    person(X, C),employee(X, E),company(E, CC),\+ (C = CC).

b(X):-
    company(X, Y),city(Y, ontario).

c(X):-
    person(X, _),not(employee(X, _)).

d(X):-
    person(X, _),employee(X, E),company(E, C),C = ottawa.



angle(X, Y):-
        Y is 3.14159265359 * X / 180.



distance(Lat1, Lat2, Lon1, Lon2, D):-
    XX is (Lat1 - Lat2) / 2,
    angle(XX, X),
    A is sin(X),
    angle((Lon1 - Lon2) / 2, Y),
    B is sin(Y),
    AA is A*A,
    BB is B*B,
    C is cos(Lat1) * cos(Lat2),
    N is AA + BB * C,
    NN is sqrt(N),
    D is 2 * asin(NN) * 6371.


    
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
    

flower(rose,red).
flower(marigold,yellow).
flower(tulip,red).
flower(daffodil,yellow).
flower(rose,yellow).
flower(maigold,red).
flower(rose,white).
flower(cornflower,purple). 

busy(X):- employee(X, C1), employee(X, C2), compare(<, C1, C2).
busy(X):- employee(X, C), company(C, toronto). 

city(ottawa,ontario).
city(toronto,ontario).
city(kingston,ontario).
city(gatineau,quebec).
city(montreal,quebec).
company(shopify,ottawa).
company(rossvideo,ottawa).
company(dium,gatineau).
company(uber,toronto).
company(deepmind,montreal).
company(google,toronto).
person(annie,gatineau).
person(paul,gatineau).
person(suzy,gatineau).
person(robert,gatineau).
person(tom,ottawa).
person(tim,kingston).
person(joe,montreal).
person(jane,ottawa).
person(marie,ottawa).
person(jack,toronto).
person(simon,toronto).
employee(annie,dium).
employee(tom,shopify).
employee(jane,shopify).
employee(marie,shopify).
employee(joe,deepmind).
employee(jack,google).
employee(simon,google).
employee(suzy,shopify).
employee(paul,rossvideo).
employee(marie,rossvideo).
employee(simon,uber). 