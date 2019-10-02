-- 1
rleEncode :: (Eq a) => [a] -> [(Int, a)]
rleEncode [] = []
rleEncode list = ((rleEncodeLength list, head list)):(rleEncode (drop (rleEncodeLength list) list))
rleEncodeLength :: (Eq a) => [a] -> Int
rleEncodeLength list = length $ takeWhile (== head list) list

rleDecode :: [(Int, a)] -> [a]
rleDecode [] = []
rleDecode ((0, char):rest) = rleDecode rest
rleDecode ((len, char):rest) = char:(rleDecode ((len-1, char):rest))

-- 2
primes1 :: [Integer]
primes1 = primes1Gen 2
primes1Gen current = current : filter (\i -> (mod i current) /= 0) (primes1Gen (current+1))

primes2 :: [Integer]
primes2  = primes2Sieve [2..] 
primes2Sieve (current:rest) = current : primes2Sieve [x | x <- rest, (mod x current) /= 0]

-- 3
mergeWith :: (a -> a -> Bool) -> [a] -> [a] -> [a]
mergeWith comp [] rest       = rest
mergeWith comp rest []       = rest
mergeWith comp (fLeft:rLeft) (fRight:rRight)
        | fLeft `comp` fRight    = fLeft:mergeWith comp rLeft (fRight:rRight)
        | otherwise              = fRight:mergeWith comp (fLeft:rLeft) rRight

split :: [a] -> ([a],[a])
split list = (take (length list `div` 2) list, drop (length list `div` 2) list)

sortWith :: (a -> a -> Bool) -> [a] -> [a]
sortWith _ [x] = [x]
sortWith comp list = mergeWith comp (sortWith comp (fst (split list))) (sortWith comp (snd (split list)))

-- BONUS
-- COMBINATIONS
joinLists :: [a] -> [a] -> [a]
joinLists [] x = x
joinLists (current:restA) restB = current:(joinLists restA restB)

combinations :: Int -> [a] -> [[a]]
combinations 0 _      = [[]]
combinations _ []     = []
-- prepend current to the rest or dont, but join results
combinations k (current:rest) = joinLists (map (current:) (combinations (k-1) rest)) (combinations k rest)

-- PERMUTATIONS
deleteNth :: Int -> [a] -> [a]
deleteNth _ [] = []
deleteNth i (current:rest)
        | i == 0    = rest
        | otherwise = current : deleteNth (i-1) rest

permutations :: [a] -> [[a]]
permutations [] = [[]]
permutations list = [(list!!ai):x | ai <- [0..((length list)-1)], x <- (permutations $ deleteNth ai list)]

-- VARIATIONS
-- variations are just permutations of all combinations
variations :: Int -> [a] -> [[a]]
variations k list = foldr joinLists [] [permutations comb | comb <- combinations k list]