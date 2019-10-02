% exp(?A, +N)
% 2^N = A
% exp(1, 0).
% exp(A, N) :-
%     N>0,
%     T is N-1,
%     exp(B, T),
%     A is B*2.

% log(+A, N)
% A = log2(N)
log(0, 1).
log(A, N) :-
    N>1,
    N1 is N/2,
    log(T, N1),
    A is T+1.

s(0).
s(s(A)) :-
    s(A).

% plus(A, B, Z)
% A + B = Z
plus(0, X, X).
plus(s(A), B, Z) :-
    plus(A, s(B), Z).

% minus(A, B, Z)
% A - B = Z
% A + Z = B
minus(A, B, Z) :-
    plus(A, Z, B).

% mul2(A, Z)
% 2*A = Z
mul2(0, 0).
mul2(s(A), s(s(Z))) :-
    mul2(A, Z).

% div2(A, Z)
% A / 2 = Z
% Z = 2*A
div2(A, Z) :-
    mul2(Z, A).
% for rounding
div2(s(A), Z) :-
    mul2(Z, A).

% log2(N, A)
% A = log2(N)
log2(s(0), 0).
log2(N, A) :-
    N \= 0,
    div2(N, N1),
    log2(N1, T),
    plus(s(0), T, A).