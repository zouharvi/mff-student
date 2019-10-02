# A) JavaScript
## Historie
- Rychle navrhnutý jazyk, který měl sekundovat Javě (amatérské skriptování/velké komerční systémy)
- Potřeba JavaScript engine
- ECMAScript, TypeScript (2012)
- Postupně se napojilo čím dál tím víc funkcionalit (nyní lze získat přístup ke kameře) a na webovou Javu se zapomnělo.
- - Za to možná může licensování, neboť pro webovou Javu je třeba plugin, zatímco JavaScript je "nativně" podporován.

## Proč se používá
Je lehký, nemá pokročilé dekorace. Kód lze psát skoro kamkoliv. Snadno na naučení - jde ruku v ruce s designem HTML.
Ideální na prototypování - velké projekty pozor.
Nemá žádný unifikovaný standard kódu, což je velký kontrast např. proti Javě, která má toto jako hlavní přednost.
Jazyk sám o sobě není nějak extra zajímavý. Důležité jsou technologie, které jej obklopují.

Podobně jako Java běží na virtuálním stroji, tedy uživateli nevadí, že na jeho stroji běží cizí kód, protože
může poškodit nejvýše samotný sandbox (tj. stránka).

## Rysy/paradigma
Imperativní interpretovaný vyšší úrovně. Má několik typů (pole čehokoliv, číslo, řetězec, bool, null, undefined, objekt),
ale samotná implementace uživatele vůbec nezajímá.

Jistým způsobem se dá v JavaScriptu programovat objektově (za pomocí prototypů), ale je dovolený také funkcionální přístup (funkce je obyčejný volatelný objekt, který může mít vlastní proměnné apod). Ta objektovost je v JavaScriptu spíše dekorativní. Rozhodně se tam nenajde žádné RAII.
I přesto, že obsahuje klíčové slovo _class_, tak to je jen syntaktická vrstva nad prototypem.

Jelikož je to otevřený interpretovaný jazyk, má občas bizarní problémy, jako například že volání funkcí s dlouhým jménem trvá déle než s krátkým.
Slouží zejména pro skriptování webů, proto obsahuje funkce určené přímo pro editaci stránkového DOM. V dnešní době se však používají různé knihovny, které tuto práci usnadňují. Známé jsou jQuery, Angular a Vue, ale každý rok vyjde něco nového.

Funkcionální rysy využívá třeba pro event driven programování, což je v prostředí uživatelského rozhraní na stránce přirozené.

## Ptakopět
### Alternativy
- nativně (dnes archaické)
- pomocí HTML forms (též archaické)
- za pomocí pure JavaScriptu (pomalejší prototypování, používáme jQuery)
- za pomocí Dartu (zbytečně velké)
- za pomocí TypeScriptu (v plánu, sníží se tím technický dluh)
- za pomocí nějaké knihovny (každý rok vychází nějaká nová, zbytečné přepisování)


# B) Obecné otázky
1. Vývoj programovacích jazyků
- FORTRAN
- Algol 60
- PL/I
- Algol 68
- Pascal
- Simula 67
- Ada
- C a C++
- Java
- APL
- Python
- LISP
- Haskell
- Prolog

2. Programovací styly
- strukturované
- modulární
- objektové programování
- event-driven

4. Datové typy a datové  abstrakce, generické typy

5. Řídící struktury programovacích jazyků

6. Struktura programovacího jazyka:
- proměnné, jejich hodnoty, typy, definiční oblast, životní cyklus
- překlad a interpretace programovacího jazyka, separátní překlad

7. Podprogramy a předávání parametrů

8. Zpracování výjimek

9. Objektové programování.
- zapouzdření
- dědičnost (jednoduchá, vícenásobná a problémy, které přináší),
- polymorfismus
- virtuální metody a způsoby jejich implementace
- konstruktor, destruktor
- „metody tříd“.
- ochrana atributů tříd.

11. Procedurální a neprocedurální programování, logické a funkcionální programování, lazy vyhodnocování.
