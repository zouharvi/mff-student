data Bag a = Item a | Items [Bag a] 

fold :: (a->b) -> ([b]->b) -> Bag a -> b
fold f1 _  (Item x) = f1 x
fold f1 f2 (Items xs) = f2 $ map (fold f1 f2) xs

listy :: Bag a -> [a]
listy bag = fold (\x -> [x]) (\x -> (foldl (++) [] x)) bag