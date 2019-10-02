diffSet([], X, X).

diffSet([H|T1],Set,Z):-
 member(H, Set),       % NOTE: arguments swapped!
 !, delete(T1, H, T2), % avoid duplicates in first list
 delete(Set, H, Set2), % remove duplicates in second list
 diffSet(T2, Set2, Z).

diffSet([H|T], Set, [H|Set2]) :-
 diffSet(T,Set,Set2).

pokryti(_, [], _).
pokryti(Hrany, Vrcholy, [V|Pokryti]) :-
    member(V, Vrcholy),
    % % is minimal (not working)
    ((\+ member(V-U1, Hrany)) ; (\+ member(U1, Pokryti))),
    ((\+ member(U2-V, Hrany)) ; (\+ member(U2, Pokryti))),
    % remove covered verticies
    findall(W, (member(V-W, Hrany) ; member(W-V, Hrany) ; W = V), O1),
    diffSet(Vrcholy, O1, O2),
    pokryti(Hrany, O2, Pokryti).

example([a-e,a-b,e-c]).