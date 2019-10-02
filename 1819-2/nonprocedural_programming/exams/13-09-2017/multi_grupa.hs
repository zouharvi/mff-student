data Group a = Group [[a]] deriving Show

multiply :: Eq a => Group a-> a -> a -> a
multiply (Group table) x y = atMatchingIndex index y $ atMatchingIndex index x table where index = header (Group table)

header :: Group a -> [a]
header (Group table) = head table

unit :: Group a -> a
unit (Group table) = head $ head table

atMatchingIndex :: Eq a => [a] -> a -> [b]-> b
atMatchingIndex (x:xs) target (d:ds)
    | x == target = d
    | otherwise = atMatchingIndex xs target ds

findOrder :: Eq a => Group a -> a -> Int
findOrder g x = (length . takeWhile (/=( unit g)) $ iterate (\y-> multiply g y x) x  ) +1


getOrders :: Eq a => Group a -> [(a,Int)]
getOrders g = zip (header g) (map (findOrder g) (header g))