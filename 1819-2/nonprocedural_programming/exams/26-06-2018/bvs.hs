data BVS a = Nic | Uzel (BVS a) a (BVS a) deriving (Show)

reBVS :: Ord a => [a] -> BVS a
reBVS [] = Nic
reBVS (a:ax) = Uzel (reBVS (takeWhile (<a) ax)) a (reBVS (dropWhile (<a) ax)) 