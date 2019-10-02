# 01_uvod
soubor aktiv
expozice - místo potenciálního poškození
zranitelnost
hrozby

naplnění hrozby - dopad
rizika - rozsah hrozeb + pravděpodobnost jejich realizace
očekáváná ztráte 


cíl je minimalizovat náklady na
- investice
- provozní náklady
- očekávané ztráty

security policy - kdo je za co zodpovědný, jaké okruhy se řeší

realizace, provoz, monitorování, aplikace změn, verifikace, audit, ..

možné hrozby
- přerušení
- zachycení
- modifikace
- fabrikace
- ...

zdroje
- přírodní
- závady hw
- neúmyslné lidské chyby
- záměrné útoky

klasifikace útočníků
..

# 02_normy_modely
potřebujeme normy pro jednotná kritéria, abychon na nic nezapomněli, usnadňují audity

formální verifikace - bezpečnost převedena na soustavu logických formulí
validace - obecnější metoda
- testování požadavků - testuje, zda je splněn každý z požadavků na funkčnost systému
- kontroly návrhu a kódu
- testování modulů a celého systému - na zkušebních datech
tiger team penetration team - třetí strana pověřená proniknout bezpečnostními mechanismy

pokud systém obstojí při validaci, může mu být vystaven certifikát, který je formálním vyjádřením s požadavky příslušné normy

zdroje požadavků na bezpečnost
- zákony
- oborové normy/standardy
- vnitrofiremní směrnice
- požadavky obchodních partnerů
- ...

Orange book (TCSEC)
- tvůrcem je ministry of defense US 
- první ucelená technická norma
- čtyři základní třídy
- D - žádná ochrana 
- C - optional protection - uživatel může použít příslušný mechanismus
- C1 - volná ochrana - oddělení uživatelů od dat
- C2 - kontrolovaný přístup
- - každý uživatel oddělen
- - rezidua (obsah paměti, registrů) poté, co je systém přestane používat, nesmí být zpřístupněna
- - musí být vede access log
- B - mandatory protection - uživatel nemůže obejít ani deaktivovat
- B1 - značkovaná ochrana
- - každý subjekt má stupeň utajení
- - každý přístup dle Bell-LaPadula modelu
- B2 - strukturovaná ochrana
- - verifikovaný globální návrh systému
- - rozdělení do nezávislých modulů
- - nejmenší možná oprávnění
- - analýza možných skrytých kanálů
- B3 - bezpečnostní domény
- - podrobení extenzivnímu testování
- - úplný popis celkové struktury návrhu systému
- - koncepčně jednoduchý
- - kontrola na úrovni provádění jednotlivých typů přístupu
- A1
- - návrh systému je formálně verifikován
- - - existuje formální model s důkazem konzistentnosti, ověřením, že odpovídá danému systému, že implementace je shodná se specifikací
- - formální analýza skrytých kanálů


ITSEC
- nadmnožina TCSEC
- kritéria rozdělena do funkčnosti (F) a korektnosti (E)
- třídy funkčnosti cca odpovídají TCSEC
- funkčnost hodnocena v
- - integritě systému (F-IN)
- - dostupnosti systémových zdrojů (F-AV)
- - integritě dat při komunikaci (F-DI)
- - utajení komunikace (F-DC)
- - bezpečnosti v rámci celé sítě (F-DX)
- každá nezávisle na ostatních
- korektnost (C2 - A1 v TCSEC)
- - E1 - testování
- - E2 - kontrola konfigurace a distribuce
- - E3 - ověření návrhu a kódu
- - E4 - analýza slabin systému
- - E5 - důkaz, že implementace odpovídá specifikaci
- - E6 - formální modely (formální popis a vzájemná korepondence)

Common criteria
- metanorma stanovující princip a postup jak odvozovat technické normy pro vývoj, testování a provoz
- evaluační kritéria -> evaluační metodologie -> evaluační schéma -> evaluace -> výsledky -> certifikace -> registr certifikátů
- oddělení functional requirements od assurance
- functional třídy
- - TODO:
- assurance třídy
- - TODO:
- vyhodnocení kvality bezpečnostního mechanismu
- - TODO:
- assurance level
- - TODO:

ISO 27000
- soustava norem pro zajištění bezpečnosti IS
- dlouhý seznam

BS7799 (ISO IEC TR 17799, ISO 2700x)
- popisuje jaké činnosti musí organizace vykonávat pro bezpečnost IS
- nespecifikuje přímo kvalitu
- bezpečnost shora dolů (politika -> implementace)
- standardní metodika a automatizovaný nástroj CRAMM
- obrázek 02_normy_modely/7
- pokrývá tyto oblasti
- - TODO:

