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