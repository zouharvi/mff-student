data Tree a = Leaf a | T (Tree a) (Tree a)
fold::(a->b) -> (b->b->b) -> Tree a ->b
fold mainfunc pairfunc (Leaf a) = mainfunc a 
fold mainfunc pairfunc (T a b) = pairfunc (fold mainfunc pairfunc a) (fold mainfunc pairfunc b)

maxmin:: (Ord a)=> Tree a -> [a]
maxmin a = [(fold (\x -> x) (\x y -> max x y) a), (fold (\x -> x) (\x y -> min x y) a)] 