standardy PKCS
- ucelený soubor technických norem popisující impementaci nástrojů asymetrické kryprografie
- v laboratořích RSA Security

zdroje standardů
- základní české standardy - zákon o kybernetické bezpečnosti
- mezinárodní standardizační instituty
- - ISO, IEC, ITU, WSSN
- regionální
- - CEN, CENELEC, COPANT, ETSI

formální modely bezpečnosti


# 03_autentizace
bezpečnost lze rozdělit na
- kontrola prostředí
- autentiace / identita
- autorizace
- separace
- - fyzická
- - časová
- - logická
- - kryptografická
- integrita
- dostupnost
- audibilita
  
autentizace
- zjištění/ověření identity subjektu
- identifikátory: jméno, userID, rodné číslo, ..
- primární identifikující dokumenty: op, pas, úřední dokumenty s fotkou
- sekundární identifikující dokumenty: směnka, výplatní páska, ..
- identifikující charakteristika: biometrika, fotografie
- entita: bytost, místo, věc

registrace
- iniciální přiřzení identifikačních dokumentů entitě

identita uživatele
- struktura označovaná jako profil
- userID, heslo
- jméno, příjmení, tituly
- certifikáty, klíče
- oprávnění

pojmy: alias, anonymita, pseudonymita

autentizace protistrany
- co ví pouze dotyčná osoba
- - heslo, pass-phrase, šifrovací klíč
- co vlastní
- - token, schopnost, znalost
- schopnost provést operaci
- - cosi charakteristického
- - biometrika

heslo
- není omezeno jen např. na malá písmena a čísla
- dostatečná délka
- není známou frází
- nepravděpodobné, nelze odvodit ze znalosti osoby vlastníka
- často obměňované
- není po okolí poznamenané

passphrase
- velmi dlouhá hesla, třeba citát z knihy

skupinová hesla
- zná celá skupina
- bývají často vyzrazena

PIN
- číselné řetězce standardní délky

Challenge-response systémy
- heslo zachyceno v průběhu vkládání
- např. systém zašle náhodnou zprávu a uživatel ji zašifruje klíčem a pošle zpět

jednorázová hesla

vícefaktorová autentizace
- kombinace několika autentizačních postupů
- několik nezávislých mechanismů aplikovaných paralelně, nebo sériově

výměna taností
- protokol pro případ, že komunikující strany nedůvěřují okolí a nechtějí vyzrazovat identitu
- pokud sdílejí/nesdílejí tajný klíč
- TODO:

asymetrické klíče
- ověřovatel zašle dokazovanému náhodně volený řetězec
- dokazovaný jej transformuje za použití soukromého klíče
- ověřovatel pomocí veřejného klíče ověří správnost

symetrické klíče
- podobný princip

passphrases
- dlouhá hesla, součást písní, básniček
- lehce zapamatovatelná
- lze aplikovat další měření (např. rytmus stisku kláves bývá charakteristický)

tokeny, smart cards
- token je předmět, který autentizuje svého vlastníka
- musí být jedinečný a nepadělatelný
- magnetické/čipové karty
- pokud má vlastní výpočetní kapacitu, pak smart card
- pouze s pamětí
- - obdoba mechanických klíčů
- udržující hesla
- - po zadání hesla vydá určený kvalitní klíč, který udržuje
- s logikou
- - umí zpracovávat jednoduché podněty, např: vydej následující klíč
- - lze realizovat one time hesla
- smart cards (inteligentní tokeny)
- - mohou např. generovat náhodná čísla
- - lze nimi doplnit challenge-response systémy

biometriky
- identifikace lidí na základě jejich osobních charakteristik
- navzájem různé mírou spolehlivosti, ceny a společenskou přijatelností
- ideální velká mezi-osobní variabilita a dobrá vnitro-osobní reproducibilita
- četnost false negatives
- četnost false positives (útok)

verifikace hlasu
- subjekt přečte systémem náhodně zvolenou frázi
- proveden rozbor zvuku
- snadné využití (i např. pomocí telefonu)

verifikace dynamiky podpisu
- sledují se změny tlaku, zrychlení v čase, celková dráhá, apod..
- výhodou je přirozenout a sociální akceptovatelnost
- nevýhodou je variabilita podpisu u lidí

