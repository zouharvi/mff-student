notmember([],_).
notmember([X|_],X) :- !, false.
notmember([_|Xs],X) :- notmember(Xs,X).

sjednoceni([],X,X).
sjednoceni(X,[],X).
sjednoceni([X|Xs],Y,[X|V]) :- notmember(Y,X),sjednoceni(Xs,Y,V),!.
sjednoceni([_|Xs],Y,V) :- sjednoceni(Xs,Y,V).

dupli([],[]).
dupli([X|Xs],V) :- member(X,Xs),dupli(Xs,V),!.
dupli([X|Xs],[X|V]) :- dupli(Xs,V).

% pridejBST(+T,+X,+S) :- prida prvek X do stromu T a vrati strom S
pridejBST(nil, X, t(nil,X,nil)).
%pridejBST(t(L,X,P),X,t(L,X,P)).  % odkomentovani tehle radky zpusobi, ze se prvky nemohou opakovat 	
pridejBST(t(L,U,P),X,t(T,U,P)):-X=<U,pridejBST(L,X,T). % tohle je pak treba zmenit na X<U
pridejBST(t(L,U,P),X,t(L,U,T)):-X>U,pridejBST(P,X,T).

seznamNaBST(S,T):-seznamNaBST(S,nil,T).
seznamNaBST([],T,T).
seznamNaBST([H|Hs],T1,T):-pridejBST(T1,H,T2),seznamNaBST(Hs,T2,T).

dfs1(nil,[]).
dfs1(t(A,B,C),X):-dfs(A,V1),dfs(C,V2),append(V1,[B|V2],X).

findvert(V,Hr,X):-setof(H,member(V->H,Hr),[X]).

% ds(Vrchol,NavsIN,V,Hrany,OA,NavsO,X)
cmp(V,V).
ds(_,V,V2,_,V):-sort(V,A),sort(V2,B),cmp(A,B).
%ds(Vrch,NavI,V,Hr,[Vrch|NavI]):- member(Vrch,NavI).%,fail.
ds(Vrch,NavI,_,Hr,[Vrch|NavI]):- \+ findvert(Vrch,Hr,_).%,fail.
ds(Vrch,NavI,V,Hr,NavsO):- findvert(Vrch,Hr,X),member(Y,X),\+ member(Y,NavI),ds(Y,[Y|NavI],V,Hr,NavsO).


        % test:
        % ds(1,[1],[1,2,3],[1->[2,3]],X).

vymaz1(X,[X|T],T):-!.
vymaz1(X,[H|T],[H|T1]) :- vymaz1(X,T,T1).
vymaz1(_,[],[]).

%genall([],[]).
%genall(Xs,[Y]):-member(Y,Xs),vymaz1(Y,Xs,Zb).
%genall(Xs,[Y|V]):-member(Y,Xs),vymaz1(Y,Xs,Zb),genall(Zb,V).



% DFS s ENTERING casy

grafTest(graf([a,b,c,d],[a->[c/8],b->[d/4],c->[a/4,d/6],d->[b/5]])).
grafTest2(graf([a,b,c,d],[a->[c],b->[d],c->[a,d],d->[b]])).

vrchol(V, graf(Vrcholy,_)):-member(V, Vrcholy).
hrana(V1, V2, graf(_,Hrany)):-member(V1->Succs, Hrany), member(V2, Succs).

% dfs cesta z V1 do V2?
dfsCesta(G,V1,V2, Num):-dfsCesta(G,V1,V2,[V1], 0, Num).
dfsCesta(_,X,X,_,Counter1, Counter2):-Counter2 is Counter1 + 1.
dfsCesta(G,X,Z,Found, Counter1, Counter2):-hrana(X,Y,G),\+member(Y,Found), C is Counter1 + 1, dfsCesta(G,Y,Z,[Y|Found], C, Counter2).

% dfs vsechny dosazitelne vrcholy ocislovane, tak jak do nich dojdu
dfsVrcholy1(G, V, Targets):-setof(v(Target,C), dfsCesta(G, V, Target, C), Targets).


% ROTACE O JEDNA DOLEVA

%rot(+A,-B)
rot([X|Xs]-R2,[X|Xs]-Z):-R2=[adam,Z].
rotateDiffListLeft([X|Xs]-Z,Xs-T):-Z=[X|T].

% PODRUHE

rota([X|Xs],V):-rota_(Xs,X,V).
rota_([],A,[A]).
rota_([X|Xs],A,[X|V]):-rota_(Xs,A,V).

