e(a, b).
e(a, c).
e(c, d).
e(d, b).
e(x, y).
e(y, x).

path(X, Y, Path) :-
    travel(X, Y, [X], Tmp), 
    reverse(Tmp, Path).

travel(X, Y, Prev, [Y|Prev]) :- 
    e(X, Y).

travel(X, Y, Prev, Path) :-
    e(X, Z),           
    Z \== Y,
    \+member(Z, Prev),
    travel(Z, Y, [Z|Prev], Path).  