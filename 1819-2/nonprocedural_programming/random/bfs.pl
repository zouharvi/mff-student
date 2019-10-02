% bfs(Edges, Queue, Seen)
bfs(_, [], _, []) :- !.
bfs(Edges, [Q|Queue], Seen, [Q|Path]) :-
    findall(A, 
            (
                member(Q-A, Edges),
                \+ member(A, Seen),
                \+ member(A, Queue)
            ),
            ToAdd
            ),
    append(Queue, ToAdd, NextQueue),
    bfs(Edges, NextQueue, [Q|Seen], Path).

e1([a-b, a-c, b-c, c-d, b-e]).