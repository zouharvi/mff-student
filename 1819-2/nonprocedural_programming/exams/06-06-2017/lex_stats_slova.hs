-- -- 3 
-- slova :: String -> Int -> [(String,Int)] 
-- slova text n = sluc (mujSort (vseSlova text n)) 

-- vseSlova::String -> Int -> [String] 
-- vseSlova [] _ = [] 
-- vseSlova text n | (length slovo)>=n = slovo:(vseSlova zbytek n) 
--                 | otherwise = vseSlova zbytek n 
--     where (slovo,zbytek) = dejSlovo text 
          
-- dejSlovo::String -> (String,String) 
-- dejSlovo text = (takeWhile (not.white) (dropWhile white text), dropWhile (not.white) (dropWhile white text)) 

-- 3 
slova :: String -> Int -> [(String,Int)] 
slova text n = sluc (mujSort (vseSlova text n)) 

vseSlova::String -> Int -> [String] 
vseSlova [] _ = [] 
vseSlova text n | (length slovo)>=n = slovo:(vseSlova zbytek n) 
                | otherwise = vseSlova zbytek n 
    where (slovo,zbytek) = dejSlovo text 
          
dejSlovo::String -> (String,String) 
dejSlovo text = (takeWhile (not.white) (dropWhile white text), dropWhile (not.white) (dropWhile white text)) 

white::Char -> Bool 
white x | elem x [' ', '\t', ' '] = True 
        | otherwise = False 
        
mujSort::Ord a => [a] -> [a] 
mujSort [] = [] 
mujSort (x:xs) = (mujSort mensi)++[x]++(mujSort vetsi) 
    where mensi = filter (<=x) xs 
          vetsi = filter (>x) xs 
          
sluc::Eq a => [a] -> [(a,Int)] 
sluc (x:xs) = sluc' x 1 xs 

sluc'::Eq a => a -> Int -> [a] -> [(a,Int)] 
sluc' x i [] = [(x,i)] 
sluc' x i (y:ys) | x==y = sluc' x (i+1) ys 
                 | otherwise = (x,i):(sluc' y 1 ys)