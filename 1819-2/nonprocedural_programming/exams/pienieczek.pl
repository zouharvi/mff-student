% http://forum.matfyz.info/viewtopic.php?f=169&t=11381


% loupeznici
loupeznici(X,L1,L2) :- rozdel(X,L1,S1,L2,S1).

rozdel([],[],0,[],0).
rozdel([X|Xs],[X|L1],S1N,L2,S2) :- rozdel(Xs,L1,S1,L2,S2), S1N is S1+X.
rozdel([X|Xs],L1,S1,[X|L2],S2N) :- rozdel(Xs,L1,S1,L2,S2), S2N is S2 + X.

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% seznamy s hvezdickou - da se za hvezdicku neco doplnit tak, aby se seznamy rovnaly?
hvezdicka([],[]).
hvezdicka([*|L1],[_|L2]) :- hvezdicka([*|L1],L2).
hvezdicka([*|L1],[_|L2]) :- hvezdicka(L1,L2).
hvezdicka([_|L1],[*|L2]) :- hvezdicka(L1,[*|L2]).
hvezdicka([_|L1],[*|L2]) :- hvezdicka(L1,L2).
hvezdicka([L|L1],[L|L2]) :- hvezdicka(L1,L2).

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% multiplikativni grupa - 19. 9. 2016
rady([[J|Prvky]|Radky],[J-1|R]) :- rady([[J|Prvky]|Radky],1,R,J).

rady([Prvky|Radky],X,[P-R|Res],J) :- length(Prvky,L), X<L,nth0(X,Prvky,P), rad(P,P,Prvky, Radky,J,R), X1 is X+1, rady([Prvky|Radky],X1,Res,J),!.
rady(_,_,[],_).

rad(J,_,_,_,J,1) :- !.
rad(P,PuvP,Prvky,Radky,J,R) :- nth1(X,Prvky,PuvP), member([P|Radek],Radky), nth1(X,[P|Radek],NewP), rad(NewP,PuvP,Prvky,Radky,J,R1), R is R1+1.  

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% trojuhelniky v grafu: Nájdite všetky trojuholníky v neorientovanom grafe. Každý trojuholník práve raz.

trojuhelniky(G,T) :- vrcholy(G,V), generujTrojice(V,Tr), najdiTrojuhelniky(Tr,G,T).

vrcholy([],[]).
vrcholy([Vrchol-_|Zbytek],[Vrchol|NewZbytek]) :- vrcholy(Zbytek, NewZbytek).

generujTrojice([V1,V2,V3|Vs],[[V1,V2,V3]|R]) :- generujTrojice([V1,V2|Vs],R1), generujTrojice([V1,V3|Vs],R2),
	generujTrojice([V2,V3|Vs],R3), append(R1,R2,RTmp), append(RTmp,R3,R).
generujTrojice([_,_],[]).

najdiTrojuhelniky([[V1,V2,V3]|Vs],G,[t(V1,V2,V3)|T]) :- member(V1-H1,G), member(V2-H2,G), member(V3-H3,G), member(V2,H1),
	member(V3,H2), member(V1,H3), najdiTrojuhelniky(Vs,G,T),!.
najdiTrojuhelniky([_|Vs],G,T) :- najdiTrojuhelniky(Vs,G,T).
najdiTrojuhelniky([],_,[]). 

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% Napište predikát, který naplánuje pokud možno optimální (nutné použít nějakou jednoduchou heuristiku) rozvrh výroby na strojích. Na vstupu je seznam délek operací (např. [3,3,2,6,4]) a maximální čas běhu (např. 10). Operace je možné plánovat na paralelně běžící stroje, chceme, aby celkový počet potřebných strojů byl co nejmenší. Výstupem má být nějaké optimální rozložení operací pro jednotlivé stroje (např. [[3,3,2],[6,4]], což znamená, že použijeme dva stroje, první z nich vykoná operace trvající 3, 3 a 2 úseky, druhý operace trvající 6 a 4 časové úseky, obojí se vejde do limitu 10 časových úseků / stroj).
 
stroje([L|Ps],L,[[L]|R]) :- stroje(Ps,L,R).
stroje([P|Ps],L,[[P|Pouz]|R]) :- P<L, P2 is L-P, dopln(P2,Ps,Pouz,NewPs), stroje(NewPs,L,R). 
stroje([],_,[]).