% NEZAVISLA MNOZINA
% se setofem :(

subset([], []).
subset([E|Tail], [E|NTail]):- subset(Tail, NTail).
subset([_|Tail], NTail):- subset(Tail, NTail).

gdva(S,[A,B]):-member(A,S),member(B,S).
tst(G,Vr):- setof(B,(gdva(Vr,B)),X),tst2(G,X).
tst2(_,[]).
tst2(G,[[X,Y]|Xs]):- \+ hrana(X,Y,G),tst2(G,Xs).
nezmn(graf(V,E),X):- subset(V,X),tst(graf(V,E),X).

% ZLEPSUJICI REZ

hrana2(V1, V2, graf(_,Hrany),C):-member(V1->Succs, Hrany), member(V2/C, Succs).
hrany(G,V1,V2,Y2) :- setof(A-B/C, (member(A,V1),member(B,V2),hrana2(A,B,G,C)), Y2 ),!.
hrany(_,_,_,[]).
hranyop(G,V1,V2,Y) :- setof(B-A/C2, (member(A,V1),member(B,V2),hrana2(B,A,G,C2)), Y ),!.
hranyop(_,_,_,[]).
vsehrany(G,V1,V2,X) :- hrany(G,V1,V2,Y2),hranyop(G,V1,V2,Y), append(Y,Y2,X).
fcena([],0).
fcena([_-_/Z|Xs],C) :- fcena(Xs,C1),C is C1 + Z.
novyrez(V1,V2,N1,[Y|V2],Y):-member(Y,V1),vymaz1(Y,V1,N1).
novyrez(V1,V2,[Y|V1],N2,Y):-member(Y,V2),vymaz1(Y,V2,N2).
lepsirez(G,V1,V2,Cn,X,W) :- novyrez(V1,V2,A,B,W),vsehrany(G,A,B,X),fcena(X,Cn),vsehrany(G,V1,V2,Y),fcena(Y,Cp),Cn > Cp.

% MAXIMALNE 2 JINAK OHODNOCENE PROMENNE
% ma chybku, vybira duplikaty tj. nejdrive vybere [a,b] a pak vybere [b,a].. coz e to same.

%atmost2(+Sez,-Nov).
prehod(true,false).
prehod(false,true).
atmost1a(Sez,[Prv-VN|Nov]):-member(Prv-V1,Sez),vymaz1(Prv-V1,Sez,Nov),prehod(V1,VN).
atmost2a(Sez,[P2-VN2,P1-VN1|Nov2]):-member(A,Sez),member(B,Sez),A\=B,A=P1-V1,B=P2-V2,vymaz1(A,Sez,Nov),vymaz1(B,Nov,Nov2),prehod(V1,VN1),prehod(V2,VN2).
atmost2(Sez,Vys):- setof( V1, (atmost1a(Sez,V1)), O1) , setof(V2, (atmost2a(Sez,V2)), O2), append(O1,O2,Vys).


%%%% VYRAZY

%2) Na vstupu dostaneme posloupnost čísel a číslo V. Máme vrátit všechny možné matematické výrazy,
%které lze z dané posloupnosti postavit pomocí operátorů +, -, *, // a závorek, a jejichž hodnota je V.
%Výraz musí využít všechna zadaná čísla, a jejich pořadí nesmí měnit. Dále si máme dávat pozor, abychom ve výrazu nedělili nulou.

oper(Cislo1, SC1, Cislo2, SC2, CisloRes, SCRes) :- (CisloRes is Cislo1 + Cislo2, string_concat("(", SC1, T1), string_concat(T1, "+", T2), string_concat(T2, SC2, T3), string_concat(T3, ")", SCRes));
                                                   (CisloRes is Cislo1 - Cislo2, string_concat("(", SC1, T1), string_concat(T1, "-", T2), string_concat(T2, SC2, T3), string_concat(T3, ")", SCRes));
                                                   (CisloRes is Cislo1 * Cislo2, string_concat("(", SC1, T1), string_concat(T1, "*", T2), string_concat(T2, SC2, T3), string_concat(T3, ")", SCRes));
                                                   (Cislo2 \= 0, CisloRes is Cislo1 / Cislo2, string_concat("(", SC1, T1), string_concat(T1, "/", T2), string_concat(T2, SC2, T3), string_concat(T3, ")", SCRes)).

proved([Result], [], Result, [String], String).
proved([Cislo1,Cislo2|Zasobnik], Vstup, Result, [String1,String2|StringZas], StringResult) :- oper(Cislo1, String1, Cislo2, String2, Vysledek, SVysledek),
                                                                         proved([Vysledek|Zasobnik],Vstup, Result, [SVysledek|StringZas], StringResult).
proved(Zasobnik, [V|Vstup], Result, StringZas, StringResult):-proved([V|Zasobnik], Vstup, Result, StringZas, StringResult).

cisla_stringy([],[]).
cisla_stringy([N|Nums],[S|Strings]):-number_string(N,S), cisla_stringy(Nums, Strings).

