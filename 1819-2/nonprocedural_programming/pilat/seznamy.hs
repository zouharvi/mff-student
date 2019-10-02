problem6 :: Int -> Int
problem6 n = (sum [1..n])^2 - (sum (map (^2) [1..n]))

prime :: Integer -> Bool
prime n | n < 2 = False
        | otherwise = and (map (\x -> n `mod` x /= 0) [2..(n-1)])

primes :: [Integer]
primes = filter prime [1..]

primesN :: Int -> [Integer]
primesN a = take a primes 

primesLt :: Integer -> [Integer]
primesLt a = takeWhile (<a) primes

horner :: Num a => [a] -> a
horner as = foldl (\x y -> 10*x + y) 0 as

foldrMap :: (a->b) -> [a] -> [b]
foldrMap _ [] = []
foldrMap f a = foldr (\x y -> (f x):y) [] a