dopln(Sum,Odkud,[Sum],Zbytek) :- member(Sum,Odkud), odstran(Odkud,Sum,Zbytek),!.
dopln(Sum,Odkud,[X|Xs],Zbytek2) :- nejblizsi(Sum,Odkud,X), X\=[], odstran(Odkud,X,Zbytek), SumN is Sum-X, dopln(SumN,Zbytek,Xs,Zbytek2),!.
dopln(Sum,Odkud,[],Odkud) :- nejblizsi(Sum,Odkud,[]).

odstran([Co|Odkud],Co,Odkud).
odstran([O|Odkud],Co,[O|Zbytek]) :- O\=Co, odstran(Odkud,Co,Zbytek).
odstran([],_,[]).

nejblizsi(Cislo,Odkud,Cislo) :- member(Cislo,Odkud),!.
nejblizsi(Cislo,Odkud,Vysl) :- Cislo > 0, CisloN is Cislo-1, nejblizsi(CisloN,Odkud,Vysl),!.  
nejblizsi(_,_,[]).

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% Máte zadaný binární strom (klasická t(vlevo, hodnota, vpravo) notace). Roztřiďte vrcholy podle toho, kolikrát musíme jít doprava, než je objevíme. Například pro tento strom je výstupem [[A,B,F],[C,D,G],[E,H,I]].
% https://upload.wikimedia.org/wikipedia/commons/7/77/Sorted_binary_tree_inorder.svg

vpravo(Strom,[V0|Vs]) :- jdiVpravo(0,Strom,V0), pokracuj(1,Strom,Vs).

jdiVpravo(0,t(L,H,_),[H|Res]) :- jdiVpravo(0,L,Res).
jdiVpravo(K,t(L,_,R),Res) :- K>0, jdiVpravo(K,L,Res1), K1 is K-1, jdiVpravo(K1,R,Res2), append(Res1,Res2,Res).
jdiVpravo(_,nil,[]).

pokracuj(K,Strom,[Vs1|Vs2]) :- jdiVpravo(K,Strom,Vs1), Vs1\= [], K1 is K+1, pokracuj(K1,Strom,Vs2),!.
pokracuj(_,_,[]).

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

	% Napište predikát termy(+N, -V), který postupně skrze V vydá všechny možnosti, jak lze z právě N funktorů poskládat smysluplný výraz. Každý funktor je buď binární plus/2 nebo unární minus/1 anebo nulární p/0. Na pořadí možností ve výstupu nezáleží.
termy(N,plus(T1,T2)) :- N>2, N1 is N-1, mensi(K1,N1), K2 is N-1-K1, termy(K1,T1), termy(K2,T2).
termy(N,minus(T)) :- N>1, N1 is N-1, termy(N1,T).
termy(1,p).

mensi(X,Y) :- Y>1, X is Y-1.
mensi(X,Y) :- Y>1, Y1 is Y-1, mensi(X,Y1).

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% Napište predikát parovani(+G, +H, -P), který bere neorientovaný graf G bez smyček (tj. reflexivních hran) zadaný jako seznam následníků, hranu H v podobě (v1-v2) a vydá co do inkluze maximální párování obsahující zadanou hranu H (pozor: nikoli největší párování, ale pouze maximální co do inkluze).
parovani(G,H,P) :- parovani2(G,[H],P).

parovani2([A-[B|_]|As],H,P) :- nesparovany(A,H), nesparovany(B,H), !, parovani2([As],[A-B|H],P).
parovani2([A-[_|Bs]|As],H,P) :- parovani2([A-Bs|As],H,P).
parovani2([_-[]|As],H,P) :- parovani2(As,H,P).
parovani2([],P,P).

nesparovany(V,H) :- \+member(V-_,H), \+member(_-V,H).

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% Naprogramujte predikat splay(+Hodnota, +BinarniVyhledavaciStrom, -Vysledek), ktery provede funkci splay (protahnout dany vrchol az do korene pomoci rotaci) na Hodnotu. Pokud Hodnota ve strome neni, pak se splay provede na bezprostredniho predchudce/naslednika.
splay(Hodnota, t(Levy, Hodnota, Pravy), t(Levy,Hodnota,Pravy)).
splay(Hodnota, t(Levy,H,Pravy), Vysl) :- H<Hodnota, splay(Hodnota,Pravy,Vysl1), rotujVlevo(t(Levy,H,Vysl1),Vysl).
splay(Hodnota, t(Levy,H,Pravy), Vysl) :- H>Hodnota, splay(Hodnota,Levy,Vysl1), rotujVpravo(t(Vysl1,H,Pravy),Vysl).
splay(_,nil,nil).

