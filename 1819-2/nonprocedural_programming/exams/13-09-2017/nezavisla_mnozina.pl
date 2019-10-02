% uspeje i kdyz se uvnitr nevyskytuje hledany prvek
select2(A, B, B) :- !, \+ member(A, B).
select2(A, B, C) :- select(A, B, C).

nez([], []).
nez([A-_|E1], [A|In]) :-
    select2(B-A, E1, E3),
    select2(A-B, E3, E4),
    nez(E4, In).
nez([_-A|E1], [A|In]) :-
    select2(B-A, E1, E3),
    select2(A-B, E3, E4),
    nez(E4, In).
nez([_|E1], Out) :- nez(E1, Out).

max_size([], T, T).
max_size([A|As], T, O) :- length(A, N), N > T, max_size(As, N, O).
max_size([A|As], T, O) :- length(A, N), N =< T, max_size(As, T, O).

nez2(Edges, Out2, L) :-
    findall(Nez, nez(Edges, Nez), Out),
    max_size(Out, 0, L),
    findall(X, (member(X, Out), length(X, N), N >= L), Out2).