isrozdel([], _) :- !.
isrozdel([A|As], Ts) :-
    member(T, Ts),
    member(A, T),
    isrozdel(As, Ts).

split([], []).
split([A|As], [[A]|As2]) :- split(As, As2).
split([A|As], [[A|X]|As2]) :- split(As, [X|As2]).

flatten2([[A|As]], [A|As]) :- !.
flatten2([[A|As]|Qs], Qt) :- flatten2(Qs, Qo), append([A|As], Qo, Qt).

rozdel(A, C) :-
    findall(O, split(A, O), B),
    flatten2(B, C).