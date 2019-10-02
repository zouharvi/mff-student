s(0).
s(s(A)) :-
    s(A).

nat(0).
nat(s(X)) :-
    nat(X).

% plus(+A, ?B, ?Z)
% A + B = Z
plus(0, X, X).
plus(s(A), B, Z) :-
    plus(A, s(B), Z).


lt(0, s(X)) :-
    nat(X).
lt(s(X), s(Y)) :-
    lt(X, Y).
leq(0, Y) :-
    nat(Y).
leq(s(X), s(Y)) :-
    leq(X, Y).

% mul(?A, ?B, ?Z)
% B*A = Z
mul(0, X, 0) :-
    nat(X).
mul(s(X), Y, R) :-
    mul(X, Y, R2),
    plus(R2, Y, R).


% div(+X, +Y, ?D, ?R) 
div(X, Y, 0, X) :- lt(X, Y).
div(X, Y, s(D), R) :- 
    plus(Y, R2, X), 
    div(R2, Y, D, R).
