
removeVertex(_,[],[]). 
removeVertex(X,[X-_|T],T1):-removeVertex(X,T,T1). 
removeVertex(X,[X1-S|T],[X1-S1|T1]):-delete(X,S,S1),removeVertex(X,T,T1). 

cutTo(A,[A|_],[A]). %Vezme část seznamu až do prvního výskytu prvku A. 
cutTo(A,[B|Z],[B|Z1]:-A/=B,cutTo(A,Z,Z1). 

circle(G,C):-member(X-[],G),removeVertex(X,G,G1),!,circle(G1,C). %Odstraním z grafu všechny vrcholy s outdegree 0 
circle([V-E|G],C):-circle_([V-E|G],[V],C). %V grafu bez vrcholů s outdegree 0 najdu kružnici na první pokus DFSkem 
circle_(G,[V|A],C):-member(V-E,G),member(V1,E),member(V1,[V|A]),!,cutTo(V1,[V|A],B),reverse(B,C). 
circle_(G,[V|A],C):-member(V-E,G),member(V1,E), circle_(G,[V1,V,|A],C). 