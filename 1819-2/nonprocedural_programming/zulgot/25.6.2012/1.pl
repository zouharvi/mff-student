h(From, To, N).

search(Vrchol, Graf, Max, V):- search(Vrchol, Graf, Graf, 0, Max, V1), unique(V1, V).
search(X, _, [], _, _, []).
search(X, Graf, [h(From, To, NH)|Ys], N, Max, V):- N=<Max, From==X, N2 is N + NH, search(To, Graf, Graf, N2, Max, V1), append([X], V1, V2), search(X, Graf, Ys, N, Max, V3), append(V2,V3,V).
search(X, Graf, [h(From, To, NH)|Ys], N, Max, V):- N=<Max, \+From==X, search(X, Graf, Ys, N, Max, V1), append([X], V1, V).


unique([], []).
unique([X|Xs], [X|V]):- \+member(X,Xs), unique(Xs, V).
unique([X|Xs], V):- member(X, Xs), unique(Xs, V).
