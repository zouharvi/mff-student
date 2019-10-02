sum([], 0) :- !.
sum([A|Ax], N) :- sum(Ax, N1), N is A + N1.

seznam([], []).
seznam([A|As], [A|Bs]) :- seznam(As, Bs).
seznam([*|As], [B|Bs]) :- seznam([*|As], Bs).
seznam([*|As], Bs) :- seznam(As, Bs).
seznam([A|As], [*|Bs]) :- seznam(As, [*|Bs]).
seznam(As, [*|Bs]) :- seznam(As, Bs).