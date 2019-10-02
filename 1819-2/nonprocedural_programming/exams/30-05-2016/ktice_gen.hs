gen :: Int -> [[Int]]
gen n = genWithMax n 0

genWithMax :: Int -> Int -> [[Int]]
genWithMax n max = [xs | xs <- var n max, max `elem` xs] ++ genWithMax n (max + 1)

var :: Int -> Int -> [[Int]]
var 0 _ = [[]]
var k n = [x:xs | x <- [0..n], xs <- var (k - 1) n]
