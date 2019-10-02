
tree(L, C, R).
nill.

bvs(A, D, H, V):-bvs(A, D, H, nill, V).
bvs(nill, _, _, A, A).
bvs(tree(L, C, R), D, H, A, V):- D=<C, C=<H, insert(C, A, V1), bvs(L, D, H, V1, V2), bvs(R, D, H, V2, V).
bvs(tree(L, C, R), D, H, A, V):- \+ (D=<C, C=<H), bvs(L, D, H, A, V1), bvs(R, D, H, V1, V).

insert(X, nill, tree(nill, X, nill)).
insert(X, tree(L, C, R), V):- X<C, insert(X, L, V1), V= tree(V1, C, R).
insert(X, tree(L, C, R), V):- X>=C, insert(X, R, V1), V= tree(L, C, V1).
