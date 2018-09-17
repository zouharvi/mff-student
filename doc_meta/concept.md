
## Obecné
Projekt ZimaDB si klade za cíl implementovat podmnožinu funkcionality SQL compliant engine, konkrétně SQLite. Mezi podporované funkcionality zcela jistě bude patřit:
- práce s databázovými soubory skrze ZimaDB CLI
- základní operace SELECT, INSERT, UPDATE, DELETE s jednoduchými modifikátory a podmínkami WHERE
- agregační funkce COUNT, SUM, AVG
- jednoúrovňový JOIN


## Vývoj
Součástí projektu jsou následující položky:

- návrh projektu
- vývoj 
- - project stub
- - compiler
- - - tokenizer
- - - parser
- - - grammar
- - - core interface
- - core
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
- Vilda
- - project stub
- - compiler
- společně, či dle vyvážení časových investicí
- - návrh projektu 
- - core
- - dokumentace
- - utilities

Rozdělení bude vynuceno návrhem závislostí v build systému (dva makefiles).