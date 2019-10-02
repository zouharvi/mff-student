-- http://forum.matfyz.info/viewtopic.php?f=169&t=11381

-- zadaný je seznam [(a,a,a)] - body ve třídimenzionálním prostoru a z nich se mají vybrat ty, pro které neexistuje žádný bod, který je ve všech třech souřadnicích neostře menší.
-- z něčeho takového: [(1,2,0), (0,2,2), (1,0,2), (0,2,4), (1,2,3)] 
-- se mělo udělat toto: [(1,2,0), (0,2,2), (1,0,2)]
protrid3d :: [(Int,Int,Int)] -> [(Int,Int,Int)]
protrid3d x = protrid3d' (setrid3d x)

protrid3d' :: [(Int,Int,Int)] -> [(Int,Int,Int)]
protrid3d' [] = []
protrid3d' (x:xs) | existujeMensi (x:xs) = protrid3d' xs
                | otherwise = x:(protrid3d' xs)

existujeMensi :: [(Int,Int,Int)] -> Bool
existujeMensi ((x1,x2,x3):(y1,y2,y3):ys) | x1 >= y1 && x2>= y2 && x3>=y3 = True
                                       | otherwise = existujeMensi ((x1,x2,x3):ys)
existujeMensi [(x1,x2,x3)] = False

setrid3d :: [(Int,Int,Int)] -> [(Int,Int,Int)]
setrid3d x = foldl vloz [] x

vloz :: [(Int,Int,Int)] -> (Int,Int,Int) -> [(Int,Int,Int)]
vloz ((x1,x2,x3):xs) (y1,y2,y3) | (x1,x2,x3) `jeVetsiNez` (y1,y2,y3) = ((x1,x2,x3):(vloz xs (y1,y2,y3)))
              | otherwise = ((y1,y2,y3):(x1,x2,x3):xs)
vloz [] (x1,x2,x3) = [(x1,x2,x3)]

jeVetsiNez :: (Int,Int,Int) -> (Int,Int,Int) -> Bool
jeVetsiNez (x1,x2,x3) (y1,y2,y3) | x1>y1 || (x1==y1 && x2>y2) || (x1==y1 && x2==y2 && x3>y3) = True
                           | otherwise = False


-- Vaskuv zpusob
protrid3dVasek :: [(Int,Int,Int)] -> [(Int,Int,Int)]
protrid3dVasek x = protrid3dVasek' x x

protrid3dVasek' :: [(Int,Int,Int)] -> [(Int,Int,Int)] -> [(Int,Int,Int)]
protrid3dVasek' (x:xs) puv | (pocetMensich x puv)>1 = protrid3dVasek' xs puv
                           | otherwise = (x:(protrid3dVasek' xs puv))
protrid3dVasek' [] puv = []

pocetMensich :: (Int,Int,Int) -> [(Int,Int,Int)] -> Int
pocetMensich _ [] = 0
pocetMensich (x1,x2,x3) ((y1,y2,y3):ys) | x1>=y1 && x2>=y2 && x3>=y3 = 1+(pocetMensich (x1,x2,x3) ys)
                           | otherwise = pocetMensich (x1,x2,x3) ys


-----------------------------------------------------------------------------------------------

-- byl zadán strom jako:
data NT a = N a [NT a] deriving Show

-- a) napsat datový konstruktor N
-- data N :: a -> [NT a] -> NT a

-- b) takový strom projít a k vrcholům dopsat pořadí navštívení postorder
ocisluj :: NT a -> NT (a,Int)
ocisluj a = res
    where (i, res) = ocisluj' a [] 0 1

ocisluj' :: NT a -> [NT (a,Int)] -> Int -> Int -> (Int, NT (a,Int))
ocisluj' (N val list) hotove i p | p>length list = ((i+1), (N (val,i) hotove))
                                 | otherwise = ocisluj' (N val list) (hotove ++ [x]) j (p+1)
             where (j,x) = ocisluj' (last(take p list)) [] i 1 

---------------------------------------------------------------------------------------------

-- Rekonštrukcia BVS
-- Máme zadaný zoznam vrcholov zoradený v preorder poradí pr prechádzaní z koreňa. Spätne z neho zostavte BVS.

-- Vopred zadané: 
data BTree a = Void | Node (BTree a) a (BTree a) deriving Show
rekonstrukce :: Ord a => [a] -> BTree a
rekonstrukce (h:ts) = Node (rekonstrukce (takeWhile (<=h) ts)) h (rekonstrukce (dropWhile (<=h) ts))
rekonstrukce [] = Void

---------------------------------------------------------------------------------------------

-- Jsou zadány dva typy stromů - jeden, který nemá explicitně rozlišenou levo-pravou orientaci, a druhý, u něhož jsou synové rozlišeni na levé a pravé. Na vstupu dostanete strom, který má v každém vrcholu hodnotu a seznam synů. V každém vrcholu je dvojice (a,Int), kde číslo Int určuje, kolik synů má být vlevo. Úkolem je napsat funkci, která z takového stromu vyrobí strom, který má v každém vrcholu explicitně dva seznamy pro levé a pravé syny.
data Tree1 a = Node1 (a,Int) [Tree1 a] deriving Show
data Tree2 a = Node2 [Tree2 a] a [Tree2 a] deriving Show

strom1Na2 :: Tree1 a -> Tree2 a
strom1Na2 (Node1 (a,x) syni) | x>(length syni) = error "Uzel ma malo synu!"
                           | otherwise = Node2 (map strom1Na2 (take x syni)) a (map strom1Na2 (drop x syni))

---------------------------------------------------------------------------------------------

-- Máte nějakou funkci, která nabývá jen dvou různých funkčních hodnot. Funkce přechází někde (nevíme kde) skokově z jedné funkční hodnoty na druhou. Na vstupu dostanete c a d určující ony dvě funkční hodnoty. Dále dostanete seznam (x,y) bodů, ve kterých jste funkci změřili s nějakou chybou. Napište funkci, která na výstupu tyto body rozdělí na levé a pravé (seznam dvou seznamů) podle toho, které body patří ještě k hodnotě c, a které už k hodnotě d. Pozor, je potřeba minimalizovat celkovou odchylku spočtenou jako součet \left( f(x_i) - y_i \right) ^2 přes všechny body, kde f(x) je změřená hodnota (ze seznamu) a y skutečná hodnota z našeho odhadu.
minFunkci:: Int -> Int -> [(Int,Int)] -> ([(Int,Int)],[(Int,Int)])
minFunkci a b body = minFunkciS a b [] (foldl setrid [] body)

setrid::[(Int,Int)] -> (Int,Int) -> [(Int,Int)]
setrid [] (x,y)  = [(x,y)]
setrid ((a,b):bodyS) (x,y)  | a>=x = ((x,y):(a,b):bodyS)
                                  | otherwise = ((a,b):(setrid bodyS (x,y)))

minFunkciS:: Int -> Int -> [(Int,Int)] -> [(Int,Int)] -> ([(Int,Int)],[(Int,Int)])
minFunkciS a b bodyA ((x,y):body) | (odchylka (((x,y):bodyA) ++ b1) a b2 b) < (odchylka bodyA a ((x,y):body) b) = ((((x,y):bodyA)++b1),b2)
                                  | otherwise = (bodyA,((x,y):body))
               where (b1,b2) = minFunkciS a b [] body
minFunkciS a b bodyA [] = (bodyA,[])

odchylka:: [(Int,Int)] -> Int -> [(Int,Int)] -> Int -> Int
odchylka bodyA a bodyB b = (foldl (+) 0 (map (\(_,y) -> (y-a)*(y-a)) bodyA)) + (foldl (+) 0 (map (\(_,y) -> (y-b)*(y-b)) bodyB))

-------------------------------------------------------------------------------------------------

-- Napište funkci, která převede slovo "abbbccac" na seznam, kde jsou po sobě jdoucí stejné znaky sjednoceny do dvojice (znak, početVýskytů). K reprezentaci výsledku použijde Either viz příklad:
rle::Eq a=>[a]->[Either a (a,Int)]
rle (s:lovo) = rle2 lovo s 1

rle2::Eq a => [a] -> a -> Int -> [Either a (a,Int)]
rle2 (s:lovo) p x | p==s = rle2 lovo p (x+1)
                | x==1 = (Left p):(rle2 lovo s 1)
                | otherwise = (Right (p,x)):(rle2 lovo s 1)
rle2 [] p x | x==1 = [Left p]
            | otherwise = [Right (p,x)]

-- Napište, jakou definici bude mít inverzní funkce, která naopak převede kontrahovaný seznam na původní slovo a potom ji napište s pomocí concat a map.
rleInv::Eq a => [Either a (a,Int)] -> [a]
rleInv seznam = concat (map rozvoj seznam)

rozvoj::Eq a => Either a (a,Int) -> [a]
rozvoj (Left a) = [a]
rozvoj (Right (a,x)) = take x (repeat a)

------------------------------------------------------------------------------------------------------

--  scitani řídkých polynomů -> mějme řídké polynomy reprezentované pomocí [(nenulový koeficient,exponent)]. Definujte pro ně datový typ (nezapomeňte na nulový polynom) a napište funkci mult (i její datovou signaturu), která bude řídké polynomy násobit.
data Polynom = P [(Int,Int)] | Nic deriving Show

secti:: Polynom -> Polynom -> Polynom
secti Nic p = p
secti p Nic = p
secti (P p1) (P p2) = P (secti' (setridq p1) (setridq p2))

secti2::[(Int,Int)] -> [(Int,Int)] -> [(Int,Int)]
secti2 p1 p2 = secti' (setridq p1) (setridq p2)

secti'::[(Int,Int)] -> [(Int,Int)] -> [(Int,Int)]
secti' ((a,b):as) ((c,d):cs) | b<d = (a,b):(secti' as ((c,d):cs))
                         | b==d = (a+c,b):(secti' as cs)
                         | b>d = (c,d):(secti' ((a,b):as) cs)
secti' a [] = a
secti' [] a = a

setridq::[(Int,Int)] -> [(Int,Int)]
setridq ((a,b):as) = (setridq mensi)++[(a,b)]++(setridq vetsi)
     where mensi = filter (\(_,x) -> x<b) as
           vetsi = filter (\(_,x) -> x>=b) as
setridq [] = []

vynasob:: Polynom -> Polynom -> Polynom
vynasob Nic _ = Nic
vynasob _ Nic = Nic 
vynasob (P p1) (P p2) = P (foldl secti2 [] (map (vynasob' p2) p1))

vynasob':: [(Int,Int)] -> (Int,Int) -> [(Int,Int)]
vynasob' ((p,q):ps) (a,b) = (p*a,q+b):(vynasob' ps (a,b))
vynasob' [] _ = []

-- skladani polynomu
sloz:: Polynom -> Polynom -> Polynom
-- do prvniho polynomu dosadime druhy
sloz (P p1) (P p2) = P (foldl secti2 [] (map (sloz' p2) p1))

sloz'::[(Int,Int)] -> (Int,Int) -> [(Int,Int)]
sloz' p2 (a,b) = map (\(x,y) -> (a*x,y)) ((umocni b) p2)

umocni::Int -> [(Int,Int)] -> [(Int,Int)]
umocni 0 a = [(1,0)]
umocni 1 a = a
umocni x a = k
    where (P k) = vynasob (P a) (P (umocni (x-1) a))
    
-----------------------------------------------------------------------------------------------------------------------

-- Mame zadanou matici (jako seznam seznamu). Nasim cilem je vypsat seznam vsech dvojic (x, y) takovych, ze podmatice (1, 1) (x, y) bude obsahovat pouze kladne hodnoty. Dvojice (x, y) musi byt vzdy nejvyssi mozne (t. j. nelze ani v jedne souradnici zvetsit)

kladna::[[Int]]->[(Int,Int)]
kladna (m:atice) = kladna' (m:atice) 1 ( length (takeWhile (>0) m))

kladna'::[[Int]]->Int->Int->[(Int,Int)]
kladna' (r1:r2:rs) x y | m==0 = [(x,y)]
                    | y>m = (y,x):(kladna' (r2:rs) (x+1) m)
                    | otherwise = kladna' (r2:rs) (x+1) y
    where m = length(takeWhile (>0) r2)
kladna' [_] x y = [(x,y)]

--------------------------------------------------------------------------------------------------------------------

-- a) Napiste fold pro binarni stromy Tree a = Leaf a | T (Tree a) (Tree a).
data Tree a = Leaf a | T (Tree a) (Tree a)
fold :: (a -> b) -> (b -> b -> b) -> Tree a -> b
fold f _ (Leaf a) = f a
fold f h (T a b) = h (fold f h a) (fold f h b)

--b) Napiste one-liner funkci, ktera vypise minimum a maximum z celeho stromu pomoci vami napsaneho foldu.
minfold :: Ord a => Tree a -> a
minfold t = fold (\x->x) min t
maxfold :: Ord a => Tree a -> a
maxfold t = fold (\x->x) max t
minmaxfold::Ord a => Tree a -> (a,a)
minmaxfold t = ((fold (\x->x) min t),(fold (\x->x) max t))
--c) Napiste hlavicku funkce z b)

-------------------------------------------------------------------------------------------

--  Pro zadané K máme generovat nekonečný uspořádáný seznam K-tic:
-- uspořádání je definováno tak, že nejprve se třídí podle maximálního prvku v daném seznamu. 
-- (jakákoliv k-tice, jejíž maximum je menší nebo rovno 2 bude před k-ticí obsahující číslo 3). 
-- Když mají dvě k-tice stejné maximum, řadí se lexikograficky.
-- Příklad pro K=2:
-- [[0,0],[0,1],[1,0],[1,1],[0,2],[1,2],[2,0],[2,1],[2,2],[0,3],.....]

genSeznam::Int -> [[Int]]
genSeznam k = genSeznam' k 0

genSeznam'::Int->Int->[[Int]]
genSeznam' k 0 = (vyber k):(genSeznam' k 1)
genSeznam' k i = (filter (\x->elem i x) (gen k i))++(genSeznam' k (i+1))

gen::Int-> Int-> [[Int]]
gen 0 _ = [[]]
gen k i = [j:l|j<-[0..i],l<-(gen (k-1) i)]

vyber k = take k [0,0..]

-----------------------------------------------------------------------------------------

-- Máme zadaný binární vyhledávací strom (reprezentaci si máme zvolit), a dvě čísla D, H.
-- Máme vrátit BVS, který vznikl ořezáním vstupního stromu tak, aby v něm byly pouze hodnoty X takové, že D<=X<=H
data Tree3 a = Node3 (Tree3 a) a (Tree3 a) | Nil deriving Show

orez::Tree3 Int -> Int -> Int -> Tree3 Int
orez (Node3 levy x pravy) d h | x<d = orez pravy d h
                             | x>h = orez levy d h
                             | otherwise = Node3 (orez levy d h) x (orez pravy d h)
orez Nil _ _ = Nil

-------------------------------------------------------------------------------------------

-- Navrhněte datový typ Graf a pro reprezentaci konečného neorientovaného grafu s vrcholy typu a. 
-- Definujte funkci troj::Graf a -> Int, která k takovému grafu vrátí počet všech jeho trojúhelníků.

data Graf a = G [(a,[a])] deriving Show

troj::Ord a => Graf a -> Int
troj (G ((v,sous):vs)) = (length (trojuhelniky (G ((v,sous):vs)))) + troj (G vs)
troj (G []) = 0

trojuhelniky::Ord a => Graf a -> [(a,a)]
trojuhelniky (G ((v,sous):vs)) = [(b,c) | (b,bsous) <- vs, (c,csous)<-vs, v<b, b<c, elem b sous, elem c bsous, elem v csous]

--------------------------------------------------------------------------------------------

-- Dán datový typ
data Bag a = Item a | Items [Bag a]
-- a) Definujte funkci pro obecný průchod touto datovou strukturou (to (a->b) tam zastupuje počáteční hodnotu v normálním foldu)
fold2 :: (a->b) -> ([b]->b) -> Bag a -> b
fold2 fitem _ (Item a) = fitem a
fold2 fitem flist (Items i) = flist (map (fold2 fitem flist) i)


-- b) Pomocí funkce fold definujte funkci 
-- listy::Bag a -> [a]
--která posbírá všechny hodnoty z položek Item ze všech úrovní zleva doprava
-- listy (Items [Item 1,Items [Item 2, Item 3], Items [Items [Item 4]]])
--[1,2,3,4]
listy::Bag a -> [a]
listy a = fold2 (\x -> [x]) (foldl (++) []) a

-------------------------------------------------------------------------------------------

-- Napište funkci, která převede slovo "abbbccac" na seznam, kde jsou po sobě jdoucí stejné znaky 
-- sjednoceny do dvojice (znak, početVýskytů). K reprezentaci výsledku použijde Either viz příklad:
-- rle::Eq a=>[a]->[Either a (a,Int)]
-- rle [a,b,b,b,c,c,a,c] = [Left a, Right (b,3), Right (c,2), Left a, Left c]

rle3::Eq a => [a] -> [Either a (a,Int)]
rle3 (x:xs) = rle' x 1 xs

rle':: Eq a => a -> Int -> [a] -> [Either a (a,Int)]
rle' x i (y:xs) | x==y = rle' x (i+1) xs
                | i==1 = (Left x):rle' y 1 xs
                | otherwise = (Right (x,i)):rle' y 1 xs
rle' x i [] | i==1 = [Left x]
            | otherwise = [Right (x,i)]

--------------------------------------------------------------------------------------------

-- Napište fold pro binární stromy. Napište funkci využívající váš fold, která pro daný binární strom 
-- spočítá počet jeho listů. 

data BTree2 a = Vltava | Vertex (BTree2 a) a (BTree2 a)
fold100::b->(b->a->b->b)->BTree2 a->b
fold100 init _ Vltava = init
fold100 init _ (Vertex Vltava _ Vltava) = init
fold100 init f (Vertex l u p) = f (fold100 init f l) u (fold100 init f p)

pocetListu:: BTree2 a -> Int
pocetListu Vltava = 0
pocetListu s = fold100 1 (\x _ z -> x+z) s

----------------------------------------------------------------------------------------

-- HTML serializer. Mame dany obecny strom, ktory ma vo vrcholoch a listoch nazvy HTML tagov, napr. "html", "body", "a", atd. Cielom bolo:
-- a) napisat typ konstruktoru tej datovej struktury
-- b) vypisat tagy do stringu podla DFS priechodu stromom zlava - teda vlastne tak, aby to bolo validne HTML.
-- Strom:         html
--               /    \
--             head   body
--                   /    \
--                  a     h2

