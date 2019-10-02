manzele(ja, vdova).
manzele(otec, dcera).

manzeleF(X, Y) :- manzele(Y, X); manzele(X, Y).

rodic(vdova, dcera).
rodic(otec, ja).

rodicF(X, Y) :- rodic(X, Y).
rodicF(X, Y) :- manzeleF(X, Z), rodic(Z, Y).

zet(Y, X) :- rodicF(X, Z), manzeleF(Z, Y).

% 2
rodic(vdova, syn).


sourozenec(X, Y) :- rodicF(Z, X), rodicF(Z, Y).
sourozenecF(X, Y) :- sourozenec(Y, X), sourozenec(X, Y).

svagr(X, Y) :- manzeleF(X, Z), sourozenecF(Z, Y).
svagr(X, Y) :- manzeleF(Y, Z), sourozenecF(X, Z).

% nebo teta
stryc(Y, X) :- rodicF(X, Z), sourozenecF(Z, Y).

% 3
rodic(dcera, ssyn).
vnuk(X, Y) :- rodicF(Z, X), rodicF(Y, Z).

