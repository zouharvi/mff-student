generateTuples([A,B], [A-B]) :- !.
generateTuples([A1,A2|As], [A1-A2|Ts]) :- generateTuples([A2|As], Ts). 

occurenceInList(_, [], 0) :- !.
occurenceInList(X, [X|Xs], N) :- occurenceInList(X, Xs, N1), N is N1+1, !. 
occurenceInList(X, [_|Xs], N) :- occurenceInList(X, Xs, N).

toSet([], []).
toSet([X|Xs], Out) :- member(X, Xs), !, toSet(Xs, Out).
toSet([X|Xs], [X|Out]) :- toSet(Xs, Out).

freqSimple([], _, []).
freqSimple([A|As], List, [f(A, N)|Xs]) :- occurenceInList(A, List, N), freqSimple(As, List, Xs).
freqSimple(A, Out) :- toSet(A, Aset), freqSimple(Aset, A, Out).

frekv(List, Freqs) :- generateTuples(List, ListTuples), freqSimple(ListTuples, Freqs).