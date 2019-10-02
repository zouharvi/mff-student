maxfun(X,V):-maxfun(X, [], V).
maxfun([], A, A).
maxfun([X|Xs], A, V):- upgrade(A, X, V1), maxfun(Xs, V1, V2), concat(V2, V).

upgrade([], X, X):- \+ X==[].
upgrade(A,[],A):- \+ A==[].
upgrade([A-At|As], [X-Xt|Xs], V):- At=<Xt, A>=X, Xt2 is Xt - At, upgrade(As,[X-Xt2|Xs], V1), append([A-At], V1, V). 
upgrade([A-At|As], [X-Xt|Xs], V):- At=<Xt, A<X, Xt2 is Xt - At, upgrade(As,[X-Xt2|Xs], V1), append([X-At], V1, V).  
upgrade([A-At|As], [X-Xt|Xs], V):- At>Xt, A>=X, At2 is At - Xt, upgrade([A-At2|As], Xs, V1), append([A-Xt], V1).
upgrade([A-At|As], [X-Xt|Xs], V):- At>Xt, A<X, At2 is At - Xt, upgrade([A-At2|As], Xs, V1), append([X-Xt], V1, V).


concat([A-B, C-D], V):- (A==C -> New is B+D, V=[A-New] ; V=[A-B, C-D]).
concat([A-B, C-D|Xs], V):- (A==C -> New is B+D, concat([A-New|Xs], V) ; concat([C-D|Xs], V1), append([A-B], V1, V)).

