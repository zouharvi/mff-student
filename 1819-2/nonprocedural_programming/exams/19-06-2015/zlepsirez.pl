compCostVertex(_, _, [], 0) :- !.
compCostVertex(G, A, [B|Bs], Q) :-
    compCostVertex(G, A, Bs, RestCost),
    member(A-B-EdgeCost, G), !,
    Q is EdgeCost + RestCost.
compCostVertex(G, A, [_|Bs], RestCost) :-
    compCostVertex(G, A, Bs, RestCost).

isCut(_, [], _) :- !.
isCut(G, [A|As], B) :-
    member(Bel, B), !,
    \+ member(A-Bel-_, G),
    \+ member(Bel-A-_, G),
    isCut(G, As, B).

compCost(G, A, B, T) :-
    compCostT(G, A, B, T1),
    compCostT(G, B, A, T2),
    T is T1 + T2.

compCostT(_, [], _, 0) :- !.
compCostT(G, [A|As], B, Q) :- 
    compCostVertex(G, A, B, ACost),
    compCostT(G, As, B, RestCost),
    Q is ACost + RestCost.

zlepsirez(G, V1, V2, OutV) :-
    compCost(G, V1, V2, SPrice),
    (
        zlepsirez(G-SPrice, V1, V2, V1, OutV) ;
        zlepsirez(G-SPrice, V2, V1, V2, OutV)
    ).

zlepsirez(G-SPrice, SA, SB, [A1|_], A1) :- 
    delete(SA, A1, SAwoA1),
    % isCut(G, SAwoA1, [A1|SB]),
    compCost(G, SAwoA1, [A1|SB], TPrice),
    TPrice < SPrice, !.

zlepsirez(G-SPrice, SA, SB, [_|A1s], OutV) :- 
    zlepsirez(G-SPrice, SA, SB, A1s, OutV).

sample([a-b-5, c-e-1, a-c-5]).