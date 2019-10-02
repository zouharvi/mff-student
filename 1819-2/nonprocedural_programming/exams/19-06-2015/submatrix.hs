import Data.Set (toList, fromList)
makeUnique :: Ord a => [a] -> [a]
makeUnique lst = toList (fromList lst)

pos :: [[Int]] -> (Int,Int) -> Bool
pos m (x,y) = and bools
    where cRows = take y m
          cM = [(take x o)| o <- cRows]
          flat = foldl (++) [] cM
          bools = map (0<) flat

greedy :: [[Int]] -> (Int,Int) -> [(Int,Int)]
greedy m (x,y) = makeUnique $ greedyA m (x,y)

greedyA :: [[Int]] -> (Int,Int) -> [(Int,Int)]
greedyA m (x,y)
    | x < (length m) && y < (length m) && (pos m (x+1, y)) && (pos m (x, y+1)) = greedy m (x+1, y) ++ greedy m (x, y+1)
    | x < (length m) && (pos m (x+1, y)) = greedy m (x+1, y)
    | y < (length m) && (pos m (x, y+1)) = greedy m (x, y+1)
    | pos m (x, y) = [(x,y)]
    | otherwise = []