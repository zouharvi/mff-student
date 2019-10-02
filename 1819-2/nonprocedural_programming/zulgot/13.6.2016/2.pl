differ(nil, Rights, A, A).
differ(t(L, C, R), Rights, A, V):- put_new(C, Rights, A ,A1), differ(L, Rights, A1, V1), Rights2 is Rights + 1, differ(R, Rights2, V1, V).

put_new(X, Num, A, V):- length(A, Len), Len =< Num, append(A, [[X]], V).
put_new(X, Num, A, V):- length(A, Len), Len > Num, put_in(X, Num, 0, A, [], V).

put_in(C, Num, Num2, [], A, A).
put_in(C, Num, Num2, [X | Xs], A, V):- Num == Num2, append([C], X, V1), append(A, [V1], V2), Num3 is Num2 + 1, put_in(C, Num, Num3, Xs, V2, V).
put_in(C, Num, Num2, [X | Xs], A, V):- Num\=Num2, append(A, [X], V1), Num3 is Num2 + 1, put_in(C, Num, Num3, Xs, V1, V).

t(t(t(nil, a, nil), b, t(t(nil, c, nil),d,t(nil, e, nil))), f, t(nil, g, t(t(nil, h, nil), i, nil)))
