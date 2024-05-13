
{-
import Data.Char (digitToInt)

main :: IO ()
main = task3

task3 :: IO ()
task3 = do
    putStrLn "Enter the number of numbers: "
    amountNumbers <- readLn :: IO Int
    vectorOddNumbers <- fmap (map counterOddNumbers) (sequence (replicate amountNumbers readLn :: [IO Int]))
    mapM_ (putStr . (++ " ") . show) vectorOddNumbers
    putStrLn ""

counterOddNumbers :: Int -> Int
counterOddNumbers = length . filter odd . map digitToInt . show

-}



import Data.Char (digitToInt)
import System.Exit (exitFailure)

main :: IO ()
main = task3

task3 :: IO ()
task3 = do
    putStr "Enter the number of numbers: "
    amountNumbers <- readInteger
    sequence_ [processNumber i | i <- [1..amountNumbers]]

readInteger :: IO Int
readInteger = do
    input <- getLine
    case reads input of
        [(n, "")] -> return n
        _ -> do
            putStrLn "Error"
            exitFailure

processNumber :: Int -> IO ()
processNumber _ = do
    putStr "Enter number: "
    enteredNumber <- readInteger
    let oddCount = counterOddNumbers enteredNumber
    putStrLn $ "Number of odd digits: " ++ show oddCount

counterOddNumbers :: Int -> Int
counterOddNumbers 0 = 0
counterOddNumbers n = length $ filter odd $ map digitToInt $ show n
