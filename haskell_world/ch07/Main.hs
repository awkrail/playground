import Shapes

data Person = Person {
    firstName :: String,
    lastName :: String,
    age :: Int,
    height :: Float,
    phoneNumber :: String,
    flavor :: String } deriving (Show)

main = do
    print $ nudge (baseCircle 30) 10 20