rotujVlevo(t(Levy,H,t(PLevy,PH,PPravy)),t(t(Levy,H,PLevy),PH,PPravy)).
rotujVpravo(t(t(LLevy,LH,LPravy),H,Pravy), t(LLevy,LH,t(LPravy,H,Pravy))).  

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% Na vstupu mame seznam po castech konstantnich funkci [Funkce], kde kazda Funkce je ve tvaru [DelkaUseku-Hodnota]. Vsechny funkce zacinaji v 0 a po konci posledniho useku pokracuji hodnotou 0. Mame vytvorit nejmensi novou funkci takovu, ze v kazdem bode je vetsi rovna vsem zadanym funkcim.
% Priklad: [ [2-5, 2-3], [3-4] ]
% Dve funkce: prvni ma v intervalu [0, 2) hodnotu 5, v intervalu [2, 4) hodnotu 3 a v intervalu [4, inf) hodnotu 0. Druha ma v intervalu [0, 3) hodnotu 4 a v intervalu [3, inf) hodnotu 0.
% Vysledkem je fce [2-5, 1-4, 1-3]

minfunkce(Funkce,Vysl) :- minfunkce2(Funkce,Vysl1), merge(Vysl1,Vysl).

merge([D1-X,D2-Y|Rs],[D1-X|Rss]) :- X\=Y, merge([D2-Y|Rs],Rss).
merge([D1-X,D2-X|Rs],Rss) :- D is D1+D2, merge([D-X|Rs],Rss).
merge([X],[X]).

minfunkce2([],[]).
minfunkce2([[]|Fs],Res) :- minfunkce2(Fs,Res),!.
minfunkce2(Funkce,[MinD-MaxF|F]) :- najdiMinD(Funkce,MinD), najdiMaxF(Funkce,MaxF), oddelejUsek(MinD,Funkce,FN), minfunkce2(FN,F).

najdiMinD([[D-_|_]|Fs],MinD) :- najdiMinD(Fs,D,MinD).
najdiMinD([[D-_|_]|Fs],Min,MinD) :- D<Min, najdiMinD(Fs,D,MinD),!.
najdiMinD([_|Fs],Min,MinD) :- najdiMinD(Fs,Min,MinD).
najdiMinD([],MinD,MinD).

najdiMaxF([[_-F|_]|Fs],MaxF) :- najdiMaxF(Fs,F,MaxF).
najdiMaxF([[_-F|_]|Fs],Max,MaxF) :- F>Max, najdiMaxF(Fs,F,MaxF),!.
najdiMaxF([_|Fs],Max,MaxF) :- najdiMaxF(Fs,Max,MaxF).
najdiMaxF([],MaxF,MaxF).

oddelejUsek(D,[[D-_|Fs]|Fss],[Fs|FssN]) :- oddelejUsek(D,Fss,FssN).
oddelejUsek(D,[[X-F|Fs]|Fss],[[Y-F|Fs]|FssN]) :- X>D, Y is X-D, oddelejUsek(D,Fss,FssN).
oddelejUsek(D,[[]|Fss],FssN) :- oddelejUsek(D,Fss,FssN).
oddelejUsek(_,[],[]).

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% Je zadán obecný graf. (reprezentaci si máme zvolit) Máme nad ním spustit DFS, a ke každému vrcholu si poznamenat čas, kdy jsme do něj vstoupili, a kdy jsme z něj vystoupili.
% Graf je ve tvaru g([seznamVrcholu],[seznamHran])

% dfs(odkud,nenavstivene,hrany,prichod,odchod,navstivene,novenenavstivene)
dfs(g(Vrcholy,Hrany),g(Navs,Hrany)) :- dfs(Vrcholy,Hrany,1,Navs).

dfs([],_,_,[]).
dfs(Vs,Hs,Prichod,N) :- member(V,Vs), delete(Vs,V,VsN), dfs(V,VsN,Hs,Prichod,Odchod,Navs,Nenavs), Odchod1 is Odchod+1,
	dfs(Nenavs,Hs,Odchod1,Navs2), append(Navs,Navs2,N).

dfs(V,Vs,Hs,P,O,[V-P-O|Navs],Nenav2) :- Vs\=[],member(V-X,Hs), member(X,Vs), delete(Vs,X,Vs1), P1 is P+1, dfs(X,Vs1,Hs,P1,O1,Nav,Nenav),
	dfs(V,Nenav,Hs,O1,O,[_|Nav2],Nenav2), append(Nav,Nav2,Navs),!.
