import Data.List
import Data.Char

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