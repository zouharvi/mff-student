neigh(V, [V-X|_], X) :- !.
neigh(V, [_|Gs], X) :- neigh(V, Gs, X).

cycle(V, G, Seen, Out) :-
    \+ member(V, Seen), !,
    neigh(V, G, Neigh), member(VN, Neigh),
    !, % forbid going back
    cycle(VN, G, [V|Seen], Out). 
cycle(V, _, Seen, [V|Cycle]) :-
    member(V, Seen), !,
    takeTillEqual(V, Seen, Cycle).

takeTillEqual(_, [], []) :- !.
takeTillEqual(A, [A|_], []) :- !.
takeTillEqual(A, [B|As], [B|Out]) :- A \= B, takeTillEqual(A, As, Out).

cycle([], []) :- !.
cycle([A-AN|As], Out) :- cycle(A, [A-AN|As], [], Out).