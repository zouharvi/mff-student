%Udělat všechny jednice, dvojice, trojice atd., pak se podívat, jestli neexistuje jadne tice, která by měla součet menší než max a přitom všechny prvky, pokud ne, podívat se, jestli neexistují nějaké 2 tice, které mají každé součet menší než max a přitom všechny prvky atd.

komb(_, 0, [[]]).
komb([], N, []):- N>0.
komb([X|Xs], N, V):- N > 0, N1 is N - 1, komb(Xs, N1, V1), komb(Xs, N, V2), map_insert(X, V1, V3), append(V3, V2, V).

map_insert(X, [], []).
map_insert(X, [Y | Ys], [[X|Y] | Z]):- map_insert(X, Ys, Z).

all_komb(X, 0, []).
all_komb(X, N, V):- N>0, komb(X, N, V1), N1 is N - 1, all_komb(X, N1, V2), append(V1, V2, V).
% Vytvoří seznam všech kombinací až po velikost N.


select_lesser(O, X, N, MaxNum, Limit, []):- N > MaxNum.
select_lesser(O, X, N, MaxNum, Limit, V):- N =< MaxNum, komb(X, N, V1), N1 is N +1,(check(O, V1, Limit, V2) -> V=V2 ; select_lesser(O, X, N1, MaxNum, Limit,V)).
% Vezme jednice, pak dvojice atd a checkuje, jestli splňují podmínku (V1)
% Neboli budu mít třeba jednice: [[1,2,3], [4,5]...]
% dvojice [[[1,2,3],[4,5]], [[1],[2,3]]...]

sum([], A, Limit):- A=<Limit.
sum([X | Xs], A, Limit):- A=<Limit, A2 is A + X, sum(Xs, A2, Limit).

limit_check([], _).
limit_check([X | Xs], Limit):- sum(X, 0, Limit), limit_check(Xs, Limit).
% zkontroluje, 1) zda je součet dohromady pod limitem pro každou část

together([], A, A).
together([X | Xs], A, V):- append(X, A, A1), together(Xs, A1, V).

delete_one(_, [], []).
delete_one(X, [X|Ys], Ys):- !.
delete_one(X, [Y|Ys], [Y|Z]) :-
  delete_one(X, Ys, Z).

minus([], []).
minus([], [Y | Ys]):- fail.
minus([X | Xs], []):- fail.
minus([X | Xs], [Y | Ys]):- delete_one(X, [Y | Ys], Z), minus(Xs, Z).

origo_check([X | Xs], O):- together([X | Xs], [], V), minus(V, O).
% 2) zda všechny části dohromady dávají O (originál)

check(O, [], Limit, V):- fail.
check(O, [X | Xs], Limit, V):- (\+limit_check(X, Limit) ; \+origo_check(X, O)), check(O, Xs, Limit, V).
check(O, [X | Xs], Limit, V):- limit_check(X, Limit), origo_check(X, O), V=X.
% zkontroluje, 1) zda je součet dohromady pod limitem pro každou část
% 2) zda všechny části dohromady dávají O (originál)


plan(X, Max, V):- length(X, N), all_komb(X, N, V1), select_lesser(X, V1, 1, N, Max, V), !.