verifikace otisků prstů
- statistický rozbor výskytu markant (hrboly, smyčky, spirály)
- dobrá mezi-osobní variabilita a vnitro-osobní reproducibilita
- občas sporná spolehlivost snímačů

geometrie ruky
- metoda zkoumá délku a šířku dlaně a jednotlivých prstů, boční profil ruky apod..
- spolehlivá, ale drahá
- možnost podrstření podlitku ruky

obraz sítnice
- zařízení pořídí obraz struktury sítnice v okolí slepé skvrny
- velmi obtížná napodobitelnost
- drahá věc, osobně možná nepříjemné

další biometriky
- rysy obličeje
- otisky chrubu, genetické rozbory

# 04_autorizace
úrovně
- žádná (nebo samovolná časová separace)
- izolace (procesy vůbec o sobě nevědí)
- sdílení všeho nebo ničeho
- sdílení s omezenými přístupy (přístupy jsou spravovány)
- sílení podle způsobeilosti (rozsah může dynamicky záviste na kontextu)
- limitované použití objektu (specifikuje i různé druhy operací, které může přistupovatel vykonávat)

granularita
- kontrola přístupu může být na různých úrovních

objekty ochrany
- systémové zdroje
- data na systému
- datové struktury
- služby

cíle ochrany objektů
- kontrola každého přístupu 
- povolení co nejmenších práv
- ověření správného používání
- omezení rozsahu používání

mechanismus ochrany obecných objektů
- rozhodovací algoritmus
- autorizační data

adresář
každý uživatel má práva k nějakému souboru (speciálně vlastník), tato práva jsou popsána v adresáři každého uživatele
žádný uživatel nemá práva na adresář uživatele

seznam oprávnění
každý objekt má vedle sebe seznam informací, které subjekty k němu mají opravnění
lze např používat regexy na označení práv

přístupová matice
řádky jsou subjekty, sloupce objekty, číslo určuje druh práva
velmi řidká a velká

způsobilost
nefalšovatelný token
třeba seznam způsobilostí každého běžícího procesu (v chráněné paměti)

security label
každý subjekt má bezpečnostní label popisující pověření/klasifikaci

procedurálně orientovaný přístup
subjekty mají práva/nepráva k funkcím z rozhrání, prostřednictvím kterého je objekt zpřístupňován
ztráta efektivity, ale podporuje zapouzdřování

## granularita autorizace
ochrana po skupinách
každý objekt má práva pro vlastníka, skupinu a okolní svět

hesla a tokeny
při vytvoření vlastník specifkuje hesla potřebná pro jisté módy přístupu
hesla jsou zaslána uživatelům
je náročné udržovat a spravovat hesla (vystavit nové, zinvalidovat subjekt apod..)

dočasné propůjčení oprávnění
stejně jako ochrana po skupinách, ale lze nastavit, zdali se soubor spouští s oprávněním vlastníka
lze tak zprostředkovaně přistupovat k prostředkům, ke kterým původní subjekt nemá právo
o něco náročněji implementovatelné a těžko se spracuje

VAX VMS/SE
každý soubor má seznam oprávnění udávající kdo má jaká práva

systém rolí a skupin
oprávnění jsou sdružována do ucelených souhrnů - rolí, které odpovídají svým obsahem okruhu práce, kterou vykonává pracovník
uživatel nezískává oprávnění "po jednom", ale přidělením role
lze role stavět hiearchicky pro snazší spravování

referenční uživatelé
předpřipravené vzory častých typů uživatelů
usnadňují správu

# 05_metody_fyzicke_ochrany
snaha eliminovat hrozbu ještě dříve, než přijde do kontaktu se systémem

## přírodní katastrofy
celkově je dobré mít označené důležitosti komponent systému pro dobrou strategii
záplavy - stoupající voda, většinou lze v mezičase přesunout alespoň data
požáry - ohrožení i pro personál
ztráta napájení
- je třeba zajistit alternativní zdroje energie, akumulátory a UPS zdroje
- důležité také filtry a přepěťové ochrany před blesky apod
chlazení - některé komponenty jsou citlivé na teplo
hmotnost - některá technika vyžaduje podlahy se zvýšenou nosností
prašnost, vibrace, další vlivy

## prostorová ochrana
prostředky zabraňující útočníkům ve vstupu do prostor systémů/výnosu komponent

