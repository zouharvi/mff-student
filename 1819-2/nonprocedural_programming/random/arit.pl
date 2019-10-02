% souc(+List, ?Souc)
souc([], 0).
souc([A|B], S) :- S is N+A, souc(B, N).

% nth(N, Arr, X)
nty(1, [X|_], X).
nty(N, [_|Rest], X) :- M is N - 1, nty(M, Rest, X).

% sub_nth(N, In, Out, X)
sub_nth(1, [_|Rest], [X|Rest], X).
sub_nth(N, [A|ARest], [A|BRest], X) :- M is N-1, sub_nth(M, ARest, BRest, X).

% del_nth(N, In, Out)
del_nth(1, [_|Rest], Rest).
del_nth(N, [A|ARest], [A|BRest]) :- M is N-1, del_nth(M, ARest, BRest).

% ins_nth(N, In, Out, X)
ins_nth(1, Rest, [X|Rest], X).
ins_nth(N, [A|ARest], [A|BRest], X) :- M is N-1, ins_nth(M, ARest, BRest, X).

% len(N, List)
len(0, []).
len(N, [_|ARest]) :- len(M, ARest), N is M+1.

% nsd(A, B, D)
nsd(A, A, A).
nsd(A, B, C) :- A > B, T is A - B, nsd(T, B, C).
nsd(B, A, C) :- A > B, T is A - B, nsd(T, B, C).

% nsdz(A, B, D)
nsdz([A|Arest], [B|Brest], C) :- nsd(A, B, C1), nsdz(Arest, Brest, C2), nsd(C1, C2, C).
nsdz([A], [B], C) :- nsd(A, B, C).
% todo: longer arr difference
nsdz([A], [], A).
nsdz([], [B], B).

% merge(A, B, AB)
merge([], [], []).
merge([A], [B], [A|[B]]).
merge([A|B], [], [A|B]).
merge([], [A|B], [A|B]).
merge([A|Arest], [B|Brest], [A|Q]) :- A < B, merge(Arest, [B|Brest], Q).
merge([A|Arest], [B|Brest], [B|Q]) :- A >=B, merge([A|Arest], Brest, Q).