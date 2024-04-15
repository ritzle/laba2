import Foundation

func main() {
    print("Enter task (1, 2, 3): ", terminator: "")
    if let task = readLine(), let taskChar = task.first {
        switch taskChar {
        case "1":
            task1()
        case "2":
            task2()
        case "3":
            task3()
        default:
            print("Error")
        }
    }
}

func task1() {
    print("Enter string: ", terminator: "")
    if let entStr = readLine() {
        var realStr: [Character] = [entStr.first!]
        var counterSymbolStr = 1
        var counterAddSymbol = 0
        
        for i in 1..<entStr.count {
            let currentChar = entStr[entStr.index(entStr.startIndex, offsetBy: i)]
            let previousChar = entStr[entStr.index(entStr.startIndex, offsetBy: i - 1)]
            
            if currentChar == previousChar {
                if counterSymbolStr == 2 {
                    counterSymbolStr = 1
                    realStr.append(Character(UnicodeScalar(Int(previousChar.asciiValue!) + 1)!))
                    realStr.append(previousChar)
                    counterAddSymbol += 1
                } else {
                    counterSymbolStr += 1
                    realStr.append(previousChar)
                }
            } else {
                counterSymbolStr = 1
                realStr.append(currentChar)
            }
        }
        
        print("Result: \(counterAddSymbol) = \(String(realStr))")
    }
}

func task2() {
    let morseCode: [Character: String] = [
        "A": "*-", "B": "-***", "W": "*--", "G": "--*", "D": "-**",
        "E": "*", "V": "***-", "Z": "--**", "I": "**", "J": "*---",
        "K": "-*-", "L": "*-**", "M": "--", "N": "-*", "O": "---",
        "P": "*--*", "R": "*-*", "S": "***", "T": "-", "U": "**-",
        "F": "**-*", "H": "****", "C": "-*-*", "Q": "--*-", "Y": "-*--",
        "X": "-**-", "1": "*----", "2": "**---", "3": "***--", "4": "****-",
        "5": "*****", "6": "-****", "7": "--***", "8": "---**", "9": "----*",
        "0": "-----"
    ]
    
    print("Enter string: ", terminator: "")
    if let entStr = readLine(), entStr.count >= 1, entStr.count <= 100 {
        let words = entStr.split(separator: " ")
        var mapWordMorse = [String: Int]()
        
        for word in words {
            let wordString = String(word)
            if wordString.count >= 1 && wordString.count <= 12 {
                wordMorseCombinations(word: wordString, mapWordMorse: &mapWordMorse, morseCode: morseCode)
                print()
            }
        }
        
        let uniqueWordCounter = mapWordMorse.values.filter { $0 == 1 }.count
        print("Result: \(uniqueWordCounter)")
    } else {
        print("Error")
    }
}

func wordMorseCombinations(word: String, mapWordMorse: inout [String: Int], morseCode: [Character: String]) {
    let uniquePermutations = getUniquePermutations(word: word)
    
    for permutation in uniquePermutations {
        let morseResult = morseTranslation(word: permutation, morseCode: morseCode)
        print("\(permutation) = \(morseResult)")
        
        if let count = mapWordMorse[morseResult] {
            mapWordMorse[morseResult] = count + 1
        } else {
            mapWordMorse[morseResult] = 1
        }
    }
}

func morseTranslation(word: String, morseCode: [Character: String]) -> String {
    var wordMorse = ""
    for char in word.uppercased() {
        if let morseChar = morseCode[char] {
            wordMorse += morseChar
        }
    }
    return wordMorse
}

func getUniquePermutations(word: String) -> Set<String> {
    var permutations = Set<String>()
    var chars = Array(word)
    getUniquePermutationsHelper(chars: &chars, startIndex: 0, endIndex: chars.count - 1, result: &permutations)
    return permutations
}

func getUniquePermutationsHelper(chars: inout [Character], startIndex: Int, endIndex: Int, result: inout Set<String>) {
    if startIndex == endIndex {
        result.insert(String(chars))
    } else {
        for i in startIndex...endIndex {
            chars.swapAt(startIndex, i)
            getUniquePermutationsHelper(chars: &chars, startIndex: startIndex + 1, endIndex: endIndex, result: &result)
            chars.swapAt(startIndex, i)
        }
    }
}

func task3() {
    print("Enter the number of numbers: ", terminator: "")
    if let amountNumbersStr = readLine(), let amountNumbers = Int(amountNumbersStr) {
        var vectorOddNumbers = [Int]()
        
        for _ in 0..<amountNumbers {
            print("Enter number: ", terminator: "")
            if let entNumbersStr = readLine(), let entNumbers = Int(entNumbersStr) {
                vectorOddNumbers.append(counterOddNumbers(number: entNumbers))
            }
        }
        
        for oddNumbers in vectorOddNumbers {
            print("\(oddNumbers) ", terminator: "")
        }
    } else {
        print("Error")
    }
}

func counterOddNumbers(number: Int) -> Int {
    var counterOddNumbers = 0
    var num = number
    
    while num != 0 {
        if (num % 10) % 2 != 0 {
            counterOddNumbers += 1
        }
        num /= 10
    }
    
    return counterOddNumbers
}

main()
