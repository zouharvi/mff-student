type Poly = [(Int, Int)]
-- Nejdříve vynásobit
-- Poté posčítat stejné exponenty


secti:: (Int, Int) -> Poly -> Poly
secti (a,b) [] = [(a,b)]
secti (a,b) (x:xs)
	| b== (snd x) = secti (a+(fst x),b) xs
	| otherwise = [x] ++ (secti (a,b) xs)

reduce:: Poly -> Int ->  Int -> Poly
reduce (x:xs) n1 n2 
	| n1/=n2 = reduce (secti x xs) (n1+1) n2
	| n1==n2 = (x:xs)

nasob:: Poly -> Poly -> Poly
nasob [] b = []
nasob (x:xs) b = map ((\(h,j) (k,l) -> (h*k,j+l)) x) b ++ (nasob xs b)

vyhodnot:: Poly -> Poly -> Poly
vyhodnot a b = reduce (nasob a b) 0 (length (nasob a b))
