% 1 
cyklus(g([],_),_,_) :- fail. 
cyklus(g([V|_],H),N,C) :- hrana(V,X,H), najdicyklus(X,V,H,[X-V],C), length(C,L), L>=N. 
cyklus(g([V|Rcholy],H),N,C) :- delete(H,V-_,H1), delete(H1,_-V,H2), cyklus(g(Rcholy,H2),N,C). 

hrana(X,Y,H) :- member(X-Y,H). 
hrana(X,Y,H) :- member(Y-X,H). 

najdicyklus(O,K,H,A,C) :- hrana(O,X,H), X\=K, \+member(X-_,A), najdicyklus(X,K,H,[X-O|A],C). 
najdicyklus(O,K,H,C,[K-O|C]) :- hrana(O,K,H), \+member(O-K,C).