moznosti(Vstup, V, StringResult):-cisla_stringy(Vstup, StringZas), proved([], Vstup, Result, StringZas, StringResult), Result=V.


%1) PREORDER + POSTORDER

traverse_(nil, Counter, Counter,C,C, nil).
traverse_(t(nil, Val, nil), Counter, Counter, C,C,t(nil, Counter-Val-C, nil)).
traverse_(t(Left, Val, Right), CounterIn, CAOut2,C2In,C2F, Result):- CA is CounterIn + 1, traverse_(Left, CA, CAOut,C2In,C2Out, ResL),
                                                                CA2 is CAOut + 1, C2OutA is C2Out+1, traverse_(Right, CA2, CAOut2, C2OutA, C2Out2,ResR),
                                                                C2F is C2Out2+1, Result = t(ResL, CounterIn-Val-C2F, ResR).

traverse(Strom, OhodnocenyStrom):-traverse_(Strom, 0, _,0,_, OhodnocenyStrom), !.

% Castecne USPORADANA MNOZINA

cUMTest(graf([a,b,c,d],[a->c,b->d,c->a,c->d,d->b])).

vrCum(V, graf(Vrcholy,_)):-member(V, Vrcholy).
hrCum(V1, V2, graf(_,Hrany)):-member(V1->V2, Hrany).

% dfs cesta z V1 do V2?
cumC(G,V1,V2):-cumC(G,V1,V2,[V1]).
cumC(_,X,X,_).
cumC(G,X,Z,Found):-hrCum(X,Y,G),\+member(Y,Found), cumC(G,Y,Z,[Y|Found]).

nepor(graf(Vrch,E),X):-setof( A->B,  (member(A,Vrch),member(B,Vrch),\+cumC(graf(Vrch,E),A,B)) , X ).

% PARY CO PORUSUJI BVS VLASNOST STROMU

hod(t(_,H,_),H).
poruP(A,B,[]):- A =< B,!.
poruP(A,B,[A-B]):- A > B,!.
poruL(A,B,[]):- A >= B,!.
poruL(A,B,[A-B]):- A < B,!.
hodnotypod(t(nil,_,nil),[]).
hodnotypod(t(L,H,nil),P1) :- hod(L,V1),poruL(H,V1,P1).
hodnotypod(t(nil,H,P),P1) :- hod(P,V1),poruP(H,V1,P1).
hodnotypod(t(L,H,P),R):- hod(L,V1),hod(P,V2),poruL(H,V1,P1),poruP(H,V2,P2),append(P1,P2,R).

btraverse_(nil,V,V).
btraverse_(t(nil, _, nil),V,V).
btraverse_(t(Left, Val, Right),Sez, Result):- btraverse_(Left,Sez, ResL),btraverse_(Right,ResL,ResR),
                                              hodnotypod(t(Left,Val,Right),New), append(ResR,New,Result).

porusuji(Strom, Res):-btraverse_(Strom, [], Res),!.

% TROJUHELNIKY

trojG(graf([a,b,c,d,e],[a->[b,c,d],b->[c,a],c->[b,d,a],d->[a,c],e->[]])).

choose1([],A,A).
choose1([X|Xs],A,V):-choose2(Xs,X,[],Vysl),append(Vysl,A,Res),choose1(Xs,Res,V).
choose2([],_,A,A).
choose2([P2|Xs],P1,A,V):- choose3(Xs,P1,P2,[],Vysl1),append(Vysl1,A,Res),choose2(Xs,P1,Res,V).
choose3([],_,_,A,A).
choose3([X|Xs],P1,P2,A,V):-choose3(Xs,P1,P2,[[P1,P2,X]|A],V).

hrana2(V1, V2, graf(_,Hrany)):-member(V1->Succs, Hrany), member(V2, Succs).
troj(graf(Vert,Edgs),V):-choose1(Vert,[],Trojice),troj1(graf(Vert,Edgs),Trojice,[],V).
troj1(_,[],A,A).
troj1(G,[X|Xs],A,V):-checkTroj(G,X,R),R\=[],troj1(G,Xs,[R|A],V),!.
troj1(G,[X|Xs],A,V):-checkTroj(G,X,[]),troj1(G,Xs,A,V).
checkTroj(G,[A,B,C],[A,B,C]):-hrana2(A,B,G),hrana2(B,C,G),hrana2(A,C,G),!.
checkTroj(_,[_,_,_],[]).

% MINIMALNE 2 RUZNE OHODNOCENI PROMENNYCH ATLEAST2

