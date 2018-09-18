
## Obecné
Projekt ZimaDB si klade za cíl implementovat podmnožinu funkcionality SQL compliant engine, konkrétně SQLite.

### Datové typy
- BOOLEAN
- [UNSIGNED] INT, TINYINT
- VARCHAR(N)
- DOUBLE
- DATE (není součástí specifikace)
- BLOB(N) (není součástí specifikace)
- atribut PRIMARY

### Povolené operace
- SELECT, INSERT, UPDATE, DELETE, CREATE TABLE
- agregační funkce, ani výrazy nejsou pro složitost povoleny, stejně jako vnořený SELECT
- - při studiu této problematiky se ukázalo, že implementace by vyžadovala použití virtual views a celkově by byla příliš složitá na rozsah tohoto projektu 
- JOIN (implementován pro začátek jako multiple select + podmínky, při volných prostředcích přidáno syntakticky jako JOIN ON)

### Další
- Je možné vybírat s příznakem DISTINCT
- Podporováno je i ORDER BY

## Vývoj
Součástí projektu jsou následující položky:

- návrh projektu
- vývoj 
- - project stub, build system
- - compiler
- - - tokenizer
- - - parser
- - - grammar
- - - core interface
- - core
- - - scheduler
- - - processor 
- - backend
- - - návrh formátu souboru
- - - b-trees
- - - pager
- - - system handling
- - utilities
- dokumentace

Rozdělení práce následující:
- Petr
- - backend
- - processor
- Vilda
- - project stub, build system
- - compiler
- - scheduler
- společně, či dle vyvážení časových investicí
- - návrh projektu 
- - dokumentace
- - utilities

Rozdělení bude vynuceno návrhem závislostí v build systému (dva makefiles). Viz. objektový návrh.

### Roadmap (nezávazně)
- před začátkem školy
- - většina objektů z UML existujících, byť jen s dummy funkčností
- - základní pravidla gramatiky
- - finální build system
