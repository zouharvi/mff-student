data Tree a = Node a [Tree a] deriving (Show)

takeTree :: Int -> Int -> Tree a -> Tree a
takeTree 1 _ (Node a _) = Node a []
takeTree n m (Node a children) = Node a childrenOk
    where
        childrenOk = take m (map (\x -> takeTree (n-1) m x) children)