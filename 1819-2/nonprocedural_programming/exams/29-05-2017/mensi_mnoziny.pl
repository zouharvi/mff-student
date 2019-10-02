strip([], []).
strip([A-_|As], [A|Os]) :- strip(As, Os).

setDiff([], _, []) :- !.
setDiff(As, [], As) :- !.
setDiff([A|As], [A|Bs], Out) :- !, setDiff(As, Bs, Out).
setDiff([A|As], [_|Bs], [A|Out]) :- setDiff(As, Bs, Out).

gt(_-_, [], _) :- !.
gt(X-Y, [B|Bs], BVals) :-
    member(B-BVal, BVals),
    Y >= BVal,
    gt(X-Y, Bs, BVals).

mensi(A, B) :-
    strip(A, Ast),
    strip(B, Bst),
    setDiff(Ast, Bst, AwoB),
    setDiff(Bst, Ast, BwoA),
    member(X, BwoA),
    member(X-Y, B),
    gt(X-Y, AwoB, A).