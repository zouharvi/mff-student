data Btree a = Nill | Node (Btree a) a (Btree a) deriving (Show)

insert::(Ord a)=> Btree a -> a -> Btree a
insert Nill a = (Node Nill a Nill)
insert (Node b1 v b2) a
	| a < v = (Node (insert b1 a) v b2)
	| a >= v = (Node b1 v (insert b2 a))

transform:: (Ord a)=> [a] -> Btree a
transform vals = foldl insert Nill vals
