% domy: cerveny, zluty, zeleny, bily, modry
% firmy: microsoft, google, apple, ibm, facebook
% jazyky: scala, swift, kotlin, fsharp
% systemy: linux, macos, ios, android, windows

% lidi jsou v domech v tomto pořadí
clovek(a).
clovek(b).
clovek(c).
clovek(d).
clovek(e).

ma_system(X, linux) :- clovek(X), vystudoval(X, mu).
ma_dum(X, cerveny) :- clovek(X), vystudoval(X, zcu).
programuje_v(X, swift) :- clovek(X), vystudoval(X, cvut).
pracuje_pro(X, microsoft) :- clovek(X), vystudoval(X, up).
vystudoval(e, mff). % absolvent mff v posledním domě
pracuje_pro(X, apple) :- clovek(X), ma_system(X, ios).
ma_system(X, android) :- clovek(X), ma_dum(X, zluty).
programuje_v(X, scala) :- clovek(X), ma_system(X, macos).
pracuje_pro(X, google) :- clovek(X), ma_dum(X, zeleny).

% dále víme že
vlevo(A, B) :- (clovek(A), clovek(B)),
                (
                    (A = a, B = b);
                    (A = b, B = c);
                    (A = c, B = d);
                    (A = d, B = e)
                ).
soused(A, B) :- vlevo(A, B); vlevo(B, A).

soused(A, B) :- ma_system(A, macOS), programuje_v(B, kotlin).
soused(A, B) :- ma_system(A, android), programuje_v(B, fsharp).
soused(A, B) :- ma_system(A, windows), pracuje_pro(B, ibm).
vlevo(A, B) :- ma_dum(A, bily), ma_dum(B, zeleny).
soused(A, B) :- ma_dum(A, modry), vystudoval(B, mff).
pracuje_pro(c, facebook).