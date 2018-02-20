:- dynamic book/4, reader/4, loan/3.

book(callNum(qa76, '73P76C57', 2003),
     location(  mrt,  general ),
     ['Programming' , in,  'Prolog' ], 
     [name( clocksin, [william, f] ), name( mellish, [christopher, s] )]).

book(callNum(qa76, '73P76S74', 1994), 
     location( mrt,  general ),
     [ 'The', art, of, 'Prolog', ':', advanced, programming, techniques],
     [name( sterling, [leon] ), name( shapiro, [ehud, y])]).

book(callNum(q336, 'B74', 2001), 
     location( mrt,  general ),
     [ 'Prolog', programming, for, artificial, intelligence ],
     [name( bratko, [ivan])] ).

reader(name(blake, [ann]), 33333,
       address([100, main], ottawa, k1a2b2),1).
reader(name(brady,[jim,b]), 12345,
       address([2, second], ottawa, k1n3m3),0).
reader(name(carp,[tony,a]), 765432,
       address([3, third], ottawa, k1k4p4),1).

loan(33333,
     callNum(qa76, '73P76C57', 2003),
     date(nov, 25, 2013)).
loan(765432,
     callNum(q336, 'B74', 2001), 
     date(oct, 20, 2013)).

wrote(Auth, CallN, Title) :-
    book(CallN, _, Title, Authors),
    member(name(Auth,_), Authors).

borrowed(Name, Title) :-
	reader(Name, Id, _Addr, _),
	loan(Id, CallN, _DateDue),
	book(CallN, _, Title, _Auths).

newLoan(Cn, Id, Due) :-
    assert(loan(Id, Cn, Due)),
    retract(reader(Nm, Id, A, N)),
    N1 is N + 1,
    assert(reader(Nm, Id, A, N1)).


returns(Id, Cn) :-
    retract(loan(Id, Cn, _Due)),
    retract(reader(Nm, Id, A, N)),
    N1 is N - 1, % loan was retracted, i.e., N1 >= 0
    assert(reader(Nm, Id, A, N1)).