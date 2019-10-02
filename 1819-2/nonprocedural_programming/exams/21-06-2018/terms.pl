% generate all combinations with repetition of length N
% gacwr(+N, +List, -Combination)
gacwr(0, _, []) :- !.
gacwr(N, L, [X|Xs]) :- member(X, L), N1 is N-1, gacwr(N1, L, Xs).

% any_split(+A1, -X1, -Y1, +A2, +X2, +Y2)
any_split([A|As], [A], As, B, [], B).
any_split([L|Ls], [L|Os1], Os2, [LX|LsX], [LX|Os1X], Os2X) :- any_split(Ls, Os1, Os2, LsX, Os1X, Os2X).

applyOState([A], [], A) :- !.
applyOState([A, B], [Op], Out) :- Out =.. [Op, A, B], !.
% applyOState([L1|Ls], [O|Os], Out) :-
%     applyOState(Ls, Os, OutTmp), applyOState([L1, OutTmp], [O], Out).
applyOState(L, O, Out) :-
    any_split(L, L1, L2, O, O1, [OpMiddle|O2]), applyOState(L1, O1, Out1), applyOState(L2, O2, Out2),
    applyOState([Out1, Out2], [OpMiddle], Out).

defineOperators([]).
defineOperators([O|Os]) :- op(10, xfx,[O]), defineOperators(Os).

gen(Atoms, Operators, Out) :-
    length(Atoms, N), N1 is N-1, gacwr(N1, Operators, OState),
    defineOperators(Operators), applyOState(Atoms, OState, Out).