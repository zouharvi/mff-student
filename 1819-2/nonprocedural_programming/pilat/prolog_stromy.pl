sampleTree(t(t(t(nil,4,nil),2,t(nil,5,nil)),1,t(nil,3,nil))).

inorderList(nil, []).
inorderList(t(L, V, R), Vs) :- inorderList(L, Ls), inorderList(R, Rs), append(Ls, [V|Rs], Vs).

pridejBST(nil, t(nil, X, nil), X) :- !.
pridejBST(t(L, V, R), t(L, V, R), V) :- !.
pridejBST(t(L, V, R), t(L, V, Ra), X) :- X > V, !, pridejBST(R, Ra, X).
pridejBST(t(L, V, R), t(La, V, R), X) :- X < V, !, pridejBST(L, La, X).

eSN(grafSN([1,2,3,4,5], [1->[2,3,4],2->[5], 3->[1,2,4], 4->[1], 5->[2,3]])).
gSNnaSH(grafSN(V, N), grafSH(V, Hrany)) :- bagof(hrana(V1,V2), E^(member(V1->E, N), member(V2, E)), Hrany).
gSHnaSN(grafSH(V, Hrany), grafSN(V, N)) :- setof(V1->Neigh, (member(V1, V), setof(X, member(hrana(V1,X), Hrany),Neigh)), N).

cesta(grafSH(_, E), O, K) :- member(hrana(O, K), E), !.
cesta(grafSH(V, E), O, K2) :- member(hrana(O, K1), E), cesta(grafSH(V, E), K1, K2).