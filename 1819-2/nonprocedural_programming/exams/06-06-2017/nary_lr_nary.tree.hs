-- 4 
data NTree a = N2 a [NTree a] deriving Show 
data UspTree a = UT [UspTree a] a [UspTree a] deriving Show 

preved:: NTree (a,Int) -> UspTree a 
preved (N2 (x,_) []) = UT [] x [] 
preved (N2 (x,n) l) = UT (take n ll) x (drop n ll) 
    where ll = map preved l