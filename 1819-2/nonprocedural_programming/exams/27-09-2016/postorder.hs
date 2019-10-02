data NT a = N a [NT a] deriving (Show)

-- f :: Num a => NT a -> NT a -> a
-- f (N x []) (N y []) = x+y

ocisluj :: NT a -> NT (a,Int) 
ocisluj a = head arr
    where
        (arr, _) = ocisluj2 [a] 0

ocisluj2 :: [NT a] -> Int -> ([NT (a,Int)], Int) 
ocisluj2 [] x = ([], x)
ocisluj2 [N a []] x = ([N (a,x) []], x+1)
ocisluj2 [N a as] x = ([N (a,lastN) asNumbered], lastN+1)
    where
        (asNumbered, lastN) = ocisluj2 as x
ocisluj2 (nA:nS) x = ([head cuNumbered] ++ asNumbered, lastN)
    where
        (cuNumbered, lastX) = ocisluj2 [nA] x
        (asNumbered, lastN) = ocisluj2 nS lastX