stráže - musí znát všechny pracovníky, nebo schopna ověřit, třeba tokenem
elektronická prostorová ochrana
- dveřní a okenní kontakty detekují otevření
- otřesové hlásiče, vodičové desky, drátěné sítě - detekují rozbití nebo proražení střežené plochy
- kontaktní matice - instalovány pod podlahu, detekují vstup
- mikrovlnné, ultrazvukové a infračervené detektory - ragují na změnu/přeručení svazku příslušného záření
- zvukové a kyvadlové hlásiče

detekce výstupu - třeba v obchodních domech, komponenty mají tagy/nálepky

likvidace médií se senzitivními informacemi
zkartovače - liší se jemností
přepisování magnetiký médií - lze přepas na nuly, není ale 100% spolehlivé
degaussery - vygenerováním silného elektromagnetického pulzu zničí původní pole, není ale 100% spolehlivé

odpovědnost za zabezpečení
- odpovědnost za návrh bezpečností strategie
- odpovědnost za dodržování návrhu
- důležité jsou opakované namátkové kontroly

elektromagnetické vyzařování
- lze z toho odvodit nějaké informace (monitor, vodiče)
- nelze kriminalizovat
- řešení:
- - vzdálenost
- - zmatení - posílat fuzzy signály
- - speciální vynutí
- - vhodné umístění do stíněných prostor

obnova provozu - dostupnost
účinné zálohování je součást bezpečnostní strategie
agilní zotavení z chyb
archivní kopie různých stádií projektu

zálohy na nejrůznější zařízení
samotné zálohy ve standardním formátu
verifikace vytvořené záložní kopie
komprese a deduplikace ukládání dat (rychlost a menší objem dat)
kryptografická ochrana dat (jinak vulnerable)
snadno specifikovatelné kdy zálohovat
SW pro zálohu musí být opravdu otestován

záložní média
výměnné - usb disky, pásky, worm disky, hard copy
další:
disky (disk mirroring - zápisy na jednom disku jsou automaticky duplikována)
duplexing - dva stroje mají přesně stejný obsah paměti a synchronně provádějí veškeré operace (při výpadku jednoho pokračuje druhý)
síť - zálohování je kopírováním na další počítač v síti (je třeba zajistit bezpečnost a flexibility zotavení)

zálohy hardware
- je nutné mít záložní systém, nebo alespoň kritické nahraditelné součástky

zásady pro pořízování záloh
- závisí na situaci a cejména na objemu dat

ztráta dat - velmi problematická, neboť znovupořízení může být náročné
ztráta software
- je zpravidla možno znovu nainstalovat, ale je nutná opětovná konfigurace 
- konfigurační soubory by tedy měly být zálohovány

pokud je místo a čas, je dobré provádět zálohu všech dat a programů
dříve Grandfather-Father-Son, nejnovější vždy přepisoval nejstarší
nyní se však zálohuje jen konkrétní část (databáze, OS, aplikace, ..)
četnost je úměrná důležitosti

důležité milníky záloh by měly být uloženy na bezpečných místech

## plány kontinuity
organizace musí mít připravené postupy pro případ haváre po dobu bez
- podpory informačního systému
- vlastního zaškoleného personálu
- komunikace
- provozních prostor ..
čím déle vydrží, tím je snazší připravit a provozovat odpovídající prostředky pro obnovu

plán obnovy - pro případ poruchy je třeba mít vypracované a otestované procedury 

obnova provozu
- občas velmi kritické znovu obnovit výpočet
- výrobci většinou rychle dokáží dodat nový systém během dne
- cold site
- - zařízení vybavené zdroji, klimatizací, komunikacemi apod
- - je třeba přinést systém
- hot site
- - už obsahuje systém
- - je třeba jen přinést zálohu dat a programů
- clustery
- - redundance na úrovni funkčních jednotek (serverů, systémů) zajišťující automatické přenesení výpočtu na zbylé kapacity
- mirroring - online redundance na úrovni datových úložišť
- zálohy 

ZVČ: při větším množství zařízení se musí počítat s chybami (např. Google s miliony HDD)

# 06_programy
trapdoors - nedokumentovaný vstup do prgramového modulu (obvykle debug mód)
trojan horses - program vykonává navíc i zákeřné věci
salami attack - využívá zaokrouhlovacích chyb, těžko detekovatelné

skryté kanály (covert channels)
- výnos informací
- fake chyby ve výpisech
- vznik systémových událostí
- nepatrné změny frontendu

exploits
- známé slabiny programů
- existuje spousta nástrojů pro detekci podmnožiny

## proti dosažitelnost služeb systému
hladové programy, DOS útoky
- mohou generovat velké množství synovských procesů
- mohou běžet v nekonečné smyčce
- spousta těžkých IO operací (i síťových)

