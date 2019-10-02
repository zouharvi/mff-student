data Trie k v = TrieEmpty | TrieList k (Trie k v) (Trie k v) | TrieValue v deriving (Show)

empty :: Trie k v
empty = TrieEmpty

singleton :: [k] -> v -> Trie k v
singleton [] v = TrieValue v
singleton (k:krest) v = TrieList k TrieEmpty (singleton krest v)

insertWith :: (Ord k) => (v -> v -> v) -> [k] -> v -> Trie k v -> Trie k v
insertWith f krest v TrieEmpty = singleton krest v
insertWith f [] v (TrieValue prev) = TrieValue (f v prev)
insertWith f [] v (TrieList x nextListTrie ptrTrie) = 
    TrieList x (insertWith f [] v nextListTrie) ptrTrie 
insertWith f (k:krest) v (TrieList x nextListTrie ptrTrie) = 
    if x == k
        then TrieList x nextListTrie (insertWith f krest v ptrTrie) 
        else TrieList x (insertWith f (k:krest) v nextListTrie) ptrTrie


disregardOld = \new old -> new
disregardNew = \new old -> old
insert :: (Ord k) => [k] -> v -> Trie k v -> Trie k v
insert k v trie = insertWith disregardOld k v trie

find :: (Ord k) => [k] -> Trie k v -> Maybe v
find (_:_) TrieEmpty = Nothing
find [] (TrieValue v) = Just v
find [] (TrieList _ _ _) = Nothing
find (_:_) (TrieValue _) = Nothing
find (k:krest) (TrieList x trieNext trieIn) =
    if x == k
        then find krest trieIn
        else find (k:krest) trieNext

member :: (Ord k) => [k] -> Trie k v -> Bool
member k t = case find k t of
    Just _ -> True
    Nothing -> False

fromList :: (Ord k) => [([k], v)] -> Trie k v
fromList [] = TrieEmpty
fromList ((krest, v):lrest) = insertWith disregardOld krest v (fromList lrest)
-- Toto by jistě šlo jednořádkové nějakým foldem, ale to mi nefungovalo.


-- Nefunguje dokonale. Nemaže celé větve, které existují jen kvůli klíči, který byl právě smazán.
-- Šlo by opravit sofistikovanějším mazáním, nebo _clean_ funkcí, která by každou Trii takto znormalizovala.
delete :: (Ord k) => [k] -> Trie k v -> Trie k v
delete [] TrieEmpty = TrieEmpty
delete [] (TrieValue _) = TrieEmpty
delete (k:_) TrieEmpty = TrieEmpty
delete (k:_) (TrieValue v) = TrieValue v
delete (k:krest) (TrieList x nextListTrie ptrTrie) =
    if x == k
        then TrieList x nextListTrie (delete krest ptrTrie) 
        else TrieList x (delete (k:krest) nextListTrie) ptrTrie