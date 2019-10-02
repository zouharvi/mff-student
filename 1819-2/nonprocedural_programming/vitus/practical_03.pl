% transpose(+X, ?R)
transpose([[]|_], []). % assume empty
transpose(A, [B|BRest]) :-
    extract_1col(A, B, ARest),
    transpose(ARest, BRest).

% extract_1col(+Matrix, ?Column, ?MatrixRest)
extract_1col([], [], []).
extract_1col([[FirstFirst|FirstRow]|MatrixRest], [FirstFirst|ColRest], [FirstRow|MatrixRestCut]) :-
    extract_1col(MatrixRest, ColRest, MatrixRestCut).

% conc(+A, +B, ?Res)
conc([], X, X).
conc([A|Arest], B, [A|X]) :-
    conc(Arest, B, X).

% rev(+L, ?A)
rev([], []).
rev([A|Arest], B) :-
    rev(Arest, Temp),
    conc(Temp, [A], B). 

% rotate(+X, ?R)
rotate(X, R) :-
    transpose(X, Xp),
    rev(Xp, R).