-- Vypis: <html><head></head><body><a></a><h2></h2></body></html>

data HTMLTree = HTMLUzel [Char] [HTMLTree]

vypis::HTMLTree -> [Char]
-- vypis [] = []
vypis (HTMLUzel tag []) = "<"++tag++">"++"</"++tag++">"
vypis (HTMLUzel tag potomci) = "<"++tag++">"++(foldl (++) [] (map vypis potomci))++"</"++tag++">"

------------------------------------------------------------------------------------------------

-- Mame body v niekolkodimenzionalnom priestore. Vzdialenost medzi bodmi je urcena pomcou Manhattanskej 
-- metriky. Funkcia dostane zadanu dvojicu bodov (prihradok), a zoznam dalsich bodov. 
-- Kazdy bod zo zoznamu bolo treba zaradit do tej blizsej z tych 2 prihradok, teda do tej, ktora je 
-- blizsie podla Manhattanskej metriky.
-- Singatura funkcie bola:
zarad :: (Num a, Ord a) => ([a], [a]) -> [[a]] -> ([[a]], [[a]])
zarad (bod1,bod2) (b:ody) | d1 < d2 = prirad b 1 (zarad (bod1,bod2) ody)
                          | otherwise = prirad b 2 (zarad (bod1,bod2) ody)
                          where 
                            d1 = vzdalenost b bod1
                            d2 = vzdalenost b bod2
zarad _ [] = ([],[])

vzdalenost::(Num a, Ord a) => [a] -> [a] -> a
vzdalenost (x:xs) (y:ys) = abs (x-y) + (vzdalenost xs ys)
vzdalenost [] x | x == [] = 0
                | otherwise = error "Kolik dimenzi ten prostor teda ma?"

prirad::(Num a, Ord a) => [a] -> Int -> ([[a]],[[a]]) -> ([[a]],[[a]])
prirad b 1 (x,y) = ((b:x),y)
prirad b 2 (x,y) = (x,(b:y))