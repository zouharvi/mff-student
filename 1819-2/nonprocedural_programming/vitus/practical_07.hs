-- isInt x = x == fromInteger (round x)
-- p m = [(x,y,sqrt(x^2+y^2)) | x <- [1..m], y <- [x..m], isInt(sqrt(x^2+y^2))]

p :: Int -> [(Int, Int, Int)]
p m = [(x,y,z) | x <- [1..m], y <- [x..m], z <- [y..m], z*z == x*x+y*y]