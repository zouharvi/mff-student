o(X, Y, X2, Y2).

all(Obd, V):- komb(Obd, 2, V1), intersect(V1, V).

intersect([o(A,B,C,D), o(E,F,G,H)], V):- A1 is A + C, B1 is B + D, E1 is E + G, F1 is F + H, (inside(A,B, o(E,F,G,H)) ; inside(A1,B, o(E,F,G,H)) ; inside(A,B1, o(E,F,G,H)) ; inside(A1,B1, o(E,F,G,H)) ; inside(E,F,o(A,B,C,D)), inside(E1,F,o(A,B,C,D)), inside(E,F1,o(A,B,C,D)), inside(E1,F1,o(A,B,C,D))), V= o(A,B,C,D)-o(E,F,G,H).

inside(X,Y, o(A,B,C,D)):- A1 is A + C, B1 is B + D, X>=A, X=<A1, Y>=B, Y=<B1.

komb(_, 0, []).
komb([X|Xs], N, [X|Ys]):- N>0, N1 is N-1, komb(Xs, N1, Ys).
komb([X|Xs], N, Ys):- N>0, komb(Xs, N, Ys).
