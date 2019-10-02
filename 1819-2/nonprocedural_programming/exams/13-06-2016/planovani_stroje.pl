test_lt([], _).
test_lt([X|Xs], Len) :- sumlist(X, N), N =< Len, test_lt(Xs, Len).

addToSomeStroj(X, Stroje1, [[X|S1]|Stroje2]) :-
    select(S1, Stroje1, Stroje2).
    
% stroje(Ulohy, Limit, Stroje1, Stroje2)
stroje([], _, X, X). % all processed, ok 
stroje([X|Xs], Limit, Stroje1, Stroje3) :- % add to the first S1
    addToSomeStroj(X, Stroje1, Stroje2),
    test_lt(Stroje2, Limit),
    stroje(Xs, Limit, Stroje2, Stroje3).

generateStroje(0, []).
generateStroje(N, [[]|Res]) :-
    N > 0, N1 is N -1,
    generateStroje(N1, Res).

strojeDriver(X, Limit, Max, Out) :-
    generateStroje(Limit, Stroje),
    stroje(X, Max, Stroje, Out), !.
strojeDriver(X, Limit, Max, Out) :-
    LimitNext is Limit+1,
    LimitNext =< Max,
    strojeDriver(X, LimitNext, Max, Out).

stroje(X, Limit, Out) :- strojeDriver(X, 1, Limit, Out).