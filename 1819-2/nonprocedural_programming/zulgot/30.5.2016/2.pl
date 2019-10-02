plus(X,Y).
minus(X,Y).
krat(X,Y).
deleno(X,Y).

vyraz(S, A, N, NV, plus(X,Y)):- N>=0, N2 is N -1, vyraz(S, A1, N2, N3, X), N3>=0, N4 is N3 -1, vyraz(A1, A, N2, NV, Y).
vyraz(S, A, N, NV, minus(X,Y)):- N>=0, N2 is N -1, vyraz(S, A1, N2, N3, X), N3>=0, N4 is N3 -1, vyraz(A1, A, N2, NV, Y).
vyraz(S, A, N, NV, krat(X,Y)):- N>=0, N2 is N -1, vyraz(S, A1, N2, N3, X), N3>=0, N4 is N3 -1, vyraz(A1, A, N2, NV, Y).
vyraz(S, A, N, NV, deleno(X,Y)):- N>=0, N2 is N -1, vyraz(S, A1, N2, N3, X), N3>=0, N4 is N3 -1, vyraz(A1, A, N2, NV, Y).
vyraz([X|Xs], Xs, N, N, X).
vyraz([], _, _, _, _):-fail.

vyhodnot(plus(X,Y), V):- vyhodnot(X, V1), vyhodnot(Y, V2), V is V1 + V2.
vyhodnot(minus(X,Y), V):- vyhodnot(X, V1), vyhodnot(Y, V2), V is V1 - V2.
vyhodnot(krat(X,Y), V):- vyhodnot(X, V1), vyhodnot(Y, V2), V is V1 * V2.
vyhodnot(deleno(X,Y), V):- vyhodnot(X, V1), vyhodnot(Y, V2), \+ V2==0 ,V is V1 / V2.
vyhodnot(X,X):- \+ X=plus(Y,Z) , \+ X=minus(Y,Z) , \+ X=krat(Y,Z) , \+ X=deleno(Y,Z).

get_all(X, C, V):- length(X, L), L2 is L*2, vyraz(X, A, L2, NV, V1), A=[], vyhodnot(V1, V2), V2==C, V=V1.


