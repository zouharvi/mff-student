flip(true, false).
flip(false, true).

prepend(_, [], []) :- !.
prepend(A, [L|Ls], [[A|L]|Out]) :- prepend(A, Ls, Out).

aspon2(X, Y) :- aspon2(X, 2, Y).

aspon2([], N, [[]]) :- N =< 0, !.
aspon2([], _, []) :- !.
aspon2([A-Val|As], N, O3) :-
    flip(Val, ValFlip),
    aspon2(As, N, O1),
    prepend(A-Val, O1, O1Full),
    N1 is N-1,
    aspon2(As, N1, O2),
    prepend(A-ValFlip, O2, O2Full),
    append(O1Full, O2Full, O3).


% % 2 
% aspon2(P,V) :- aspon(2,P,V). 

% aspon(N,P,V) :- length(P,M), M>=N,!, presne(N,P,V1), N1 is N+1, aspon(N1,P,V2), append(V1,V2,V). 
% aspon(_,_,[]). 

% presne(N,[K-P|Ps],[[K-R|V1]]) :- length([K-P|Ps],M), M=N, !,switch(P,R), N1 is N-1, presne(N1,Ps,[V1]). 
% presne(N,[K-P|Ps],V) :- N>0,switch(P,R), N1 is N-1, presne(N1,Ps,V1), pridej(K-R,V1,Vr1), 
%     presne(N,Ps,V2), pridej(K-P,V2,Vr2), append(Vr1,Vr2,V). 
% presne(0,X,[X]). 

% switch(true,false). 
% switch(false,true). 

% pridej(R,[S|Ss],[[R|S]|Xs]):-pridej(R,Ss,Xs). 
% pridej(_,[],[]).