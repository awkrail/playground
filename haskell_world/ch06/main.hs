import Data.List
import Data.Char
import qualified Data.Map as Map

wordNum :: String -> [(String, Int)]
wordNum = map (\xs -> (head xs, length xs)) . group . sort . words

isIn' :: (Eq a) => [a] -> [a] -> Bool
needle `isIn'` haystack = any (needle `isPrefixOf`) $ tails haystack

encode :: Int -> String -> String
encode offset msg = map (\c -> chr $ ord c + offset) msg

decode :: Int -> String -> String
decode shift msg = encode (negate shift) msg

digitSum :: Int -> Int
digitSum = sum . map digitToInt . show

firstTo40 :: Maybe Int
firstTo40 = find (\x -> digitSum x == 40) [1..]

findKey :: (Eq k) => k -> [(k, v)] -> Maybe v
findKey key [] = Nothing
findKey key ((k,v):xs)
    | key == k  = Just v
    | otherwise = findKey key xs

findKey' :: (Eq k) => k -> [(k, v)] -> Maybe v
findKey' key xs = foldr (\(k, v) acc -> if k == key then Just v else acc) Nothing xs

phoneBook :: Map.Map String String
phoneBook = Map.fromList $ [
    ("taichi", "555-29292"),
    ("bonnie", "452-2928"),
    ("pasty", "493-2985")]

string2digits :: String -> [Int]
string2digits = map digitToInt . filter isDigit