dfs(V,Vs,Hs,P,O,[V-P-O|Navs],Nenav2) :- Vs\=[],member(X-V,Hs), member(X,Vs), delete(Vs,X,Vs1), P1 is P+1, dfs(X,Vs1,Hs,P1,O1,Nav,Nenav),
	dfs(V,Nenav,Hs,O1,O,[_|Nav2],Nenav2), append(Nav,Nav2,Navs),!.
dfs(V,Vs,_,P,O,[V-P-O],Vs) :- O is P+1,!.

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% Na vstupu dostaneme posloupnost čísel a číslo V. Máme vrátit všechny možné matematické výrazy, které 
% lze z dané posloupnosti postavit pomocí operátorů +, -, *, // a závorek, a jejichž hodnota je V. 
% Výraz musí využít všechna zadaná čísla, a jejich pořadí nesmí měnit. Dále si máme dávat pozor, abychom 
% ve výrazu nedělili nulou.

vyraz(Cisla,V,Vyraz) :- doplnOperatory(Cisla,Vyraz), vyhodnot(Vyraz,V).

doplnOperatory(Cisla,Vyraz) :- append(C1,C2,Cisla), C1\=[], C2\=[], doplnOperatory(C1,V1), doplnOperatory(C2,V2),
	append(['('|V1],['+'|V2],Tmp), append(Tmp,[')'],Vyraz).
doplnOperatory(Cisla,Vyraz) :- append(C1,C2,Cisla), C1\=[], C2\=[], doplnOperatory(C1,V1), doplnOperatory(C2,V2),
	append(['('|V1],['-'|V2],Tmp), append(Tmp,[')'],Vyraz).
doplnOperatory(Cisla,Vyraz) :- append(C1,C2,Cisla), C1\=[], C2\=[], doplnOperatory(C1,V1), doplnOperatory(C2,V2),
	append(['('|V1],['*'|V2],Tmp), append(Tmp,[')'],Vyraz).
doplnOperatory(Cisla,Vyraz) :- append(C1,C2,Cisla), C1\=[], C2\=[], doplnOperatory(C1,V1), doplnOperatory(C2,V2),
	append(['('|V1],['//'|V2],Tmp), append(Tmp,[')'],Vyraz).
doplnOperatory([C],[C]).
doplnOperatory([C],['(','-',C,')']).
doplnOperatory([],[]).

vyhodnot(['(',A,')'],A).
vyhodnot(['(',A,'+',B,')'|Res],X) :- Y is A+B, append(['(',Y|Res],[')'],V),vyhodnot(V,X).
vyhodnot(['(',A,'-',B,')'|Res],X) :- A\='(',Y is A-B, append(['(',Y|Res],[')'],V),vyhodnot(V,X).
vyhodnot(['(',A,'*',B,')'|Res],X) :- Y is A*B, append(['(',Y|Res],[')'],V),vyhodnot(V,X).
vyhodnot(['(',A,'//',B,')'|Res],X) :- B\=0,Y is A/B, append(['(',Y|Res],[')'],V),vyhodnot(V,X).
vyhodnot(['(','-',B,')'|Res],X) :- Y is (-1)*B, append(['(',Y|Res],[')'],V),vyhodnot(V,X).
vyhodnot(['(',A,Op|Res],X) :- A\='(',append(R,[')'],Res), vyhodnot(R,Y), vyhodnot(['(',A,Op,Y,')'],X).
vyhodnot(['(','('|Res],X) :- append(R,[')'],Res), vyhodnot(['('|R],Y), vyhodnot(['(',Y,')'],X).

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% Sestavte predikát termy/1, který postupně vrací termy složené z funktorů bin/2, un/1 a const/0. 
% Výstupem bude tedy korektně sestavený term. Predikát by měl postupně vrátit všechna řešení, sice v 
% libovolném pořadí, ovšem každé právě jednou. 
termy2(X) :- vsiTermy(X,1).

termy2(const,1).
termy2(un(const),2).
% termy2(bin(const,const),3).
termy2(un(X),N) :- N>2, N1 is N-1, termy2(X,N1).
termy2(bin(X,Y),N) :- N>2, N1 is N-1, soucet(A,B,N1), termy2(X,A), termy2(Y,B).

vsiTermy(X,Y) :- termy2(X,Y).
vsiTermy(X,Y) :- Y1 is Y+1, vsiTermy(X,Y1).

