-- Ideálně bychom chtěli použít word alignment, ale pro unsupervised ML úlohu nemáme dostatek dat (běžně se používají crawly z webu)
-- Jako supervised ML úlohuu bychom museli nasadit nějaký ML algoritmus.
-- Pro unsupervised s málo daty musíme bohužel předpokládat, že word alignment je buď diagonální, nebo uniformní.
-- Postavíme si ze vstupu datovou strukturu, která bude daným slovům přiřazovat jejich překlady a to i s četností, kterou následně použijeme při inferenci.
-- Při inferenci odebereme nejpravděpodobnější dvojici (co do frekvence ve slovníku) a iterujeme

-- Později by šlo přidat i drobné manuální vylepšení, jako např. když je slovo uprostřed věty a začíná velkým písmenem, tak se má udělat alignment pouze na toto slovo. (Nebude fungovat u Němčiny)
-- Pokud se slovo vyskytuje i v cílové větě, tak se s tímto slovem spáruje. Toto pravidlo se však v praxi rozhodně nikdy nepoužije, neboť naprosto nebude fungovat v případech např. souvětí (může se udělat alignment do jiné věty).


type Slovo = [Char]
type PrekladSlova = ([Slovo], [Slovo])
type PrekladySlova = [PrekladSlova]
type PrekladyVety = [(Slovo, Slovo)]
type SlovoCetnost = (Slovo, Int)
type Slovnik = [(Slovo, [SlovoCetnost])]
type AlignSlova = [(Slovo, Slovo)]

ex1Preklad :: PrekladySlova
ex1Preklad = [
(["Ahoj", "jak", "se", "mas", "?"], ["Hi", "how", "are", "you", "?"]),
(["Ahoj", "jmenuji", "se", "Vilda", "."], ["Hello", "my", "name", "is", "Vilda", "."])
]

-- c = buildFreqDic $ [head ex1Preklad]
-- d = buildFreqDic $ tail ex1Preklad

buildFreqDiag :: ([Slovo], [Slovo]) -> Slovnik
buildFreqDiag ([], _) = []
buildFreqDiag (_, []) = []
buildFreqDiag (a:as, b:bs) = (a, [(b, 1)]):(buildFreqDiag (as, bs))

-- TODO: this is not correct
mergeFreq :: [SlovoCetnost] -> [SlovoCetnost] -> [SlovoCetnost]
mergeFreq a b = a ++ b

addToDictionary :: [(Slovo, [SlovoCetnost])] -> (Slovo, [SlovoCetnost]) -> [(Slovo, [SlovoCetnost])]
addToDictionary [] b = [b]
addToDictionary ((a,c1):as) (b, c2)
| a == b = (a, mergeFreq c1 c2):as
| otherwise = (a,c1):(addToDictionary as (b, c2))

mergeDics :: [(Slovo, [SlovoCetnost])] -> [(Slovo, [SlovoCetnost])] -> [(Slovo, [SlovoCetnost])]
mergeDics [] a = a
mergeDics a [] = a
mergeDics (a:as) bs = mergeDics as (addToDictionary bs a)

flattenDic :: [Slovnik] -> Slovnik
flattenDic [] = []
flattenDic (a:[]) = a
flattenDic (a:b:as) = flattenDic (x:as)
where
x = mergeDics a b

buildFreqDic :: PrekladySlova -> Slovnik
buildFreqDic as = flattenDic $ map buildFreqDiag as

findInDic :: Slovnik -> Slovo -> [SlovoCetnost]
findInDic [] _ = error "Slovo ve slovniku neni"
findInDic ((a,cetnost):as) slovo
| a == slovo = cetnost
| otherwise = findInDic as slovo

intersectResult :: [SlovoCetnost] -> [Slovo] -> [SlovoCetnost]
intersectResult cetnosti veta = [(a1, c1) | (a1, c1) <- cetnosti, slovo <- veta, a1 == slovo]

bestResult :: [SlovoCetnost] -> SlovoCetnost
bestResult [] = ("NWF", -1)
bestResult ((a1,c1):cs)
| c1 > c2 = (a1, c1)
| otherwise = (a2, c2)
where
(a2, c2) = bestResult cs

contains :: Slovo -> [Slovo] -> Bool
contains _ [] = False
contains a (b:bs)
| a == b = True
| otherwise = contains a bs

extractBestResult :: Slovnik -> Slovo -> [Slovo] -> Slovo
extractBestResult slovnik a target
| contains a target = a
| otherwise = best
where
cetnost = findInDic slovnik a
cetnostSafe = intersectResult cetnost target
best = fst $ bestResult cetnostSafe

-- tady bud muzeme ponechavat celou vetu, nebo postupne odebírat již zarovnaná slova
-- v případě odebírání však systém přestane fungovat u gramatických konstruktů
getAlignmentSentence :: Slovnik -> PrekladSlova -> AlignSlova
getAlignmentSentence _ ([], _) = []
getAlignmentSentence slovnik ((a:as), target) = (a, best):(getAlignmentSentence slovnik (as, target)) -- target misto remaining
where
best = (extractBestResult slovnik a target)

getAlignment :: PrekladySlova -> [AlignSlova]
getAlignment as = map (\x -> getAlignmentSentence slovnik x) as
where
slovnik = buildFreqDic as

-- splitSentence :: Slovo -> Slovo -> [Slovo]
-- splitSentence buff [] = buff
-- splitSentence buff (a:as)
-- | a == ' ' = ([buff]:(splitSentence [] as)
-- | otherwise = ([buff++[a]]:(splitSentence [] as)

-- formatInput :: PrekladyVety -> PrekladySlova
-- formatInput [] = []
-- formatInput ((a1,a2):as) = (splitSentence a1, splitSentence a2):(formatInput as)
