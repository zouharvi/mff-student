% zip(+A, +B, ?R)
zip([], [], []).

zip([A1,A2|Arest], [], [[A1,A2]|R]) :- zip(Arest, [], R).
zip([], [A1,A2|Arest], [[A1,A2]|R]) :- zip([], Arest, R).

zip([A|Arest], [B|Brest], [[A,B]|R]) :- zip(Arest, Brest, R).