sum([], 0) :- !.
sum([A|Ax], N) :- sum(Ax, N1), N is A + N1.

loupeznici(Loot, A, B) :-
    loupeznici2(Loot, A, B),
    sum(A, N),
    sum(B, N).

loupeznici2([], [], []) :- !.
loupeznici2([X|Xs], [X|As], Bs) :-
    loupeznici2(Xs, As, Bs).
loupeznici2([X|Xs], As, [X|Bs]) :-
    loupeznici2(Xs, As, Bs).
