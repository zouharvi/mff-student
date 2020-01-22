# HSV
- hue, saturation, (brightness) value (0-360, 0-1, 0-1)
- v = max(rgb)
- s = max(rgb)/(max(rgb)-min(rgb))
- lidský

# Konstrukce 3D povrchové scény - datová struktura
- pro jedno těleso: VHS (z trojúhelníků)
- celkově hiearchický model
- okřídlené hrany
- normály ve vrcholech, hranách a stěnách
- jak ukládat? TODO

# Kamera - letecký simulátor
- perspektivní středová projekce
- near & far clipping plane, field of view
- mění se far clipping plane v závislosti na výšce, taky LOD
- near clipping plane - průmětna
- střed S, vzdálenost od průmětny d, svislý vektor u, normálnový vektor N

# Struktura hrany polygonu pro použití ve vybarvování po řádkách
- double x (počáteční, pak aktuální průsečík x s řádkem)
- int y (počáteční y)
- int dy = y2 - y1 (výška úsečky)
- double dxy = (x2 - x1) / lengthY (změna x při změně y o jedna)

# Anti-aliasing
- metoda vykreslování proti hranatým okrajům, používá více barev než samotný obrazec
- super-sampling: diskretizace se provede ve větším rozlišení a při snižování rozlišení se bere průměr z okna
- kreslení s vyhlazováním: už při kreslení děláme antialisng, běžně určujeme alpha vzdáleností od samotného obrazce
- - (např. vzdálenost D od středu pixelu k úsečce) (Bresenham)

# Flood-fill with FIFO
- why is LIFO bad? TOOD
- TODO

# HDR
- high dynamic range
- uloženo v plovoucích číslech
- dá se pořídit různou expozicí (nikoliv clonou, ta mění FOV)
- v počítačové grafice má spousta věcí značně rozdílné intenzity (není přirozené prostředí)
- je třeba převod do LDR (ořez/tone mapping)

# quadtree operace
- dá se vymyslet na místě TODO
- prochází se paralelně, buduje se nový (šlo by asi zapisovat do jednoho z nich)

# Phong model
- tři složky:
- - difuzní složka Ed (ideálně matné těleso)
- - okolní světlo Ea (hack simulující odražené světlo)
- - lesklý odraz Es (odleskl na povrchu tělesa)
- + obrázek