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
%   -------------
% 1|a . a 2 . . b|
% 2|. a a . b . .|
% 3|. a . . . . .|
% 4|a . . . c b b|
% 5|. . . . b c .|
% 6|. b . 3 c c .|
% 7|b 1 . . . c .|
%   -------------

% Run the following example for points indicated on the plane
% 1. knn(4, [2, 7], C).
% 2. knn(4, [1, 4], C).
% 3. knn(4, [6, 4], C).


% DATA VALIDATION & MANIPULATION

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

% Extracts classes from data list
% extract_classes(+Data, ?Classes)
extract_classes([], []).
extract_classes([_ of X|Rest], [X|CRest]) :- extract_classes(Rest, CRest).

% % Unpacks a tuple (from bagof)
% % unpack_tuple(+List, ?Output)
% unpack_tuple([], []).
% unpack_tuple([(P)|Rest], [P|TRest]) :- unpack_tuple(Rest, TRest).

% DISTANCE/METRICS

% A is closer to C than B
% closer(+A, +B, +C)
closer(A of _, B of _, C) :-
    diff_squared(A, C, An),
    diff_squared(B, C, Bn),
    An @=< Bn.

% Performs squares of differences of two lists element-wise
% diff_squared(+A, +B, -C)
diff_squared([], [], 0).
diff_squared([A|ARest], [B|BRest], Total) :-
    T is A - B,
    TS is T * T,
    diff_squared(ARest, BRest, TRest),
    Total is TRest + TS.



% SORTING

% Sorts by distance using quick sort
% (code adapted from https://raw.githubusercontent.com/vituscze/neproc/master/Prolog/cviceni5.pl)
% Needed because of custom comparison closer/3 and issues with predsort
% Base is only a point, while elements of In and Out are data points
% sort_by_distance(+In, -Out, +Base)
sort_by_distance(In, Out, Base) :- merge_sort(In, Out, Base).

% Splits list into two (even/odd)
split([], [], []).
split([X|XS], [X|R1], R2) :- split(XS, R2, R1).

merge_b(XS, [], XS, _) :- !.
merge_b([], YS, YS, _) :- !.
merge_b([X|XS], [Y|YS], R, Base) :-
  (
    closer(X, Y, Base) -> 
    merge_b(XS, [Y|YS], S, Base), R = [X|S] ;
    merge_b([X|XS], YS, S, Base),
    R = [Y|S]
  ).

% base cases
merge_sort([], [], _) :- !.
merge_sort([X], [X], _) :- !.
% split and mereg
merge_sort([A1,A2|ARest], S, Base) :-
  split([A1,A2|ARest], LL, LR),
  merge_sort(LL, LS, Base),
  merge_sort(LR, RS, Base),
  merge_b(LS, RS, S, Base).



% UTILITIES

% Takes first N elements from a list (if they exist)
% take(+N, +List, ?FirstNElements)
% OK if the list is empty, but something is remaining
% Otherwise substract one and recurse
take(N, _, Xs) :- N =< 0, !, N =:= 0, Xs = [].
take(_, [], []).
take(N, [X|Xs], [X|Ys]) :- M is N-1, take(M, Xs, Ys).




% STATISTICS

% Counts the number of occurences in a list
% Empty list, no occurences
% count(+Element, +List, -NumberOfOccurences)
count(_, [], 0).
count(X, [X|T], Y) :-
    count(X, T, Z), !,
    Y is 1+Z.
count(X, [Y|T], Z) :-
    Y \= X, !,
    count(X, T, Z).

% Computes frequencies in a list ([.. , [Class, Frequency], ..])
% freqs(+List, -Freqs)
freqs(List, Freqs) :-
    list_to_set(List, Unique),
    freqs_unique(List, Unique, Freqs).

% freqs_unique(+List, +Unique, -Freqs)
freqs_unique(_, [], []).
freqs_unique(List, [U|Unique], [[U, N]|Freqs]) :-
    count(U, List, N),
    freqs_unique(List, Unique, Freqs), !.

% Class is unified with the most frequent class in List
% If multiple classes have the same frequency, then the first occuring
% in the list is chosen
% most_frequent(+List, -Class)
most_frequent(List, [MClass, MFreq]) :-
    freqs(List, Freqs),
    most_frequent_f(Freqs, [MClass, MFreq]),
    MFreq >= 0.

most_frequent_f([], [[], -1]) :- !.
most_frequent_f([[HClass, HFreq]|Rest], [MClass, MFreq]) :-
    most_frequent_f(Rest, [_, RFreq]),
    HFreq > RFreq, !,
    MFreq is HFreq,
    MClass = HClass.
most_frequent_f([[_, HFreq]|Rest], [MClass, MFreq]) :-
    most_frequent_f(Rest, [RClass, RFreq]),
    HFreq =< RFreq, !,
    MFreq is RFreq,
    MClass = RClass.
    

% KNN

% Data points are specified in p/2 facts
% knn(+K, +FeatureVector, -OutputClass)
knn(K, FV, OC) :- 
    bagof(Point of Class, p(Point of Class), Data),
    knn(Data, K, FV, OC).

% Alternatively the data can be passed as a list 
% knn(+Data, +K, +FeatureVector, -OutputClass)
knn(Data, K, FV, OC) :-
    data_correct(Data),
    sort_by_distance(Data, Sorted, FV),
    take(K, Sorted, Neighbours),
    extract_classes(Neighbours, Classes),
    most_frequent(Classes, [OC, _]).