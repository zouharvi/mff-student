data Graf a = Hrany [(a, a)] deriving (Show)

troj :: Eq a => Graf a -> [(a,a,a)]
troj (Hrany xs) = [(a1, a3, a5)| (a1, a2) <- xs, (a3, a4) <- xs, (a5, a6) <- xs, a2 == a3, a4 == a5, a6 == a1]