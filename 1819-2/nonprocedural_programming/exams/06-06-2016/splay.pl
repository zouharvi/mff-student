
splay(P,t(L,P,R),t(L,P,R)). 
splay(P,t(L,P1,nil),t(L,P1,nil)):-P>P1,!. 
splay(P,t(nil,P1,R),t(nil,P1,R)):-P<P1,!. 
splay(P,t(L,P1,R),T):-P<P1,splay(P,L,L1),rotRight(t(L1,P1,R),T). 
splay(P,t(L,P1,R),T):-P>P1,splay(P,R,R1),rotLeft(t(L,P1,R1),T). 

rotRight(t(t(A,B,C),D,E),t(A,B,t(C,D,E))). 
rotLeft(A,B):-rotRight(B,A). 