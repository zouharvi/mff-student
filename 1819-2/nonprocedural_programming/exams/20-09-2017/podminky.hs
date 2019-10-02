podminkySingle :: [(a->Bool)] -> a -> [[a]]
podminkySingle [] _ = []
podminkySingle (f:fs) a
    | f a = [a]:(take (length fs) (repeat []))
    | otherwise = []:(podminkySingle fs a)

podminky :: [(a->Bool)] -> [a] -> [[a]]
podminky _ [] = error "should not happen"
podminky fce (a:[]) = podminkySingle fce a
podminky fce (a:as) = zipWith (++) pA pAs
    where
        pA = podminkySingle fce a 
        pAs = podminky fce as