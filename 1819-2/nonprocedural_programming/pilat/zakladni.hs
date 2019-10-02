fact :: Integer -> Integer
fact x 
       | x == 0 = 1
       | x > 0  = x * fact (x-1)
       | otherwise = error "Nope"

mMap :: (a -> b) -> [a] -> [b]
mMap _ [] = []
mMap f (x:xs) = (f x):(mMap f xs)

mTake :: Int -> [a] -> [a]
mTake _ [] = []
mTake 0 _ = []
mTake n (x:xs) | n > 0 = x:(mTake (n-1) xs)
               | otherwise = []

mocniny_dvojky :: Int -> [Int]
mocniny_dvojky n = mTake n (mMap (2^) [1..])

mTakeWhile :: (a -> Bool) -> [a] -> [a]
mTakeWhile _ [] = []
mTakeWhile f (x:xs) | f x = x:(mTakeWhile f xs)
                      | otherwise = []

mZip :: [a] -> [b] -> [(a,b)]
mZip [] _ = []
mZip _ [] = []
mZip (a:as) (b:bs) = (a,b):(mZip as bs)

mZipWith :: (a -> b -> c) -> [a] -> [b] -> [c]
mZipWith _ [] _ = []
mZipWith _ _ [] = []
mZipWith f (a:as) (b:bs) = (f a b):(mZipWith f as bs)

mFoldl :: (a -> b -> a) -> a -> [b] -> a
mFoldl _ a [] = a
mFoldl f a (x:xs) = mFoldl f (f a x) xs

mFoldl1 :: (a -> a -> a) -> [a] -> a
mFoldl1 f (x:xs) = mFoldl f x xs

skalarniSoucin :: Num a => [a] -> [a] -> a
skalarniSoucin as bs = mFoldl1 (+) (mZipWith (*) as bs)

mFilter :: (a -> Bool) -> [a] -> [a]
mFilter _ [] = []
mFilter f (a:as) | f a = a:(mFilter f as)
                 | otherwise = mFilter f as
                 
qsort :: Ord a => [a] -> [a]
qsort [] = []
qsort (x:xs) = (qsort mensi)++[x]++(qsort vetsi)
             where
                mensi = mFilter (<x) xs
                vetsi = mFilter (>x) xs