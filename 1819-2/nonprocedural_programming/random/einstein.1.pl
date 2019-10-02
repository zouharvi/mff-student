% barva, skola, system, spolecnost, jazyk 
dum(_, mu, linux, _, _).
dum(red, zcu, _, _, _).
dum(_, cvut, _, _, swift).
dum(_, up, _, microsoft, _).

dum(_, _, ios, apple, _).
dum(yellow, _, android, _, _).
dum(_, _, macos, _, scala).
dum(green, _, _, google, _).

vlevo(A, B) :- ulice(_, _, _, A, B).
vlevo(A, B) :- ulice(_, _, A, B, _).
vlevo(A, B) :- ulice(_, A, B, _, _).
vlevo(A, B) :- ulice(A, B, _, _, _).
soused(A, B) :- vlevo(A, B); vlevo(B, A).

soused(dum(_, _, macos, _, _), dum(_, _, _, _, kotlin)).
soused(dum(_, _, android, _, _), dum(_, _, _, _, fsharp)).
soused(dum(_, _, windows, _, _), dum(_, _, _, ibm, _)).
soused(dum(_, mff, _, _, _), dum(blue, _, _, _, _)).
% vlevo(dum(white, _, _, _, _), dum(green, _, _, _, _)).

ulice(_,
      _,
      dum(_, _, _, facebook, _),
      _,
      dum(_, mff, _, _, _)
    ).

dum(_, _, _, _, prolog).