troj(G, X-Y, 0, []):- member(X,Y).
troj(G, X-[Y|Ys], N, [Y|V]):- N>0, hrany(G, Y, H), N2 is N - 1, troj(G, X-H, N2, V).
troj(G, X-[Y|Ys], N, V):- N>0, troj(G, X-Ys, N, V).
% Prochází hrany a hledá, jestli najde troj.

get_all(G, [], []).
get_all(G, [X-Y|Xs], V):- (troj(G, X-Y, 2, V1) -> append([X],V1, V2), get_all(G, Xs, V3), sort(V2, V4), append([V4], V3, V) ; get_all(G, Xs, V)).
%Prochází každý vrchol, dodává troje

all(G, V):- get_all(G, G, V1), reduce(V1,V).
%Dostane graf, vydá troje

hrany([], _, []).
hrany([X-Y|Z], X, Y).
hrany([Y1-Y2|Z], X, V):- hrany(Z, X, V).
% Vrátí hrany, které vedou z nějakého vrcholu

reduce([], []).
reduce([X|Xs], V):- (member(X,Xs) -> reduce(Xs,V) ; reduce(Xs, V1), append([X], V1, V)).
% Zahodí duplikátní troje