soucet(1,S,N) :- S is N-1.
soucet(S1,S2,N) :- N>2, N1 is N-1, soucet(Ss1,S2,N1), S1 is Ss1+1.

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% Multimnožinu lze specifikovat seznamem termů Prvek-Pocet. Sestavte predikát mensi/2, který porovná 
% multimnožiny A a B následovně: mensi(A,B) je True právě tehdy, pokud v B existuje nějaký prvek, 
% co není v A, takový, že je větší než všechny prvky z A, které nejsou v B. 
% mensi([c-3,b-2,a-1],[d-1,b-3]) True
% mensi([c-3,b-2,a-1],[c-1,b-3]) False
mensi2(A,B) :- vyhodStejne(A,B,A1,B1), member(X-_,B1), vetsiNezVsichni(X,A1).

vyhodStejne([],X,[],X) :- !.
vyhodStejne([P-R|Xs],Y,[P-R1|Xss],Yss) :- member(P-Q,Y), R>Q, delete(Y,P-Q,Ys), R1 is R-Q, vyhodStejne(Xs,Ys,Xss,Yss),!.
vyhodStejne([P-R|Xs],Y,Xss,Yss) :- member(P-Q,Y), R=Q, delete(Y,P-Q,Ys), vyhodStejne(Xs,Ys,Xss,Yss),!.
vyhodStejne([P-R|Xs],Y,Xss,[P-Q1|Yss]) :- member(P-Q,Y), R<Q, delete(Y,P-Q,Ys), Q1 is Q-R, vyhodStejne(Xs,Ys,Xss,Yss),!.
vyhodStejne([P-R|Xs],Y,[P-R|Xss],Yss) :- vyhodStejne(Xs,Y,Xss,Yss).

vetsiNezVsichni(_,[]).
vetsiNezVsichni(X,[Y-_|Ys]) :- compare(>,X,Y), vetsiNezVsichni(X,Ys).

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% Definujte predikát tranverse(+Strom,-OhodnocenýStrom), který zkopíruje strukturu stromu Strom do 
% OhodnocenýStrom s tím, že ke každému vrcholu přidá číslo N, které znamená pořadí v preOrder průchodu 
% a číslo M, které znamená pořadí v postOrder průchodu. Ideálně jedním průchodem stromem.
transverse(S,OS) :- transverse(S,0,0,_,_,OS).
%transverse(strom, tohle uz je v pre, tohle uz je v post, tady jsem skoncil v pre,tady jsem skoncil v post, vysledek)
transverse(t(L,U,P),X,Y,XN,YN,t(LL,(U,X1,YN),PP)) :- X1 is X+1, transverse(L,X1,Y,X3,Y3,LL),
	transverse(P,X3,Y3,XN,Y4,PP), YN is Y4+1.
transverse(nil,X,Y,X,Y,nil). 

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% Definujte predikát atmost2(+seznam,-seznam2), který dostane seznam ohodnocených binárních proměnných 
% a vrátí seznam všech možných ohodnocení stejných proměnných, které se od původního seznamu liší 
% v maximálně 2 proměnných.

atmost2(S,[S|NS]) :- exactly(1,S,NS1), exactly(2,S,NS2), append(NS1,NS2,NS).

exactly(N,[A-X|Xs],Z) :- N>0, length([A-X|Xs],L), N<L, switch(X,Y), N1 is N-1, exactly(N1,Xs,Xss),addToAll(Xss,A-Y,Z1),
	exactly(N,Xs,Xsss), addToAll(Xsss,A-X,Z2), append(Z1,Z2,Z).
exactly(N,[A-X|Xs],[[A-Y|Xss]]) :- length([A-X|Xs],N), switch(X,Y), N1 is N-1, exactly(N1,Xs,[Xss]).
exactly(0,X,[X]).
%exactly(0,[],[[]]).

switch(true,false).
switch(false,true).

addToAll([X|Xs],Y,[[Y|X]|Z]) :- addToAll(Xs,Y,Z).
addToAll([],_,[]).

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%  máte ČUM ([a>-b, a>-c, ...]). Vypište všechny neporovnatelné dvojice (ve formě seznamu), tzn například [b-c, ...]
mensiNez(X,Y,M) :- member(X<Y,M).
mensiNez(X,Y,M) :- member(X<K,M), mensiNez(K,Y,M).

vetsiNez(X,Y,M) :- mensiNez(Y,X,M).

