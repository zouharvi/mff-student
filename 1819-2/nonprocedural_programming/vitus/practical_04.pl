delete(X, t(t(nil, X, nil), Y, Z), t(nil, Y, Z)).
delete(X, t(Z, Y, t(nil, X, nil)), t(Z, Y, nil)).

delete(X, t(A, B, C), t(Arest, B, C)) :- X < B, delete(X, A, Arest).
delete(X, t(A, B, C), t(A, B, Crest)) :- X > B, delete(X, C, Crest).

delete(X, t(A, X, C), t(A, M, Crest)) :- getmaxrest(C, Crest, M).

getmaxrest(t(A, X, nil), A, X) :- !. % rightmost
getmaxrest(t(A, X, R), t(A, X, R1), Y) :- getmaxrest(R, R1, Y). 

tree1(t(t(t(nil, 1, nil), 2, t(nil, 3, nil)), 5, t(nil, 10, nil))).
tree2(t(t(nil, 7, nil), 5, t(nil, 10, nil))).