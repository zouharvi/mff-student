
genList(1, [1]) :- !.
genList(N, [N|Ns]) :- N1 is N-1, genList(N1, Ns).

termA(const, 1) :- !.
termA(un(X), N) :-
    N > 1,
    N1 is N-1,
    termA(X, N1).
termA(bin(X, Y), N) :-
    N > 2,
    N1 is N-1,
    genList(N1, List),
    !,
    member(N2, List),
    termA(X, N2),
    N3 is N1-N2,
    termA(Y, N3).

termB(X, N) :- termA(X, N).
termB(X, N) :- N1 is N+1, termB(X, N1).

term(X) :- termB(X, 0).