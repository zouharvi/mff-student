mergeSorted([], X, X) :- !.
mergeSorted(X, [], X) :- !.
mergeSorted([A|As], [B|Bs], [O|Os]) :-
    append(A, B, O),
    mergeSorted(As, Bs, Os).

travSort(t(nil, X, nil), [[X]]) :- !.
travSort(t(nil, X, Right), [[X]|RightOut]) :-
    !,
    travSort(Right, RightOut).

travSort(t(Left, X, nil), [[X|L1]|LeftOut]) :-
    !,
    travSort(Left, [L1|LeftOut]).

travSort(t(Left, X, Right), [[X|L1]|Out]) :-
    travSort(Left, [L1|LeftOut]),
    travSort(Right, RightOut),
    mergeSorted(LeftOut, RightOut, Out).

tree(
    t(
        t(
            t(nil, a, nil),
            b,
            t(
                t(nil, c, nil),
                d,
                t(nil, e, nil)
            )
        ),
        f,
        t(
            nil,
            g,
            t(
                t(nil, h, nil),
                i,
                nil
            )
        )
    )
).