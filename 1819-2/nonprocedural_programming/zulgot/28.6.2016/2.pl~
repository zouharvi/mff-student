% Předělt ten divnej zápis na seznam dvojic
% Vzít si ze seznamu všechny N-tice a zkontrolovat, jestli některá není párování
% Vzít si poté N-1 tice a opakovat, dokud nenarazím na 0
% Vypsat první nalezenou tici a konec.


% vstup: parovani([a-[b,c,d],b-[a,c],c-[a,b,d],d-[a,c],e-[]], a-d,P)

addon(X-[], A, A).
addon(X-[Y | Ys], A, V):- append([X-Y], A, A1), addon(X-Ys, A1, V).

transform([], A, A).
transform([X-Y | Z], A, V):- addon(X-Y, A, A1), transform(Z, A1, V).
%předělá graf na dvojice

search(G, N, H, V):- N > 0, kombinace(G, N, V1), N1 is N - 1, (check(V1, H, V2) -> V=V2 ; search(G, N1, H, V)).
%hledá postupně kombinace o velikosti N, N-1 atd.

kombinace(_, 0, [[]]).
kombinace([], N, []):- N>0.
kombinace([X-Y | Z], N, V):- N>0, N1 is N-1, kombinace(Z, N1, V1), kombinace(Z, N, V2), map_insert(X-Y, V1, V3), append(V3, V2, V).
%ze seznamu X udělá seznam kombinací o velikosti N

map_insert(_, [], []).
map_insert(X-Y, [Xs | Xss], [[X-Y | Xs]|Yss]):- map_insert(X-Y, Xss, Yss).

pairs([], _).
pairs([X-Y | Z], A):- \+ member(X, A), append([X], A, A1), \+ member(Y, A1), append([Y], A1, A2), pairs(Z, A2).
% zkontroluje, zda se jedná o párování - tedy jestli se neopakují některé vrcholy

check([X | Xs], H, V):- \+ member(H, X), check(Xs, H, V).
check([X | Xs], H, V):- member(H, X), (pairs(X, []) -> V=X ; check(Xs, H, V)).
% zkontroluje, zda je některý seznam hran parování (X je seznam z kombinace) a obsahuje hledanou hranu.

parovani(G, H, V):- transform(G, [], G1), length(G1, N), search(G1, N, H, V), !.
