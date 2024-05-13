package main

import (
	"bufio"
	"fmt"
	"os"
	"unicode"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Print("Enter task (1, 2, 3): ")
	task, _ := reader.ReadByte()

	switch task {
	case '1':
		task1()
	case '2':
		task2()
	case '3':
		task3()
	default:
		fmt.Println("Error")
	}
}

func task1() {
	fmt.Print("Enter string: ")
	var entStr string
	fmt.Scanln(&entStr)

	realStr := []rune{rune(entStr[0])}
	counterSymbolStr := 1
	counterAddSymbol := 0

	for i := 1; i < len(entStr); i++ {
		if entStr[i] == entStr[i-1] {
			if counterSymbolStr == 2 {
				counterSymbolStr = 1
				realStr = append(realStr, rune(entStr[i])+1, rune(entStr[i]))
				counterAddSymbol++
			} else {
				counterSymbolStr++
				realStr = append(realStr, rune(entStr[i]))
			}
		} else {
			counterSymbolStr = 1
			realStr = append(realStr, rune(entStr[i]))
		}
	}

	fmt.Print("Result: ", counterAddSymbol, " = ")
	for _, ch := range realStr {
		fmt.Print(string(ch))
	}
	fmt.Println()
}

func task2() {
    morseCode := map[rune]string{
        'A': "*-", 'B': "-***", 'C': "-*-*", 'D': "-**", 'E': "*",
        'F': "**-*", 'G': "--*", 'H': "****", 'I': "**", 'J': "*---",
        'K': "-*-", 'L': "*-**", 'M': "--", 'N': "-*", 'O': "---",
        'P': "*--*", 'Q': "--*-", 'R': "*-*", 'S': "***", 'T': "-",
        'U': "**-", 'V': "***-", 'W': "*--", 'X': "-**-", 'Y': "-*--",
        'Z': "--**", '0': "-----", '1': "*----", '2': "**---", '3': "***--",
        '4': "****-", '5': "*****", '6': "-****", '7': "--***", '8': "---**",
        '9': "----*",
    }

    fmt.Print("Enter string: ")
    var entStr string
    fmt.Scanln(&entStr)

    if len(entStr) < 1 || len(entStr) > 100 {
        fmt.Println("Error")
        return
    }

    words := strings.Split(entStr, " ")
    mapWordMorse := make(map[string]int)

    for _, word := range words {
        if len(word) >= 1 && len(word) <= 12 {
            wordMorseCombinations(word, mapWordMorse, morseCode)
            fmt.Println()
        }
    }

    uniqueWordCounter := 0
    for _, v := range mapWordMorse {
        if v == 1 {
            uniqueWordCounter++
        }
    }
    fmt.Println("Result:", uniqueWordCounter)
}

func wordMorseCombinations(word string, mapWordMorse map[string]int, morseCode map[rune]string) {
    uniquePermutations := getUniquePermutations(word)

    for _, permutation := range uniquePermutations {
        morseResult := getMorseRepresentation(permutation, morseCode)
        fmt.Printf(" %s  =  %s\n", permutation, morseResult)
        mapWordMorse[morseResult]++
    }
}

func getMorseRepresentation(word string, morseCode map[rune]string) string {
    var sb strings.Builder
    for _, ch := range word {
        sb.WriteString(morseCode[unicode.ToUpper(ch)])
    }
    return sb.String()
}

func getUniquePermutations(word string) []string {
    var permutations []string
    getUniquePermutationsHelper([]rune(word), 0, len(word)-1, &permutations)
    uniquePermutations := make(map[string]bool)
    for _, perm := range permutations {
        uniquePermutations[perm] = true
    }
    result := make([]string, 0, len(uniquePermutations))
    for perm := range uniquePermutations {
        result = append(result, perm)
    }
    return result
}

func getUniquePermutationsHelper(list []rune, k, m int, result *[]string) {
    if k == m {
        *result = append(*result, string(list))
    } else {
        for i := k; i <= m; i++ {
            swap(list, k, i)
            getUniquePermutationsHelper(list, k+1, m, result)
            swap(list, k, i)
        }
    }
}

func swap(list []rune, a, b int) {
    if list[a] == list[b] {
        return
    }
    list[a], list[b] = list[b], list[a]
}


func task3() {
	var amountNumbers int
	fmt.Print("Enter the number of numbers: ")
	fmt.Scanln(&amountNumbers)

	for i := 0; i < amountNumbers; i++ {
		var entNumbers int
		fmt.Print("Enter number: ")
		fmt.Scanln(&entNumbers)
		fmt.Println("Number of odd digits:", counterOddNumbers(entNumbers))
	}
}

func counterOddNumbers(number int) int {
	counterOddNumbers := 0

	for number != 0 {
		if (number % 10) % 2 != 0 {
			counterOddNumbers++
		}
		number /= 10
	}

	return counterOddNumbers
}
