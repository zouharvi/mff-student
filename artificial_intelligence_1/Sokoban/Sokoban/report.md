Porovnávám s věstavěnou heuristikou SimpleDistanceHeuristic, kterou nová heuristika BlindHeuristicVilda poráží v čase a počtu expandovaných vrcholů a kvalita řešení zůstává stejná.

### BlindHeuristicVilda

Nová heuristika má čtyři komponenty, které jsou vážené kombinací. Na to, aby byla admissible, by se musely váhy prvních dvou komponenty sčítat na 1, což se nyní nesčítají, poněvadž experimentálně jsem dostával lepší výsledky s vyššími čísly a zároveň došel algoritmus ke stejně kvalitnímu řešení jako SimpleDistanceHeuristic.  

- __Crate To Target__ Počítá součet vzdálenosti každé bedny k jejímu nejbližšímu cíly.
- __Target To Crate__ Počítá součet vzdáleností každého cíle k nejbližšímu cíly. Kombinace této a předchozí komponenty má "simulovat" nejmenší bipartitní párování.
- __Sokoban To Crate__ "Zajišťuje", že Sokoban se nebude nikde zbytečně motat a zůstane v "centru dění". Toto může být zavádějící v případech, kdy Sokoban musí obcházet např. celou mapu, proto má tato komponenta nejmenší váhu.
- __Crates In Corners__ Jako rudimentární "dead end detection" nekonečně penalizuji bedny, které se nacházejí v rozích, které nejsou cílové.

### Úlohy

Částí _Easy_ se myslí zapnuté všechny přepínače ulehčující hledání řešení. V _Hard_ jsou všechny vypnuté.

#### Úloha 13

Ve 13. úloze v _Easy_ byla nová heuristika o zlomek horší (v čase a v počtu expandovaných vrcholů). V _Hard_ však Simple heuristika měla značně horší výkon. Toto je pravděpodobně zapříčiněno tím, že nová heuristika používá částečně Dead end detection ve formě Crates In Corners.

| Charakteristika | BlindHeuristicVilda | SimpleDistanceHeuristic |
|-----------------|-------|--------|
| Easy |
| Total time: | 21s | 20s |
| Solution length: | 136 | 136 |
| Closed nodes: | 198575 | 195063 |
| Hard | 
| Total time: | 34s | 114s |
| Solution length: | 136 | 136 |
| Closed nodes: | 7522898 | 20177775 |
||

<br>
<br>
<br>
<br>

#### Úloha 1

| Charakteristika | BlindHeuristicVilda | SimpleDistanceHeuristic |
|-----------------|-------|--------|
| Easy |
| Total time: | 2s | 3s |
| Solution length: | 228 | 228 |
| Closed nodes: | 28518 | 28518 |
| Hard | 
| Total time: | 97s | >200s |
| Solution length: | 228 | N/A |
| Closed nodes: | 18944914 | N/A |
||

#### Úlohy 1-15

V poslední tabulce je ukázána časová náročnost na variabilní úrovni náročnosti. Pokud obě úlohy timeoutovaly (>200s), pak se změnila obtížnost z _Hard_ na _Easy_. V 8 případech byla nová heuritika časově lepší, v 6 nešlo rozhodnout a v 1 o trochu horší.

| Úloha | Obtížnost | BlindHeuristicVilda | SimpleDistanceHeuristic |
|-------|-----------|---------------------|-------------------------|
| 1 | Hard | 97s | >200s |
| 2 | Hard | 0.007s | 0.01s |
| 3 | Hard | 0.7s | 8s | 
| 4 | Easy | >200s | >200s | 
| 5 | Easy | 13s | 36s | 
| 6 | Hard | 14s | >200s | 
| 7 | Easy | >200s | >200s | 
| 8 | Easy | >200s | >200s |
| 9 | Hard | 156s | 183s |
| 10 | Easy | >200s | >200s |
| 11 | Easy | >200s | >200s |
| 12 | Easy | 131s | 118s |
| 13 | Hard | 34s | 126s |
| 14 | Hard | 0.1s | 0.3s |
| 15 | Easy | >200s | >200s |
||