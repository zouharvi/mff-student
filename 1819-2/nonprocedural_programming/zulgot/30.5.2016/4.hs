data Tree a = Nil | Node (Tree a) a (Tree a) deriving (Show, Read, Eq)

insert:: (Ord a) => Tree a -> a -> Tree a
insert Nil v = (Node Nil v Nil)
insert (Node l c r) v
	| v>c = (Node l c (insert r v))
	| v<c = (Node (insert l v) c r)
	| v==c = (Node l c r)

elim:: (Ord a)=> Tree a -> a -> a -> Tree a -> Tree a
elim Nil n1 n2 t2 = t2
elim (Node l c r) n1 n2 t2
	| c>=n1, c<=n2 = elim r n1 n2 (elim l n1 n2 (insert t2 c))
	| otherwise = elim r n1 n2 (elim l n1 n2 t2)
