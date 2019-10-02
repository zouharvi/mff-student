xor:: [Int] -> [Int] -> [Int]
xor [] b = b
xor (x:xs) b = xor xs ( filter (/=x) b )

xor_2:: [Int] -> [Int] -> [[Int]]
xor_2 a b =  [xor b a] ++ [xor a b]

multi::[[Int]]->[[Int]]
multi x = concat (map helper (get_doubles x))

helper (x:y:xs) = (cartProd x y) 

cartProd xs ys = [[x,y] | x <- xs, y <- ys]

get_doubles:: [[Int]] -> [[[Int]]]
get_doubles [] = [[[], []]]
get_doubles (x:xs) = [xor_2 x y | y<-xs ] ++ get_doubles xs

