data Formula = Konst Bool | Not Formula | And Formula Formula | Or Formula Formula deriving (Show)

gen_help :: [Formula] -> [Formula]
gen_help fs = (map Not fs) ++ [And a b | a <- fs, b <- fs] ++ [Or a b | a <- fs, b <- fs]

gen ::  [Formula]
gen = concat $ iterate gen_help [Konst False, Konst True]