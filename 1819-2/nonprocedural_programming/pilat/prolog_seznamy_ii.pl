prunik([], _, []).
prunik([X|Xs], Y, [X|Zs]) :- member(X, Y), prunik(Xs, Y, Zs), !.
prunik([_|Xs], Y, Zs) :- !, prunik(Xs, Y, Zs).

union([], X, X).
union([X|Xs], Y, O) :- \+ member(X, Y), union(Xs, [X|Y], O).
union([X|Xs], Y, O) :- member(X, Y), union(Xs, Y, O).

minseznam([X|Xs], M) :- minseznam(Xs, X, M).
minseznam([X|Xs], A, M) :- X =< A, minseznam(Xs, X, M).
minseznam([X|Xs], A, M) :- X > A, minseznam(Xs, A, M).
minseznam([], A, A).

nty(0, [X|_], X) :- !.
nty(N, [_|Xs], X) :- N1 is N-1, nty(N1, Xs, X).