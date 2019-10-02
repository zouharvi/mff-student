mensiNez :: Integer -> [Integer]
mensiNez n = [x | x <- [1..], x < n]

tuples :: [a] -> [b] -> [(a,b)]
tuples as bs = [(a,b)| a <- as, b <- bs]

data Dvojice a = Dvojice a a deriving (Show)

prvni :: Dvojice a -> a
prvni (Dvojice a _) = a
druhy :: Dvojice a -> a
druhy (Dvojice _ a) = a

naTuple :: Dvojice a -> (a, a)
naTuple (Dvojice a b) = (a, b)