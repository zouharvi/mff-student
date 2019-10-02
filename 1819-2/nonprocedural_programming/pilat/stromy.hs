data Strom a = Nil | Uzel (Strom a) a (Strom a) deriving (Show)

pridej :: Ord a => Strom a -> a -> Strom a
pridej Nil a = Uzel Nil a Nil
pridej (Uzel sL x sB) a | x > a  = (Uzel sL x (pridej sB a))
                        | x <= a = (Uzel (pridej sL a) x sB)
                        | otherwise = error "Nope"

seznamNaBST :: Ord a => [a] -> Strom a
seznamNaBST as = foldl pridej Nil as

treeMap :: (a->b) -> Strom a -> Strom b
treeMap _ Nil = Nil
treeMap f (Uzel sB x sL) = Uzel (treeMap f sB) (f x) (treeMap f sL)

treeFold :: (a) -> (a -> b -> a -> a) -> Strom b -> a
treeFold fNil _ Nil = fNil
treeFold fNil fUzel (Uzel sL x sB) = fUzel (treeFold fNil fUzel sL) x (treeFold fNil fUzel sB) 

prefixBSTnaSzenam :: Strom a -> [a]
prefixBSTnaSzenam a = treeFold [] (\la u pa -> la ++ [u] ++ pa) a