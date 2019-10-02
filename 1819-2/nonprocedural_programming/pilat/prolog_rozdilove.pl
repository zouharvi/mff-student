vyber([], N, _) :- N > 0, fail.
vyber([], 0, []).
vyber([H|T], N, [H|Z]) :- N1 is N-H, vyber(T, N1, Z).
vyber([_|T], N, Z) :- vyber(T, N, Z).

narozdil([], X-X).
narozdil([H|T], [H|S]-X) :- narozdil(T, S-X).