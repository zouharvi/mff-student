exists(A, list(A, _, _, _, _)).
exists(A, list(_, A, _, _, _)).
exists(A, list(_, _, A, _, _)).
exists(A, list(_, _, _, A, _)).
exists(A, list(_, _, _, _, A)).

vpravo(R, L, list(L, R, _, _, _)).
vpravo(R, L, list(_, L, R, _, _)).
vpravo(R, L, list(_, _, L, R, _)).
vpravo(R, L, list(_, _, _, L, R)).

middle(A, list(_, _, A, _, _)).
last(A, list(_, _, _, _, A)).

soused(A, B, C) :- vpravo(A, B, C); vpravo(B, A, C).

puzzle(Ulice) :-
    exists(dum(_, mu, linux, _, _), Ulice),
    exists(dum(red, zcu, _, _, _), Ulice),
    exists(dum(_, cvut, _, _, swift), Ulice),
    exists(dum(_, up, _, microsoft, _), Ulice),
    exists(dum(_, _, ios, apple, _), Ulice),
    exists(dum(yellow, _, android, _, _), Ulice),
    exists(dum(_, _, macos, _, scala), Ulice),
    exists(dum(green, _, _, google, _), Ulice),
    vpravo(dum(green, _, _, _, _), dum(white, _, _, _, _), Ulice),
    last(dum(_, mff, _, _, _), Ulice),
    middle(dum(_, _, _, facebook, _), Ulice),
    soused(dum(_, _, macos, _, _), dum(_, _, _, _, kotlin), Ulice),
    soused(dum(_, _, android, _, _), dum(_, _, _, _, fsharp), Ulice),
    soused(dum(_, _, windows, _, _), dum(_, _, _, ibm, _), Ulice),
    soused(dum(_, mff, _, _, _), dum(blue, _, _, _, _), Ulice),
    exists(dum(_, _, _, _, pro), Ulice).