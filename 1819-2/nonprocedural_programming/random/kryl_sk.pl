muz(adam). % Tam vám byl jeden muž Adam
manz(adam,eva). % ti dva byli manželé.
rodic(adam,josef). % Adam byl rodičem Josefa
rodic(adam,hugo). % a Huga.
rodic(eva,josef). % Rodičem Josefa byla i Eva,
rodic(eva,hugo). % zrovna tak byla i rodičem Huga.

muz(karel). % Byl tam i další muž, jmenoval se Karel,
zena(helena). % a žena Helena.
manz(karel,helena). % Ti také byli manželé.
rodic(karel,zuzana). % Karel byl rodičem Zuzany,
rodic(helena,zuzana). % i Helena byla jejím rodičem.
rodic(helena,alfred). % Helena byla i rodičem Alfreda
rodic(karel,alfred). % a Karel taky.

zena(klara). % Byla tam i žena Klára,
rodic(klara,emil). % která byla rodičem Emila,
muz(emil). % což byl muž.
rodic(karel,emil). % Rodičem Emila byl i Karel

zena(kunhuta). % Byla tam i žena Kuhnuta,
manz(zibrid,kunhuta). % jejíž manželem byl Žibrid.
muz(zibrid). % Byl to muž.
rodic(kunhuta,eva). % Kunhuta byla rodičem Evy
rodic(kunhuta,katka). % a Katky.
zena(katka). % Katka byla žena.
rodic(zibrid,eva). % Rodičem Evy
rodic(zibrid,katka). % a Katky byl také Žibrid.

zena(ruzena). % Žena Růžena
rodic(ruzena,jan). % byla rodičem Jana.
manz(jan,lucie). % Jan byl manželem Lucie.
muz(jan). % Jan byl muž
zena(lucie). % a Lucie žena.
rodic(jan,adam). % Oba byli
rodic(lucie,adam). % rodiči Adama.

muz(jose). % Muž José
manz(jose,katka). % byl manželem Katky.

otec(O, X) :- muz(O), rodic(O, X).
matka(O, X) :- zena(O), rodic(O, X).
deda(D, V) :- otec(D, R), rodic(R, V).
sestra(A, B) :- zena(A), rodic(X, A), rodic(X, B), A \= B.
teta(T, X) :- sestra(T, R), rodic(R, X).
manzF(A, B) :- manz(A, B); manz(B, A).
zenaty(X) :- manz(X, _).
tchyne(T, C) :- matka(T, J), manzF(J, C).