ohod([],A,A).
ohod([X|Xs],A,V):-member(O,[true,false]),ohod(Xs,[X-O|A],V).
porov([],_,[_,_|_]).
porov([P-H|Xs],Zad,A):-member(P-H2,Zad),H\=H2,!,porov(Xs,Zad,[P|A]).
porov([_|Xs],Zad,A):-porov(Xs,Zad,A).
sepprom([],A,A).
sepprom([P-_|Zs],A,V):-sepprom(Zs,[P|A],V).
filtruj([],_,A,A).
filtruj([Oh|Os],Zad,A,V):-porov(Oh,Zad,[]),!,filtruj(Os,Zad,[Oh|A],V).
filtruj([_|Os],Zad,A,V):-filtruj(Os,Zad,A,V).
min2(Zad,V):-sepprom(Zad,[],Prom),setof(X,ohod(Prom,[],X),Ohod),filtruj(Ohod,Zad,[],V).

% LUKASUV ATLEAST A ATMOST
negace(true, false).
negace(false, true).

aaatmost2_(C, List, List, N, N):-C=<2.
aaatmost2_(C, [X-BoolX|Xs], Result, I, N) :- I<N, ((I1 is I + 1, atmost2_(C, Xs, Result2, I1, N), Result=[X-BoolX|Result2]);
                                                (C =< 1, I2 is I +1, C2 is C+1, negace(BoolX, BoolX2), atmost2_(C2, Xs, Result3, I2, N),Result=[X-BoolX2|Result3])).

aaatmost2(L1, L2):-length(L1, N),atmost2_(0, L1, L2,0, N).

aaatleast2_(C, List, List, N, N):-C >= 2.
aaatleast2_(C, [X-BoolX|Xs], Result, I, N) :- I<N, ((I1 is I + 1, atleast2_(C, Xs, Result2, I1, N), Result=[X-BoolX|Result2]);
                                                (I2 is I +1, C2 is C+1, negace(BoolX, BoolX2), atleast2_(C2, Xs, Result3, I2, N),Result=[X-BoolX2|Result3])).

aaatleast2(L1, L2):-length(L1, N),atleast2_(0, L1, L2, 0, N).

% KONTRAKCE EKVIVALENTNICH VRCHOLU

novev([],_,A,A).
novev([V|Vrch],Ekviv,A,Nove):- \+ member(V,Ekviv),!,novev(Vrch,Ekviv,[V|A],Nove).
novev([_|Vrch],Ekviv,A,Nove):-novev(Vrch,Ekviv,A,Nove).
puvhrany([],_,A,A).
puvhrany([V1-V2|Hr],NoveV,A,NoveH):-member(V1,NoveV),member(V2,NoveV),!,puvhrany(Hr,NoveV,[V1-V2|A],NoveH).
puvhrany([_-_|Hr],NoveV,A,NoveH):-puvhrany(Hr,NoveV,A,NoveH).
novehrany([],_,_,_,A,A).
novehrany([V1-V2|Hr],NoveV,EkV,E,A,V):-member(V1,EkV),member(V2,NoveV),\+member(E-V2,A),!,novehrany(Hr,NoveV,EkV,E,[E-V2|A],V).
novehrany([V1-V2|Hr],NoveV,EkV,E,A,V):-member(V1,NoveV),member(V2,EkV),\+member(V1-E,A),!,novehrany(Hr,NoveV,EkV,E,[V1-E|A],V).
novehrany([_-_|Hr],NoveV,EkV,E,A,V):-novehrany(Hr,NoveV,EkV,E,A,V).

kontra(graf(V,H),Ekviv,JM,graf([JM|NovV],NovE)):-novev(V,Ekviv,[],NovV),novehrany(H,NovV,Ekviv,JM,[],NovE2),puvhrany(H,NovV,[],NovE1),append(NovE1,NovE2,NovE).


% PROTINAJICI SE OBDELNIKY

protinaji(o(X,Y,VX,VY), o(X1,Y1,_,_)):-X=<X1,Y=<Y1,XX is X+VX, YY is Y+VY,XX>=X1,YY>=Y1,!.
protinaji(o(X1,Y1,_,_), o(X,Y,VX,VY)):-X=<X1,Y=<Y1,XX is X+VX, YY is Y+VY,XX>=X1,YY>=Y1,!.

vyber1([],A,A).
vyber1([X|Xs],A,V):-vyber2(Xs,X,[],Res),append(A,Res,Res2),vyber1(Xs,Res2,V).
vyber2([],_,A,A).
vyber2([X|Xs],Prvek,A,V):-vyber2(Xs,Prvek,[[Prvek,X]|A],V).

zpracujObdelniky([],A,A).
zpracujObdelniky([[Ob1,Ob2]|Xs],A,V):-protinaji(Ob1,Ob2),!,zpracujObdelniky(Xs,[[Ob1,Ob2]|A],V).
zpracujObdelniky([[_,_]|Xs],A,R):-zpracujObdelniky(Xs,A,R).
protOb(SezOb,V):-vyber1(SezOb,[],Dvojice),zpracujObdelniky(Dvojice,[],V).