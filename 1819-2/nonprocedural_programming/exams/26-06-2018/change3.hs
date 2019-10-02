import Data.Set (toList, fromList)
makeUnique :: Ord a => [a] -> [a]
makeUnique lst = toList (fromList lst)

change3 :: [Char] -> [Char] -> [[Char]]
change3 sub xs = filter (\can -> (dist can xs) == 3) (makeUnique (genAll sub xs))

genAll :: [Char] -> [Char] -> [[Char]]
genAll _ [] = []
genAll sub [x] = map (\y -> [y]) (x:sub)
genAll sub (x:xs) = [(a:rest)| a <- (x:sub), rest <- (genAll sub xs)]

-- changeN :: Int -> [Char] -> [Char] -> [[Char]]
-- changeN n sub [x]
--     | n <= 0 = []
--     | n == 1 = map (\y -> [y]) sub
--     | n > 1  = []
-- changeN n sub (x:xs) = (map (\y -> x:y) (changeN n sub (xs))) ++ ([(a:rest)| a <- sub, rest <- (changeN (n-1) sub xs)])

dist :: [Char] -> [Char] -> Int
dist [] _ = 0
dist _ [] = 0
dist (a:as) (b:bs)
    | a == b = (dist as bs)
    | otherwise = 1 + (dist as bs)