%%%%%
% 1 %
%%%%%

% flat(+X, ?R)
flat([], []).

% A is not a list, great
flat([A|Arest], [A|Final]) :-
    \+ is_list(A),
    !,
    flat(Arest, Final).

% A is a list, so append and recurse
flat([A|Arest], Final) :-
    is_list(A),
    append(A, Arest, AArest),
    flat(AArest, Final).


%%%%%
% 2 %
%%%%%

% transp(+X, ?R)
transp([], []) :- !.
transp([[]|Arest], []) :- !, all_empty(Arest).
transp(A, [B|Brest]) :-
    extract_col(A, B, Arest),
    transp(Arest, Brest),
    !.

% A1 | Arest
% MatrixRest
% MatrixRest
% MatrixRest
% 
% A1 | ColRest
% 
% A1 | Arest
% A2 | MatrixRight
% A3 | MatrixRight
% A4 | MatrixRight
% 
% extract_col(+Matrix, ?Column, ?MatrixRest)
extract_col([], [], []).
extract_col([[A1|Arest]|MatrixRest], [A1|ColRest], [Arest|MatrixRight]) :-
    extract_col(MatrixRest, ColRest, MatrixRight).

% asserts all lists in a list are empty
all_empty([]).
all_empty([[]]).
all_empty([A|Arest]) :-
    length(A, 0),
    all_empty(Arest).