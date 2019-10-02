data Strom a = Nil | Strom a [Strom a] deriving (Show)

myStrom :: Strom Char 
myStrom = Strom 'a' [Strom 'b' [Strom 'e' []], Strom 'c' [], Strom 'd' []]

label :: Strom a -> Strom (a, Int)
label a = fst (traverseMain 0 a)

traverseMain :: Int -> Strom a -> ((Strom (a, Int)), Int)
traverseMain n Nil = (Nil, n-1)
traverseMain n (Strom a xs) = ((Strom (a, lastN) children), lastN)
    where (children, lastN) = traverseList (n+1) xs

traverseList :: Int -> [Strom a] -> ([(Strom (a, Int))], Int)
traverseList n [] = ([], n)
traverseList n (x:xs) = (firstX:children, ns)
    where (firstX, lastN) = traverseMain (n-1) x
          (children, ns) = traverseList (lastN+1) xs
          