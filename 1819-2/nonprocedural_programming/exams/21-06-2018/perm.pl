gen_list(0, Acc, Acc) :- !.
gen_list(N, Acc, Out) :- N1 is N-1, gen_list(N1, [N|Acc], Out).
gen_list(N, Out) :- gen_list(N, [], Out).

gen_perm(L, [], Pref) :- length(L, N), length(Pref, N).
gen_perm(L, [X|Suff], Pref) :- member(X, L), \+ member(X, Pref), gen_perm(L, Suff, [X|Pref]).
gen_perm(L, Perm) :- gen_perm(L, Perm, []).

reverse([], Acc, Acc).
reverse([X|Xs], Acc, Out) :- reverse(Xs, [X|Acc], Out).
reverse(X, Out) :- reverse(X, [], Out).

is_lower([A], [B]) :- A < B, !.
is_lower([A|_], [B|_]) :- A < B, !.
is_lower([A|As], [B|Bs]) :- A =:= B, is_lower(As, Bs).

first_lower(A, [R|_], R) :- is_lower(R, A), !.
first_lower(A, [_|Rs], B) :- first_lower(A, Rs, B).

prev_perm(Perm, Prev) :- length(Perm, Length), gen_list(Length, List), bagof(X, gen_perm(List, X), Perms),
                         reverse(Perms, PermsRev), first_lower(Perm, PermsRev, Prev).