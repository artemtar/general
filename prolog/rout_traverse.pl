pool("alvin heights",-0.7573696702118861,1.2605921757058876).
pool("optimiste",-0.7571945203226652,1.26084855107748).
pool("kiwanis",-0.7573482709251491,1.2610035959236714).
pool("st-laurent",-0.7573948852625304,1.2610118975237459).
pool("bearbrook",-0.758245045573857,1.2610727541499978).
pool("bingham",-0.756922442181575,1.2610870067138156).
pool("jules morin",-0.7570641059132592,1.2610911042043584).
pool("st. paul's",-0.7573984784286492,1.2611870400297798).
pool("strathcona",-0.7571525043270554,1.261239739640528).
pool("overbrook",-0.7573084824647125,1.261325250959384).
pool("sandy hill",-0.7571116343682034,1.261420639526743).
pool("dutchie's hole",-0.7571986152957082,1.2614440700968406).
pool("cecil morrison",-0.757419856372694,1.2615443031860376).
pool("st. luke's",-0.7570098721138382,1.2616010602967624).
pool("chaudiere",-0.7567441767532127,1.2617478279937508).
pool("mcnabb",-0.756852073565979,1.2617721061456357).
pool("brantwood",-0.7571633613900783,1.2618511362230913).
pool("balena",-0.7574457115388217,1.2618809341856967).
pool("champlain",-0.7564302113525732,1.261901613921028).
pool("alda burt",-0.7576234601937104,1.2619456063762078).
pool("sylvia holden",-0.7570576670811312,1.2619501250380958).
pool("parkdale",-0.7565773832664677,1.2619830313506806).
pool("ev tremblay",-0.7567647244107847,1.2620397521411106).
pool("reid",-0.756640633117287,1.2620744073617873).
pool("weston",-0.7576187750077147,1.2621338128886495).
pool("windsor",-0.7571201840293719,1.2621735868561268).
pool("lions",-0.7563567578018889,1.2621806625377976).
pool("hawthorne",-0.7577210517645655,1.2621972569338988).
pool("iona",-0.7564551033576168,1.2622321559750898).
pool("canterbury",-0.7575917477743411,1.262312918048622).
pool("hampton",-0.7564961389128818,1.2623711037526923).
pool("westboro",-0.7563498442554007,1.262469108014654).
pool("mckellar",-0.756216848675079,1.2624844036478098).
pool("alta vista",-0.7572156422746208,1.2624920418908403).
pool("alexander",-0.7565633146577234,1.2625685901458712).
pool("heron",-0.7571068948015862,1.2625901465433966).
pool("meadowvale",-0.756631868871307,1.2626255927113674).
pool("raven",-0.7564755190574094,1.26267410398938).
pool("woodroffe",-0.7561577514751766,1.26268685336111).
pool("bellevue manor",-0.7564910936192639,1.262793905656711).
pool("elizabeth manley",-0.7576865527928753,1.2628563201749006).
pool("frank licari",-0.7573088300448871,1.2628877698596774).
pool("rideauview",-0.7568121638682467,1.26291431420641).
pool("pauline vanier",-0.7571139631461125,1.2629476393546375).
pool("kingsmere",-0.7562546543879204,1.2629973614046428).
pool("greenboro",-0.757515488455333,1.2630426385251805).
pool("britannia",-0.7558874623301968,1.2631167054067562).
pool("carleton heights",-0.7568541037440548,1.2631446120117669).
pool("agincourt",-0.7563438881966503,1.2631458241729174).
pool("pushman",-0.757397261828285,1.2631458975735108).
pool("bel air",-0.7562563545472114,1.263203852439612).
pool("parkway",-0.7561210915569975,1.2632371547932404).
pool("frank ryan",-0.7559893304322987,1.26324080923781).
pool("michã¨le",-0.7558608630997383,1.2632768777681802).
pool("owl",-0.7572316607253768,1.2632907622017961).
pool("general burns",-0.7566727881807065,1.2633650181360152).
pool("ruth wildgen",-0.7559233943027529,1.263373001668342).
pool("corkstown",-0.7556085306799575,1.2635218743380476).
pool("crestview",-0.756500201519718,1.2635693743822993).
pool("lisa",-0.755991852389742,1.263574502351199).
pool("entrance",-0.7557139406114124,1.2640730781283736).
pool("glen cairn",-0.7550338918761309,1.2649324804800388).

:-  dynamic  graph/2,  route/2.

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
    findall(pool(N, L1, L2), pool(N, L1, L2), [_, B| T]),
    findSecond(R, [B|T], _, N, 99999),
    assert(graph(R, [N])),
    assert(graph(N, [])),
	%skip first and second element sisnce root is already known
    findClosest(T).

findSecond(_, [], N, N, _).
findSecond(R, [H|T], _, N, X):-
    distance(R, H, D),
    D < X,
    findSecond(R, T, H, N, D), !.
findSecond(R, [_|T], NN, N, X):-
    findSecond(R, T, NN, N, X).

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

%1
findRoute(L):-
	buildGraph(R),
	trace(R),
	writeFile(2).

trace(R):-
    graph(R, C),
    addRoute(R, C).

addRoute(_, []).
addRoute(R, [H|T]):-
    assertz(route(R, H)),
    trace(H),
    addRoute(H, T).

writeFile(X):-	open('prolog_out.txt', append, F),
	write(F, X), nl(F),
	close(F).


















