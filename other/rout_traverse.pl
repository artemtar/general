%Finding first node of graph
findRoot(R):-
	findall(pool(N, L1, L2), pool(N, L1, L2), [Start|Rest]),
	western(Start, Rest, R).
western(X, [], X).
western(Check, [S|R], P):-
    Check = pool(_, _, L2),
    S = pool(_, _, L2s),
    L2s < L2,
    western(S, R, P), !.
western(Check, [_|R], P):-
    western(Check, R, P).

%Distance check
angle(X, Y):-
        Y is 3.14159265359 * X / 180.

distance(pool(_, Lat1, Lon1), pool(_, Lat2, Lon2), D):-
    angle(Lat1, Lt1),
    angle(Lat2, Lt2),
    X is ((Lt1 - Lt2) / 2),
    A is sin(X),
    angle(Lon1, Ln1),
    angle(Lon2, Ln2),
    Y is ((Ln1 - Ln2) / 2),
    B is sin(Y),
    AA is A*A,
    BB is B*B,
    C is cos(Lt1) * cos(Lt2),
    N is AA + BB * C,
    NN is sqrt(N),
    D is 2 * asin(NN) * 6371.

%add node to graph
addNode(P, N):-
    graph(P, L),
    appendLast(L, N, LL),
    retract(graph(P, L)),
    assert(graph(P, LL)),
    assert(graph(N, [])).


%add new element in list
appendLast([], N, [N]).
appendLast([H|T], N, [H|LL]):-
    appendLast(T, N, LL).

%Finding cosest node in the graph
buildGraph(R):-
    findRoot(R),
    findall(pool(N, L1, L2), pool(N, L1, L2), [_| T]),
    findSecond(R, T, _, N, 99999),
    assert(graph(R, [N])),
    assert(graph(N, [])),
    removeSecond(T, N, L),
	%skip first and second element sisnce root is already known
    findClosest(L).

findSecond(_, [], N, N, _).
findSecond(R, [H|T], _, N, X):-
    distance(R, H, D),
    D < X,
    findSecond(R, T, H, N, D), !.
findSecond(R, [_|T], NN, N, X):-
    findSecond(R, T, NN, N, X).

removeSecond([H|T], N, T):-
    H = N, !.
removeSecond([H|T], N, [H|L]):-
    removeSecond(T, N, L).

findClosest([]).
findClosest([H|T]):-
    lookforParent(H),
    findClosest(T).

lookforParent(C):-
    findall(P , graph(P, _), L),
    luke(L, C).

luke(L, C):-
    iAmYourFather(L, C, _, 999999).

iAmYourFather([], C, P, _):-
    addNode(P, C).
iAmYourFather([H|T], C, _, X):-
    distance(H, C, D),
    D < X,
    iAmYourFather(T, C, H, D), !.
iAmYourFather([_|T], C, P, X):-
    iAmYourFather(T, C, P, X).

findRoute(LL):-
	buildGraph(R),
    assert(route(R)),
    graph(R, C),
	trace(C),
    findall(P, route(P), X),
    getName(R, Name),
    atom_concat(Name, " ", L),
    atom_concat(L, 0, AddRoot),
	makeList(X, AddRoot, LL),
    reverseList(LL, [], LLL),
    saveRoute(LL, 'prolog_out.txt').

trace([]).
trace([H|T]):-
    assertz(route(H)),
    graph(H, C),    
	trace(C),
    trace(T). 

makeList(X, AddRoot, [AddRoot|L]):-
	writeFile(X, 0, L).	

writeFile([_| []], _, []):- !.
writeFile([H, HH| T], Z, [X|LL]):-	
	distance(H, HH, D),
	getName(HH, Name),
	atom_concat(Name, " ", L), 	
	ZZ is Z + D,
	atom_concat(L, ZZ, X),	
	writeFile([HH| T], ZZ, LL). 

saveRoute([], _).
saveRoute([H|T], F):-
	writeFileNewLine(H, F),
    saveRoute(T, F).

writeFileNewLine(X, FF):-	
    open(FF, append, F),
	write(F, X), nl(F),
	close(F).

reverseList([], L, L).
reverseList([H|T], L, LL):-
    reverseList(T, [H|L], LL).   

getName(pool(Name, _, _), Name).