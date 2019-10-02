prepend(_, [], []) :- !.
prepend(A, [L|Ls], [[A|L]|Out]) :- prepend(A, Ls, Out).


diff(S, X) :- diff(S, 2, X).

diff([], N, [[]]) :- N >= 0, !.
diff(S, 0, [S]) :- !.
diff([S|Ss], N, O4) :-
    N >= 0,
    diff(Ss, N, O1),
    prepend(S, O1, O2),
    N1 is N-1,
    diff(Ss, N1, O3),
    append(O2, O3, O4).
    