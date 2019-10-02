-- REPREZENTACE DLOUHYCH DESETINNYCH CISEL A JEJICH NASOBENI

times (ls1,f1) (ls2,f2) = (reverse $ toLongFloat ((foldl (\acc x -> acc * 10 + x) 0 ls1) * (foldl (\acc x -> acc * 10 + x) 0 ls2)), (f1 + f2))
                    where toLongFloat num | num > 0 = (num `mod` 10):(toLongFloat (num `div` 10))
                                          | otherwise = []


-- BVS OREZANI

data Tree a = Nil | Node (Tree a) a (Tree a) deriving(Show)

add' Nil val = Node Nil val Nil
add' (Node l h r) val | val <= h  = Node (add' l val) h r
                      | otherwise = Node l h (add' r val)

fromList xs = foldl (add') Nil xs

filterTreeToList _ _ Nil = []
filterTreeToList d h (Node l val r) | val < d = filterTreeToList d h r
                                    | val > h = filterTreeToList d h l
                                    | otherwise = val:(filterTreeToList d h l) ++ (filterTreeToList d h r)

filterTree d h tree = fromList $ filterTreeToList d h tree

-- MAX PODMATICE

-- nejdelsi v radku
maxx :: [Int] -> Int -> Int
maxx [] p = (p-1)
maxx (x:xs) p = if x >= 0 then maxx xs p+1
                else (p-1)

-- nejdelsi v item radku
maxx' :: [[Int]] -> Int -> Int
maxx' m i = maxx (m !! i) 0

-- nejdelsi v item sloupci
mkdown :: [[Int]] -> Int -> Int -> Int
mkdown [] p i = (p-1)
mkdown (s:ss) p i = if x >= 0 then mkdown ss (p+1) i
                  else (p-1)
                 where x = s !! i

maxxy m p i  = if (i >= (length m)) then p
              else if ((maxx' m i) < p) then (i-1)
                   else maxxy m p (i+1)

maxyy :: [[Int]] -> Int -> Int -> Int
maxyy mm p i = if (i >= length m) then (i-1)
               else if ((mkdown mm 0 i) < p) then (i-1)
                    else maxyy mm p (i+1)
  where (m:ms) = mm

pocitej :: [[Int]] -> [(Int,Int)]
pocitej m = [xova,yova] -- remove duplicates
    where
        mx1 = (maxx' m 0)
        xova = ((maxxy m mx1 0), mx1)
        my1 = mkdown m 0 0
        yova = (my1, maxyy m my1 0)

--- test::: pocitej [[1,2,3],[4,5,6],[7,-8,9]]

-- KTICE

allTuples :: Integer -> Integer -> [[Integer]]
allTuples 0 maxElem = [[]]
allTuples k maxElem = concat $ [map (a:) (allTuples (k-1) maxElem) | a <- [0..maxElem]]

allTuplesWithMaxElem k maxElem = filter (elem maxElem) (allTuples k maxElem)

ktice k = concat $ [allTuplesWithMaxElem k i | i <- [0..]]

-- KONKAT. RETEZCU

smt poc char
    | poc == 1 = Left char
    | otherwise = Right (char,poc)

--delej :: [Char] -> Char -> Int -> [(Char,Int)] -> [(Char,Int)]
delej [] prv poc acc = ((smt poc prv):acc)
delej (x:xs) prv poc acc
  | x == prv = delej xs prv (poc+1) acc
  | otherwise = delej (xs) (x) 1 ((smt poc prv):acc)

konk s = delej (tail s) (head s) 1 []

expaa :: Either a (a,Int) -> [a]
expaa (Left a) = [a]
expaa (Right (a,b)) = take b $ repeat a

invrs :: [Either a (a,Int)] -> [a]
invrs sez = concat $ map expaa sez

-- TREE FOLD A POCITANI LISTU

data Strom a = Nul | Uzel (Strom a) a (Strom a) deriving (Show)

treeFold :: (a -> b -> a -> a) -> a -> Strom b -> a
treeFold _      fNil Nul            = fNil
treeFold fUzel  fNil (Uzel l u p)   = fUzel (treeFold fUzel fNil l) u (treeFold fUzel fNil p)

-- *Main> treeFold (\a b c -> a+c) 1 (Uzel (Uzel Nul 4 Nul) (5) (Uzel Nul 5 Nul)  )
--        4

-- HTML -- PROCHAZENI OBECNEHO STROMU, vypis v PREORDER + POSTORDER

data Tre a = Try a [Tre a]

visit :: [Tre a] -> [a] -> [a]
visit [] sez = sez
visit (syn:sons) sez = visit sons (dfs syn sez)

dfs :: Tre a -> [a] -> [a]
dfs (Try hod stromy) vis = (hod:(visit stromy (hod:vis)))

depth strom = reverse $ dfs strom []

-- *Main> depth (Try 1 [Try 2 [Try 1337 []], Try 3 [Try 7 [], Try 8 [Try 9 []]], Try 4 [Try 5 [], Try 6 []]])
--        [1,2,1337,1337,2,3,7,7,8,9,9,8,3,4,5,5,6,6,4,1]


-- OCISLOVAT VRCHOLY STROMU V PREORDER A POSTORDER PORADI

-- MANHATTAN METRIKA

mandist :: (Int,Int) -> (Int,Int) -> Int
mandist (x1,y1) (x2,y2) = abs (x1-x2) + abs (y1 - y2)

mansort :: ((Int,Int),(Int,Int)) -> [(Int,Int)] -> ( [(Int,Int)] , [(Int,Int)] )
mansort refs [] = ([],[])
mansort (ref1,ref2) (p:points)
  | dist1 <= dist2 = ((p:left) , (right))
  | otherwise =      ((left) , (p:right))
    where
      dist1 = mandist p ref1
      dist2 = mandist p ref2
      (left,right) = mansort (ref1,ref2) points

-- RIDKE POLYNOMY

jednak :: (Int,Int) -> [(Int,Int)] -> [(Int,Int)] -> [(Int,Int)]
jednak _ [] acc = acc
jednak (koe,exp) ((ck,ce):zb) acc = jednak (koe,exp) zb ((koe*ck,exp+ce):acc)

vsenas :: [(Int,Int)] -> [(Int,Int)] -> [(Int,Int)] -> [(Int,Int)]
vsenas [] _ acc = acc
vsenas (prvni:zb1) druhy acc = vsenas zb1 druhy ((jednak prvni druhy [])++acc)

concpol :: [(Int,Int)] -> [(Int,Int)] -> [(Int,Int)]
concpol [] acc = acc
concpol (prv:zb) acc = concpol zb2 (new:acc)
  where
      (koef,exp) = prv
      zb2 = filter ((/=exp) . snd ) zb
      sloucit = filter ((==exp) . snd ) zb
      new = ( (sum $ map fst sloucit) + koef,exp)


-- CUSTOM FOLD NA STRUKTURE BAG

data Bag a = Item a | Items [Bag a]

-- a) Definovat funkci fold pro obecny pruchod datovou strukturou.
fold :: (a -> b) -> ([b] -> b) -> Bag a -> b
fold func listFunc (Item x) = func x
fold func listFunc (Items xs) = listFunc [fold func listFunc bag | bag <- xs]

-- b) Definovat funkci listy, ktera vrati seznam polozek s datovymi konstruktory Item.
listy :: Bag a -> [a]
listy = fold (:[]) concat -- triky, :[] udela z prvku x -> [x]

-- DOPLNENI HRAN DO HYPERGRAFU

-- DELENI NA PRIHRADKY