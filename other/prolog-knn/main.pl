:- op(1000, xfx, [of]).


% DATA VALIDATION & MANIPULATION

% Checks that the given data list is correctly formatted
% data_correct(+Data)
data_correct([X of Class|Rest]) :-
    length(X, N),
    data_correct([X of Class|Rest], N).
data_correct([]).

% Data_correct(+Data, +Dimension)
data_correct([], _).
data_correct([X of Class|Rest], N) :-
    nonvar(Class),
    list_of_numbers(X),
    length(X, N),
    data_correct(Rest, N).

% Checks whether a given point contains only numbers
% (could be merged with length in data_correct/2)
% list_of_numbers(+Point)
list_of_numbers([]).
list_of_numbers([A|Rest]) :-
    number(A),
    list_of_numbers(Rest).

% Extracts classes from data list
% extract_targets(+Data, ?Classes)
extract_targets([], []).
extract_targets([_ of X|Rest], [X|CRest]) :- extract_targets(Rest, CRest).



% DISTANCE/METRICS/NUMERIC

% A is closer to C than B
% closer(+A, +B, +C)
closer(A of _, B of _, C) :-
    diff_squared(A, C, An),
    diff_squared(B, C, Bn),
    An @=< Bn.

% Performs squares of differences of two lists element-wise
% diff_squared(+A, +B, -C)
diff_squared([], [], 0).
diff_squared(A, B, Total) :-
    diff_list(A, B, Diff),
    square_list(Diff, Square),
    sum_list(Square, Total).

% Computes the difference of two lists
% diff_list(+A, +B, ?C)
diff_list([], [], []).
diff_list([A|ARest], [B|BRest], [T|TRest]) :-
    T is A-B,
    diff_list(ARest, BRest, TRest).

% Computes the squares a lists
% square_list(+A, ?C)
square_list([], []).
square_list([A|ARest], [T|TRest]) :-
    T is A*A,
    square_list(ARest, TRest).

% Computes the sum a lists
% sum_list(+A, ?C)
sum_list([], 0).
sum_list([A|ARest], Total) :-
    sum_list(ARest, TRest),
    Total is TRest + A.

% Computes the average of a numeric list
% avg_list(+List, ?Result)
avg_list(List, Result) :-
    sum_list(List, Sum),
    length(List, N),
    Result is Sum / N.

% Computes piece-wise average of a list of numeric lists
% avg_list_pw(+List, -ResList)
avg_list_pw([], []).
avg_list_pw([L|List], [R|Rest]) :-
    avg_list(L, R),
    avg_list_pw(List, Rest).

% Matrix transposition
% transp(+X, ?R)
transp([], []) :- !.
transp([[]|Arest], []) :- !, all_empty(Arest).
transp(A, [B|Brest]) :-
    extract_col(A, B, Arest),
    transp(Arest, Brest),
    !.
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

% Merge two sorted lists
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

% split and merge
merge_sort([A1,A2|ARest], S, Base) :-
  split([A1,A2|ARest], LL, LR),
  merge_sort(LL, LS, Base),
  merge_sort(LR, RS, Base),
  merge_b(LS, RS, S, Base).



% UTILITIES

% Takes first N elements from a list (if they exist)
% take(+N, +List, ?FirstNElements)
% N is less than zero, cut
take(N, _, Xs) :-
    N =< 0, !,
    N =:= 0,
    Xs = [].
% OK if the list is empty, but something is remaining
take(_, [], []).
% Otherwise substract one and recurse
take(N, [X|Xs], [X|Ys]) :-
    M is N-1,
    take(M, Xs, Ys).



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
most_frequent(List, MClass) :-
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
knn(Data, K, FV, Result) :-
    data_correct(Data),
    sort_by_distance(Data, Sorted, FV),
    take(K, Sorted, Neighbours),
    extract_targets(Neighbours, Targets),
    [T|_] = Targets,
    interpolate(Targets, T, Result).

% Interpolate is used to agerage/find most common
% class in the target data. Sample is the resulting
% structure (class, number of list of numbers)
% interpolate(+Targets, +Sample, -Result)
interpolate(Targets, Sample, Result) :-
    number(Sample), !,
    avg_list(Targets, Result).

interpolate(Targets, Sample, Result) :-
    list_of_numbers(Sample), !,
    transp(Targets, TargetsT),
    avg_list_pw(TargetsT, Result).

interpolate(Targets, _, Result) :-
    most_frequent(Targets, Result).