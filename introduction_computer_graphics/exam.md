2019-01-28
1) HSV, co znamenají jednotlivé složky? Jakých nabývají hodnot? Jaké efekty se s tím dobře dělají? Jak určíte sytost z RGB?
2) Konstrukce 3D povrchové scény. Popište, jak by vypadala datová struktura použitá pro vykreslování. Co by mělo být uložené ve vrcholech a stěnách pro vykreslování/stínování? Jak efektivně ukládat sousední vrcholy a stěny?
3) Kamera - letecký simulátor. Vyberte vhodné zobrazení kamery, jaké byste použili pro simulátor letadla. Jaké budete potřebovat parametry? Některé se budou v čase měnit, které? Co se bude dít při vykreslování?
4) volitelná otázka

2019-01-14
1) Jakou strukturu byste vytvořili pro hranu polygonu pro použití ve vybarvování po řádkách, napište v libovolném jazyce (C, Java, C#, C++)
2) Co je to anti-aliasing a k čemu je dobrý? Popište dva algoritmy, kterými by se mohl počítat
3) Popište, co byste si potřebovali ukládat u kamery při kolmém rovnoběžném promítání? Jak vypadá matice projekce tohoto promítání?
4) volitelné téma (Vyplňování souvislé oblasti: Popište záplavový algoritmus se strukturou FIFO. Proč není vhodný zásobník?)

2017-01-20
1) Co je to HDR grafika a jak se pořizuje? Jaký význam má v PC grafice a fotografii?
2) Upravte algoritmus distribuce chyby (Floyd-Steinberg) tak, aby na stejný vstup vždy nedával stejný výstup.
3) Popište algoritmus na výpočet množinového rozdílu dvou Quadtree stejné velikosti.
4) Popište Phongův model osvícení, alespoň kvalitativně. Jak spočítat stínování povrchové reprezentace hladkého tělesa?

2016-02-16
1) HSV, co znamenají jednotlivé složky? Jakých nabývají hodnot? Jaké efekty se s tím dobře dělají? Jak určíte sytost z RGB?
- 25/25 za výcuc ze slajdů 04 a 06
2) Dithering - F-S algoritmus. Popište přesně, jak funguje (možnost omezit se na odstíny šedé, 2 barvy). Jak v celočíselné aritmetice dosáhnout, aby se přenesla celá chyba?
- 25/25 za popis a obrazek, ani jsem nemel spravne zlomky. Na celociselnost se to vhodne vynásobí.
3) Konstrukce 3D povrchové scény. Těleso je složené z trojúhelníků, popište, jak by vypadala datová struktura použitá pro vykreslování. Co by mělo být uložené ve vrcholech a stěnách pro vykreslování/stínování? Jak efektivně ukládat sousední vrcholy a stěny?
- na 24/25 stačilo vzpomenout si na úlohu 57 a extrapolovat, ten jeden bod dolu byl za to, ze mi nedošlo, že trojuhelnik bude vždy mít 3 sousedy (pozor, neplatí pro vrcholy)
4) Kamera - letecký simulátor. Vyberte vhodné zobrazení kamery, jaké byste použili pro simulátor letadla. Jaké budete potřebovat parametry? Některé se budou v čase měnit, které? Co se bude dít při vykreslování?
- MUSÍ se použí panoramatická, pak stačí popsat co je na slajdech.
... pokud komplet správně popíšete rovnoběžnou, dostanete něco jako 8 bodu O:-)

2015-02-23
1) Napsat deklaraci struktury pro hranu (+ krátké komentáře co je co) v algoritmu vyplňování n-úhelníka.
2) Anti-aliasing.
3) Napsat půltónovací matici pro 51 odstínů. Má být čtvercová, důležité popsat postup, nemusí tam být celá matice napsaná.
4) Rovnoběžná kolmá projekce. Jakými daty reprezentovat kameru? Jak vypadá transformační matice.

2015-01-09
1) Napiště datovou strukturu, kterou byste reprezentovali hranu v řádkovém algoritmu pro vyplňování n-úhelníku. Použijte jazyk z množiny {C, C++, Java, C#}. Berte v úvahu dva obvyklé druhy vyplňování, každý parametr stručně popište.
2) Co je to anti-aliasing, k čemu se používá? Popište základní principy použité při anti-aliasingu (ne konkrétní algoritmy).
3) Napište půltónovací matici pro ČB laserovou tiskárnu o 51 odstínech.
4) Jak byste reprezentovali kameru pro rovnoběžnou kolmou projekci (ortogonální)? Jak byste přišli na matici projekce této kamery (nebo tak něco)?

1) struct Edge { real x, int y, int dy, real dxy },
x: x-souřadnice prvního bodu hrany a při běhu algoritmu průsečík s moentální řádkou
y: y-souřadnice prvního bodu hrany
dy: y-rozdíl mezi prvním a druhým bodem hrany (y2 - y1)
dxy: o kolik se změní x při přechodu z y na y+1 (na další řádku), vypočítá se jako (x2 - x1) / dy
[25/25]

2) Antialiasing je metoda, která se používá pro zlepšení vizuálních vlastností objektů vykreslených na obrazovce (čar, polygonů, písma).
Funguje jako vykreslování všech pixelů, které objekt překrývá, a používá více odstínů barvy (například: odstín odpovídá procentu zakrytí pixelu).
[18/25] - Myslím, že jsem tam toho moc víc nepsal, nějaké věci kolem, asi mu tam něco specifického chybělo.

3) jelikož jde o laserovou tiskárnu, musí se použít bodový rastr, při pravidelném inkrementálním by se rozpíjely kapky.
Jelikož chceme 51 odstínů, máme 1 odstín bílý a 50 odstínů barvy, to odpovídá matici 10x10, kde pro každý odstín přidáme dva pixely (nejdřív do levé-horní a pravé-spodní poloviny kde tvoříme kruhy, a poté jakoby zmenšujeme invertovaný kruh v pravé-horní a levé-spodní polovině). Přesně tenhle příklad je ve slajdech, nakreslil jsem odstíny 1,3,25,45,50.
[25/25]

4) kameru budeme reprezentovat pomocí:
S: rovina průmětny
N: vektor kolmý na průmětnu
u: svislý vektor
Na matici transformace bych přišel tím způsbem, že bych vektor N sjednotil s osou z a vektor u sjednotil s osou x, pomocí operace Cs(S,uxN,u,N).
Matice bude 4x4, neboť se použijí homogenní souřadnice (x,y,z,w)
[25/25]
