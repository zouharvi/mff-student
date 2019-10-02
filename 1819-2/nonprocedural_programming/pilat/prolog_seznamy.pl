is_num(0).
is_num(s(X)) :- is_num(X).

soucet(0, Y, Y) :- is_num(Y).
soucet(s(X), Y, s(Z)) :- is_num(X), is_num(Y), soucet(X, Y, Z).

soucin(_, 0, 0).
soucin(0, _, 0).
soucin(s(X), Y, Z) :- soucet(A, Y, Z), soucin(X, Y, A).


pridejk(X,[],[X]).
pridejk(X,[Y|Ys],[Y|Z]):-pridejk(X,Ys,Z).
otoc([], []).
otoc([X|Xs], Y) :- otoc(Xs, Z), pridejk(X, Z, Y).

otoc2([], X, X).
otoc2([X|Xs], A, T) :- otoc2(Xs, [X|A], T).

sudy([]).
sudy([_,_|Xs]) :- sudy(Xs).

lichy([_]).
lichy([_,_|Xs]) :- lichy(Xs).

prefix([], X) :- X = []; X = [_|_].
prefix([A|As], [A|X]) :- prefix(As, X).

suffix(X, Y) :- otoc2(Y, [], YR), prefix(XR, YR), otoc2(XR, [], X).