
% dfs(In, Out) :-
neigh(_, [], []) :- !.
neigh(V, [V-X|_], X) :- !.
neigh(V, [_|Neigh], Out) :- neigh(V, Neigh, Out).

addTime(V, S, [V-X|Ts], [v(V, S)-X|Ts]) :- !.
addTime(V, S, [X|Ts], [X|Os]) :- addTime(V, S, Ts, Os).

% works only for trees
strom([c-[d], a-[b,c], b-[e], d-[], e-[]]).
% strom([c-[d], a-[b,c], b-[d,e], d-[], e-[]]).

dfs(SV, Neigh, Out) :- dfsList([SV], Neigh, Out, 1, _).

dfsList([], Neigh, Neigh, S0, S0).
dfsList([V|Vs], Neigh1, Neigh4, S0, S3) :-
    addTime(V, S0, Neigh1, Neigh2), S1 is S0 + 1, % pridam si vstupni cas
    neigh(V, Neigh1, VNeigh), % zjistim deti
    dfsList(VNeigh, Neigh2, Neigh3, S1, S2), % oznacim deti
    dfsList(Vs, Neigh3, Neigh4, S2, S3). % oznacim sourozence