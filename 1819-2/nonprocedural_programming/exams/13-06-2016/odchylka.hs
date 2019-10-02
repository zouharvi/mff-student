-- comb :: [a] -> Int -> [[a]]
-- comb _ 0 = [[]]
-- comb xs n = do
--     a <- xs
--     return $ map (\x -> [a] ++ x) (comb xs (n-1))


vyries :: Float -> Float -> [(Float, Float)] ->  ([Float], [Float]) 
vyries c d merania = rozdel merania (skok c d merania) 

skok :: Float -> Float -> [(Float, Float)] -> Float 
skok c d merania = snd $ minimum [ (odchylka merania x c d, x) | (x, y) <- merania] 

rozdel :: [(Float, Float)] -> Float -> ([Float], [Float]) 
rozdel merania bod = (map fst $ takeWhile (\(x, y) -> x < bod) merania, map fst $ dropWhile (\(x,y) -> x < bod) merania) 

odchylka :: [(Float, Float)] -> Float -> Float -> Float -> Float 
odchylka [] _ _ _ = 0 
odchylka ((x,y):xs) bod c d 
    | x < bod = (y - c)^2 + zvysnaOdchylka 
    | otherwise = (y - d)^2 + zvysnaOdchylka 
    where zvysnaOdchylka = odchylka xs bod c d 