neporovnatelne(M,N) :- prvky(M,MP), neporovnatelne(MP,M,N).
neporovnatelne([X|Xs],M,Vysl) :- porovnej(X,Xs,M,Xss), neporovnatelne(Xs,M,Xsss), append(Xss,Xsss,Vysl).
neporovnatelne([_],_,[]).

porovnej(X,[Y|Ys],M,[X-Y|Xss]) :- \+mensiNez(X,Y,M), \+vetsiNez(X,Y,M), porovnej(X,Ys,M,Xss).

prvky(M,N) :- vsechnyPrvky(M,MVsi), sort(MVsi,N).

vsechnyPrvky([X<Y|Xs],[X,Y|Xss]) :- vsechnyPrvky(Xs,Xss).
vsechnyPrvky([],[]).

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% Mame dany nedokonaly BVS, mame vypisat dvojice vrcholov, ktore porusuju podmienky BVS. 
% Kazdy vrchol a list ma nejaku hodnotu, co je unikatne cele cislo.
spatneDvojice(t(t(Ll,Lu,Lp),U,t(Pl,Pu,Pp)),[U-Lu,U-Pu|X]) :- U<Lu, U>Pu,!, spatneDvojice(t(Ll,Lu,Lp),X1),
	spatneDvojice(t(Pl,Pu,Pp),X2), append(X1,X2,X).
spatneDvojice(t(t(Ll,Lu,Lp),U,P),[U-Lu|X]) :- U<Lu,!, spatneDvojice(t(Ll,Lu,Lp),X1),
	spatneDvojice(P,X2), append(X1,X2,X).
spatneDvojice(t(L,U,t(Pl,Pu,Pp)),[U-Pu|X]) :- U>Pu,!, spatneDvojice(L,X1),
	spatneDvojice(t(Pl,Pu,Pp),X2), append(X1,X2,X).
spatneDvojice(t(L,_,P),X) :- spatneDvojice(L,X1), spatneDvojice(P,X2), append(X1,X2,X).
spatneDvojice(t(nil,_,nil),[]).
spatneDvojice(nil,[]).

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% Byl dán seznam objektů, kde každý objekt obsahuje dvojice klíč-hodnota. Úkolem bylo pro každý klíč vypsat jakých hodnot nabývá.
% Pokud nějaký objekt klíč neobsahuje, tak je hodnota undefined. Objekty jsou prostě seznamy.
vypisKliceHodnoty(Objekty,KH) :- vseKlice(Objekty,Klice), vypisKliceHodnoty(Objekty,Klice,KH).

vseKlice([O|Bjekty],Klice) :- klice(O,OK), vseKlice(Bjekty,BK), append(OK,BK,K), sort(K,Klice).
vseKlice([],[]).

klice([K-_|KHs],[K|Ks]) :- klice(KHs,Ks).
klice([],[]).

vypisKliceHodnoty(O,[K|Ks],[K-H|KHs]) :- seberHodnoty(O,K,H), vypisKliceHodnoty(O,Ks,KHs).
vypisKliceHodnoty(_,[],[]).

seberHodnoty([O|Bjekty],Klic,[H|Odnoty]) :- member(Klic-H, O),!, seberHodnoty(Bjekty,Klic,Odnoty).
seberHodnoty([_|Bjekty],Klic,['undefined'|Odnoty]) :- seberHodnoty(Bjekty,Klic,Odnoty).
seberHodnoty([],_,[]).

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% Na vstupu máme graf reprezentovaný jako graf(Vrcholy, Hrany) a cislo n a mame urcit, jestli v grafu existuje cyklus delky alespon n. Pokud ano, vratit ho, pokud ne, fail.

aspon2(P,V) :- aspon(2,P,V).

aspon(N,P,V) :- length(P,M), M>=N,!, presne(N,P,V1), N1 is N+1, aspon(N1,P,V2), append(V1,V2,V). 
aspon(_,_,[]).

presne(N,[K-P|Ps],[[K-R|V1]]) :- length([K-P|Ps],M), M=N, !,switch2(P,R), N1 is N-1, presne(N1,Ps,[V1]).
presne(N,[K-P|Ps],V) :- N>0,switch2(P,R), N1 is N-1, presne(N1,Ps,V1), pridej(K-R,V1,Vr1),
    presne(N,Ps,V2), pridej(K-P,V2,Vr2), append(Vr1,Vr2,V).
presne(0,X,[X]).

switch2(true,false).
switch2(false,true).

pridej(R,[S|Ss],[[R|S]|Xs]):-pridej(R,Ss,Xs).
pridej(_,[],[]).

