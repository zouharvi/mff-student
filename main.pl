% TODO:
% Allow dimension 0?

:- op(1000, xfx, [of]).

% Data points for knn
% p([x,y] of class)
p([1,1] of a).
p([1,3] of a).
p([1,7] of b).
p([2,2] of a).
p([2,3] of a).
p([2,5] of b).
p([3,2] of a).
p([4,1] of a).
p([4,5] of c).
p([4,6] of b).
p([4,7] of b).
p([5,5] of b).
p([5,6] of c).
p([6,2] of b).
p([6,5] of c).
p([6,6] of c).
p([7,1] of b).
p([7,6] of c).

% Example above
%   1 2 3 4 5 6 7
% 1 a . a . . . b
% 2 . a a . b . .
% 3 . a . . . . .
% 4 a . . . c b b
% 5 . . . . b c .
% 6 . b . . c c .
% 7 b . . . . c . 

% Checks that the given data list is correctly formatted
% data_correct(+Data)
data_correct([X of Class|Rest]) :- length(X, N), data_correct([X of Class|Rest], N).
data_correct([]).

% Data_correct(+Data, +Dimension)
data_correct([], _).
data_correct([X of _|Rest], N) :- point_correct(X), length(X, N), data_correct(Rest, N).

% Checks whether a given point contains only numbers
% (could be merged with length in data_correct/2)
% point_correct(+Point)
point_correct([]).
point_correct([A|Rest]) :- number(A), point_correct(Rest).


% A is closer to C than B
% closer(+A, +B, +C)
closer([A|_], [B|_], [C|_]) :-
    abs(A-C, An),
    abs(B-C, Bn),
    An @=< Bn.

% Sorts by distance using quick sort
% (code adapted from https://raw.githubusercontent.com/vituscze/neproc/master/Prolog/cviceni5.pl)
% Needed because of custom comparison closer/3 and issues with predsort
% sort_by_distance(+In, -Out, +Base)
sort_by_distance(In, Out, Base) :- merge_sort(In, [], Out, Base).

% Splits list into two (even/odd)
split([], [], []).
split([X|XS], [X|R1], R2) :- split(XS, R2, R1).

merge_b(XS, [], XS) :- !.
merge_b([], YS, YS) :- !.
merge_b([X|XS], [Y|YS], R) :-
  (
    closer(X, Y, [0]) -> 
        merge_b(XS, [Y|YS], S), R = [X|S] ;
    merge_b([X|XS], YS, S), R = [Y|S]
    
  ).

% base cases
merge_sort([], []) :- !.
merge_sort([X], [X]) :- !.
% split and mereg
merge_sort([A1,A2|ARest], S) :-
  split([A1,A2|ARest], LL, LR),
  merge_sort(LL, LS),
  merge_sort(LR, RS),
  merge_b(LS, RS, S).


% Data points are specified in p/2 facts
% knn(+K, +FeatureVector, -OutputClass)
knn(K, FV, OC) :- 
    bagof([Point of Class], p(Point of Class), Data),
    knn(Data, K, FV, OC).

% Alternatively the data can be passed as a list 
% knn(+Data, +K, +FeatureVector, -OutputClass)
knn(Data, K, FV, OC) :-
    data_correct(Data).