data Tree1 a = Node1 (a,Int) [Tree1 a] deriving (Show)
data Tree2 a = Node2 [Tree2 a] a [Tree2 a] deriving (Show)

tmute :: Tree1 a -> Tree2 a
tmute (Node1 (val, leftN) children) = Node2 [tmute x| x <- lCh] val [tmute x| x <- rCh]
    where
        lCh = take leftN children
        rCh = drop leftN children