viry
- malý program s autoreprodukční schopností
- často nahrazuje část jiného programu
- obsahují mechanismy proti detekci
- po určitou dobu vykonávají pouze reprodukci
- prevence je oddělení systémů, aby nemohlo dojít k přenosu

worms
- síťová obdoba virů, mají schopnost se šíři pomocí sítě
- prevence je patřičné rozdělení, používání pouze testovaného sw

## metody vývoje
modularita, zapouzdření, ukrytí informací
- rozdělení na nezávislé moduly (microservices? :^) )
- pořádně zdokumentované rozhrání

nezávislé testování - nezávislý tým

správa verzí a konfigurací
- zabraňuje úmyslným změnám odzkoušených programů (vkládání trapdoors)
- zabraňuje ztrávtám předchozích verzí software
- odstraňuje komplikace při vývoji více verzí
- mechanismus pro kontrolované sdílení modul (prostě version control)

spolehlivý software
- program je funkčně korektní, pokud vykonává správně všechny očekávané funkce a nic víc
- spolehlivý sw (trusted) jsou programy, které jsou funkčně korektní a vyžadují to i u modulů, které spouštějí
- operační systém by měl být spolehlivý sw

spolehlivé programy
- funkční korektnost
- zajištění integrity - zachová korektnost dat i při špatném vstupu 
- omezená práva - pokud má přístup k utajovaným datům, minimalizuje kontakt
- zajišťuje přístup k citlivým datům pro obecně nespolehlivé uživatele, kterým není možné dát přímý přístup

vzájemné podezřívání (mutual suspicion)
- předpokládat, že ostatní programy jsou hloupé
- nevěřit, že předávají korektní vstupy
- komunikace pouze poocí dobře chráněného rozhrání

omezení (confinement)
- podezřelý program má přísně vymezeno, jaké systémoé zdroje smí používat (sandbox)
- Windows _runas_, UNIX _chroot_

parcelizace informací (information comparement)
- veškerá data a programy v systému jsou rozdělena do několika oblastí
- každý program může pracovat s daty z nejvýše jedné oblasti, do které sám patří

access log
- vše logovat (co, kdo, kdy, jak dlouho, s čím)
- zaznamenávat zejména chyby a pokusy o nepovolené přístupy

## administrativní nástroje ochrany
není fajn dávat programátorům úplně volnou ruku, neboť kód musí být verifikovatelný, udržovatelný apod
standardní návrh - obvykle seznam povolených vývojových prostředků, jazyků a metodologií
standardy pro tvorbu dokumentace, stylu kódování, pojmenování proměnných apod
standardy programování - programování ve větším měřítku, systém peer reviews, audity
standardy testování - verifikační metody, archivování výsledků testů
standardy konfiguračního managementu - způsoby výměny produktů, zaznamenávání změn apod

dodržování - bez toho nemá smysl
- klíčové momenty tendence porušení pravidel jsou při zpoždění projektu a odchodu klíčových pracovníků

pokud programátor očekává, že neznámý člověk bude testovat jeho kód, snaží se víc

charakter přijímání pracovníků
- podstatné jsou reference z předchozích pracovišť, psychologické testy apod
- až postupně získává důvěru a větší a větší přístup

sledování pracovníků
- dobré mít ponětí o extrémních a finančních aktivitách

## verifikace a validace software
cíl je důkladná analýza a testování
provádí se v průběhu a po dokončení díla
nezávisle na vývoji po stránce
- technické - jiní lidé než vývojáři
- řídící - tým si sám volí co testuje
- finanční - tým musí být zodpovědný pouze za testování, nikoliv za funkčnost projektu

řízení v&v
- pareto efekt - 20% chyb spotřebuje 80% nákladů na předělávky
- je dobré mít analýzu hazardů a kritických sekcí

aktivity v&v
- validace požadavků - zdali nejsou v rozporu s platnými standardy, nejsou vnitřně sporné
- v&v návrhu sw - ověřit, že návrh splňuje požadavky
- v&v kódu - ověřit, že kód implementuje návrh
- testování (modulů, integrace, systému, instalace)
- v&v při správě a používání sw

TODO: table

v&v techniky
- statické - přímo zkoumají struktury a formu produktu bez jeho spuštění (reviews, inspekce, data-flow)
- dynamické - analýza výsledků zkušebních běhů a simulací
- formální - matematická analýza

