form(N, NV, plus(X,Y)):- N>=1, N2 is N - 1, form(N2, N3, X), N3>=1, form(N3, NV, Y).
form(N, NV, minus(X)):- N>=1, N2 is N - 1, form(N2, NV, X).
form(N, NV, p):- N >=1, NV is N - 1.

full(N, V):- form(N, N2, V), N2==0.

