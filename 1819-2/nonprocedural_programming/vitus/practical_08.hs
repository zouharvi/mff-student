gen = (sum . map (2 *) . takeWhile((< 1000) . (^2))) [1..]

cstep n
    | mod n 2 == 0  = div n 2
    | otherwise     =  3 * n + 1

cl n
    | n == 1    = [n]
    | otherwise = n:cl (cstep n)

genl = snd (maximum [(length (cl n), cl n) | n <- [1..1000]])