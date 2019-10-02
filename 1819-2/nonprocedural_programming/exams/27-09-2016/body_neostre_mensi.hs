cmp :: (Int,Int,Int) -> (Int,Int,Int) -> Bool
cmp (a1,a2,a3) (b1,b2,b3) = (a1 <= b1) && (a2 <= b2) && (a3 <= b3)

is_ok :: (Int,Int,Int) -> [(Int,Int,Int)] -> Bool
is_ok x xs = not $ or [(cmp y x)| y <- xs, x /= y]

body :: [(Int,Int,Int)] -> [(Int,Int,Int)]
body xs = [x| x <- xs, is_ok x xs]