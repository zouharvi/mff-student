prvek(X, [X|_]).
prvek(X, [_|T]) :-
    prvek(X, T).

% vypust0(Prv, Puvod, Novy)
vypust0(X, [X|T], T).
vypust0(X, [Y|T], [Y|Z]) :-
    vypust0(X, T, Z).

% vypust1(Prv, Puvod, Novy)
vypust1(X, [X|T], L) :-
    vypust1(X, T, L).
vypust1(X, [Y|T], [Y|L]) :-
    X\=Y,
    vypust1(X, T, L).
vypust1(_, [], []).

% last(X, Arr)
last(X, [X]).
last(X, [_|Y]) :-
    last(X, Y).

% lastHead(X, Head, Arr)
lastHead(X, [], [X]).
lastHead(X, [Y|Z], [Y|T]) :-
    lastHead(X, Z, T).

% first(X, Arr)
first(X, [X|_]).

% firstTail(X, Arr, Tail)
firstTail(X, [X|T], T).

% prost(+S, +S, -X)
% první argument je čítač. Když dojde do velikosti 1, nebo 2, vyextrahujeme hlavu, jinak zmenšujeme po dvou.
prost([_], [X|_], X).
prost([_,_], [X|_], X).
prost([_,_|T1],[_|T2],X) :- prost(T1,T2,X). 

% split(+Arr, -Odd, -Even)
split([], [], []).
split([A], [A], []).
split([A,B|T], [A|T1], [B,T2]) :- split(T, T1, T2).

% conc(+A, +B, -Res)
conc([], A, A).
conc([X|T], L, [X|S]) :- conc(T, L, S).

% obrat(A, Rev)
obrat([], []).
obrat([A|T], L) :- obrat(T, T1), conc(T1, [A], L).

% concrev(A, B, <rev(A), B>)
concrev([],L,L).
concrev([X|T],L,P):- concrev(T,[X|L],P). 