%%%%%%
% 1a %
%%%%%%

% s(+A)
% natural numbers
s(0).
s(s(A)) :-
    s(A).

% plus(+A, ?B, ?Z)
% A + B = Z
plus(0, X, X).
plus(s(A), B, Z) :-
    plus(A, s(B), Z).

% mul2(?A, ?Z)
% 2*A = Z
mul2(0, 0).
mul2(s(A), s(s(Z))) :-
    mul2(A, Z).

% div2(+A, ?Z)
% A / 2 = Z
div2(A, Z) :-
    mul2(Z, A).
% for rounding
div2(s(A), Z) :-
    mul2(Z, A).

% log2(+N, ?A)
% A = log2(N)
log2(s(0), 0).
log2(N, A) :-
    N\=0,
    div2(N, N1),
    log2(N1, T),
    plus(s(0), T, A).

%%%%%%
% 1b %
%%%%%%

% fibPrev(+N, ?R1, ?R2).
% stores the previous two values
fibPrev(1, 1, 0).
fibPrev(N, R1, R2) :-
    N>1,
    N1 is N-1,
    fibPrev(N1, R2, R3),
    R1 is R2+R3.

fib(N, R1) :-
    fibPrev(N, R1, _).

%%%%%%
% 1c %
%%%%%%

% concatenate two lists
% conc(+A, +B, ?Res)
conc([], X, X).
conc([A|Arest], B, [A|X]) :-
    conc(Arest, B, X).

% reverts a list
% rev(+L, ?A)
rev([], []).
rev([A|Arest], B) :-
    rev(Arest, Temp),
    conc(Temp, [A], B). 

% pads both arrays to the same size (tailing)
% padzero(+A, +B, ?C, ?D)
padzero([], [], [], []).
padzero([A|Arest], [B|Brest], [A|Crest], [B|Drest]) :-
    padzero(Arest, Brest, Crest, Drest).
padzero([], [B|Brest], [0|Crest], [B|Drest]) :-
    padzero([], Brest, Crest, Drest).
padzero([A|Arest], [], [A|Crest], [0|Drest]) :-
    padzero(Arest, [], Crest, Drest).

% add three single digit binary numbers
% binAddSingle(+A, +B, +C, ?Res, ?Carry)
binAddSingle(A, B, C, Res, Carry) :-
    Res is A xor B xor C,
    Carry is A/\B\/(C/\A xor B).

% adds two binary numbers in LSBf
% binAddRev(+A, +B, ?Res, +Carry)
binAddRev([], [], [], 0).
binAddRev([], [], [1], 1).
binAddRev([A|Arest], [B|Brest], [R|Rrest], Carry) :-
    binAddSingle(A, B, Carry, R, CarryNext),
    binAddRev(Arest, Brest, Rrest, CarryNext).

% add two binary numbers
% binAdd(+A, +B, ?Res)
binAdd(A, B, Res) :-
    rev(A, Arev),
    rev(B, Brev),
    padzero(Arev, Brev, Apadded, Bpadded),
    binAddRev(Apadded, Bpadded, Resrev, 0),
    rev(Resrev, Res).


%%%%%%%%%%%%%%
% extra code %
%%%%%%%%%%%%%%

toNat(N, R) :-
    integer(N),
    toNat_(N, R).
  
toNat_(N, R) :- N > 0 ->
(N2 is N - 1, toNat_(N2, R2), R = s(R2));
R = 0.

fromNat(0, 0).
fromNat(s(N), R) :-
fromNat(N, R2),
R is R2 + 1.
