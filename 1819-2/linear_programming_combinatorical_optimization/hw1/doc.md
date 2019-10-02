# Sestavení
Oba programy jsou psané v Python 3. Je třeba jej mít nainstalovaný a v cestě (v labu tomu tak je). Build není potřeba.

# Ovládání
Vstup a výstup je prováděn pomocí stdin a stdout. Spuštění a předání vstupu do _glpsol_ může tedy vypadat: `cat vstupy/vstup2-003.txt | ./task2.py > tmp.mod && glpsol -m tmp.mod`.

# Popis
## Úloha 1
Pro každý vrchol `i` se vytvoří nová proměnná `v[i]` (realizováno setem), která je nezáporná a pro hranu `(a,b)` platí, že `v[a] < v[b]` (docíleno pomocí `v[a] + 1 <= v[b]`). Zároveň se snažíme minimalizovat nejvyšší pořadí, tedy pro všechny vrcholy `minimize m; m >= v[i]`. Z podmínek pak plyne, že proměnné budou celočíselné (pokud ne, pak lze stlačit na dolní celou část => původně nebylo optimum).

## Úloha 2
Pro každou hranu `(a,b)` se vytvoří binární celočíselná nezáporná proměnná `x["a --> b"]`, která indikuje, že tuto hranu vymažeme. Optimalizujeme součet součinů těchto hran se svými váhami. Algoritmicky si nalezneme všechny 3- a 4-cykly a vynutíme, aby alespoň jedna hrana zmizela pomocí podmímky `x[..] + x[..] + x[..] >= 1`. Z důvodu optimalizace a toho, že stačí alespoň `1` se proměnné `x[..]` stávají binární.

# Chybějící řešení
## Úloha 1
Pokud zmíněné topologické uspořádání existuje, pak se uspořádá a vypíše. Pokud ne (nerovnost je tranzitivní, tj. graf by obsahoval cykly), pak neexistuje žádné přípustné řešení. Programu `glpsol` můžeme pomoct tak, že nastavíme horní odhad na očíslování počet vrcholů `V`.

## Úloha 2
Úloha má vždy alespoň jedno přípustné řešení a to odebrání úplně všech hran. Takové řešení jistě ve většině případů nebude optimální, ale pak graf bude zaručeně bez 3- a 4- cyklů. Pokud existuje přípustné řešení, pak jistě i optimální, neboť mezi přípustným a jakýmkoliv lepším je jen konečně mnoho jiných voleb hran.