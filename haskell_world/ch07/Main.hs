import Shapes
import qualified Data.Map as Map

data Vector a = Vector a a a deriving (Show)

data Person = Person { 
    firstName :: String,
    lastName :: String,
    age :: Int                   
} deriving (Eq, Show)

data Day = Monday | Tuesday | Wednesday | Thursday | Friday | Saturday | Sunday
            deriving (Eq, Ord, Show, Read, Bounded, Enum)

type PhoneNumber = String
type Name = String
type PhoneBook = [(Name, PhoneNumber)]

inPhoneBook :: Name -> PhoneNumber -> PhoneBook -> Bool
isPhoneBook name pnumber pbook = (name, pnumber) `elem` pbook

data LockerState = Taken | Free deriving (Show, Eq)
type Code = String
type LockerMap = Map.Map Int (LockerState, Code)

lockerLookup :: Int -> LockerMap -> Either String Code
lockerLookup lockerNumber map = case Map.lookup lockerNumber map of
    Nothing -> Left $ "Locker " ++ show lockerNumber ++ " does not exist!"
    Just (state, code) -> if state /= Taken
                            then Right code
                            else Left $ "Locker " ++ show lockerNumber ++ " is already taken!"

vplus :: (Num a) => Vector a -> Vector a -> Vector a
(Vector i j k) `vplus` (Vector l m n) = Vector (i+l) (j+m) (k+n)

dotProd :: (Num a) => Vector a -> Vector a -> a
(Vector i j k) `dotProd` (Vector l m n) = i*l + j*m + k*n

vmult :: (Num a) => Vector a -> a -> Vector a
(Vector i j k) `vmult` m = Vector (i*m) (j*m) (k*m)

main = do
    print $ nudge (baseCircle 30) 10 20