analýza algoritmů
analytické modelování
back-to-back testing
analýza mezních hodnot
čtení kódu
analýza toku řízení
analýza pokrytí
kritická analýza
databázová analýza
analýza toku dat
rozhodovací tabulky
desk checking
error seeding
event tree analysis
konečné automaty
funkční testování
inspekce
analýza rozhraní
testování rozhraní
analýza mutací
testováí výkonu
petriho sítě
důkaz korektnosti
prototypování
regresní analýza a testy
procházení požadavků
reviews
sensitivity analysis
simulation
sizing a analýza časování
slicing
chybový mód, efekty, kritická analýza
analýza chybných stromů
stress testing
strukturální testování
symbolické spouštění
certifikace testů
procházky

v&v pro znovupoužitý SW
- analýza konzistence
- analýza rozhraní

specifické pro báze znalostí
- alternativní model
- control groups
- analýza kredibility
- field testing
- testování nepovolených atributů
- logická verifikace
- meta modely
- partition testing
- verifikace pravidel
- statická validace
- turingův test
- weight analysis

# 07_osy
chráněné objekty
- procesor
- paměť
- spustitelné programy
- sdílená zařízení typu sidky
- sériově znovupoužitelná zařízení - tiskárny, pásky
- sdílená data

poskytované služby
ochrana procesoru
metody ochrany objektů v operačních systémech

ochrana paměti a adresování
- ohrada (fence)
- relokace
- base/bound registry
- značkovaná (tagged) architektura
- segmentace
- stránkování

ochrana obecných objektů
- seznam
- cíle

autentizace subjektů
- hesla
- - hledání hesel
- - - textové soubory
- - - zašifrované soubory
- - - one time passwords

návrh bezpečných OS
- autentizace uživatelů
- ochrana paměti
- řízení přístupu k souborům a IO
- alokace a řízení přístupu k obecným objektům
- zabezpečení sdílení
- zabezpečení spravedlivého přístupu
- meziprocesorová komunikace a synchronizace

namátkou
- virtuální adresní prostor
- virtual machine
- kernel
- vrstvový model
- kruhová struktura

průniky OS
- TODO

problémy virtualizace

# 08_databaze
fyzická integrita
logická integrita
elementární integrita
auditabilita
kontrola přístupu
autentizace uživatelů
dostupnost

integirta
- dvoufázový update
- třífázový update
- redundance/vnitřní konzistance
- - detekční a samoopravné kódy
- - stinné záznamy

zotavení
paralelismus/konzistence
monitory

porovnání mezí
stavová omezení
tranzitivní omezení

senzitivní data
rozhodování o přístupu
- dostupnost dat
- akceptovatelnost přístupu
- zajištění autenticity

vyzrazení dat
- přesné hodnoty
- meze
- negativní výsledek
- existence
- pravděpodobné hodnoty
- součet
- počet
- medián

bezpečnost vs. přesnost
problém odvoditelnosti
přímý ptok
nepřímý útok
tracker attack

ochrana odvoditelnosti
- potlačení malých výsledků
- kombinování výsledků
- modifikace výsledků
- náhodný šum
- nýhodný výběr (random sample)
- náhodné zmatení

víceúrovňové databáze
- parcelizace
- šifrování
- integrity lock
- spolehlivý frontend (guard)
- komutativní filtr
- pohled (view)

bezpečnost v aplikačních serverech


# 09_site
- sdílení
- složitost
- neznámý perimetr
- množství zranitelných míst
- neznámá cesta

ochrana komunikace
- proud dat
- jednotlivé zprávy

šifrování na úrovni linky
end to end šifrování
kontrola přístupu
- ochrana komunikačních portů (port protection)
- automatické zpětné volání
- odstupňovaná přístupová práva
- tichý modem (silent modem)

řízení přístupu z vnějšího prostředí
parcelizace vnitřní sítě

autentizace uzlů

autentizace v síti
- cookies
- tickets
- certifikáty, PKI
- čipové karty
- tokeny

aktivní útočník
- playback starých zpráv
- narušení služeb
- vkládání poškozených zpráv

řízení zátěže
- vycpávací zátěž (analýza zátěže)
- kontrola routování
- další metody..

integrita dat
lokální sítě

víceúrovňová bezpečnost
spolehlivé síťové rozhraní (trusted network interface)
bezpečná komunikace
- kabely
- mikrovlny
- satelitní přenos
- celulární radio
- analogové sítě
- - X.25
- - ISDN
- - MPLS
- - pevné linky
- - X.400 message handling
bezpečné síťové spojení