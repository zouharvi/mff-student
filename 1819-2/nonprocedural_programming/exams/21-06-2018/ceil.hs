ceilNaive :: Float -> Float
ceilNaive n = last $ takeWhile (<(n+1)) (map fromIntegral [1..])

ceilU :: Float -> Float
ceilU x | x == 0 = 0
        | x < 0 = (-(ceilM (-x)))
        | x > 0 = ceilM x

ceilM :: Float -> Float
ceilM x = ceilBinary 0 (lastLower*2) x
    where listLower = takeWhile (<x) (map (\y -> fromIntegral (2^y)) [0,1..])
          lastLower = last listLower

ceilBinary :: Float -> Float -> Float -> Float
ceilBinary lower upper x 
    | lower >= upper-1 = upper 
    | middle == x = x
    | middle > x = ceilBinary lower middle x
    | middle < x = ceilBinary middle upper x
    where middle = (lower+upper)/2