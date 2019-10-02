data  Tree a = Leaf a | T (Tree a) (Tree a)

fold :: (a -> b) -> (b -> b -> b) -> Tree a -> b 
fold f1 _ (Leaf a) = f1 a
fold f1 f2 (T l r) = f2 (fold f1 f2 l) (fold f1 f2 r)


max_tree :: Ord a => Tree a -> a
max_tree t = maximum (fold (\x -> [x]) (++) t)

max_tree2 :: Ord a => Tree a -> a
max_tree2 t = (fold id max t)