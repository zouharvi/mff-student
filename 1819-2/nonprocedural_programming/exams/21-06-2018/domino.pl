extract_min([], A, A).
extract_min([L|Ls], A, B) :-
    length(L, N1),
    length(A, N2),
    N1 < N2, !,
    extract_min(Ls, L, B).
extract_min([L|Ls], A, B) :-
    length(L, N1),
    length(A, N2),
    N1>= N2,
    extract_min(Ls, A, B).

domino([], X, [X]).

% domino(Remaining, CurrentString, Out)
% we match current string
domino(X, [A1-A2|As], Out) :-
    (
        select(B1-A1, X, X2) ;
        select(A1-B1, X, X2)
    ),
    domino(X2, [B1-A1,A1-A2|As], Out).

% we skip the current (nonempty) string and continue
domino(X, [A|As], [[A|As]|Out]) :-
    select(B1-B2, X, X2),
    (
        domino(X2, [B1-B2], Out) ;
        domino(X2, [B2-B1], Out)
    ).

domino([A1-A2|X2], Out) :-
    findall(
        Sol,
        (
            domino(X2, [A1-A2], Sol) ;
            domino(X2, [A2-A1], Sol)
        ),
        [S1|SolAll]
    ),
    extract_min(SolAll, S1, Out).

ex1([c-a, a-b]).
ex2([8-8,1-2,2-3,3-4,7-8]).

% spravne reseni: chceme najit eulerovsky tah v grafu, kde hrany jsou domina (idealne)
% pokud maji vsechny vrcholy sudy stupen, tak ok
% pokud ne, tak do lichych vrcholu pripojime hranu do nového vrcholu NIL
% pak uděláme eulerovský tah a pokud někde bude přechod do NIL, tak tam to usekneme