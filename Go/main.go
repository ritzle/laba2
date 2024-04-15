package main

import (
	"fmt"
	"strings"
)

func main() {
	var task string
	fmt.Print("Enter task (1, 2, 3): ")
	fmt.Scanln(&task)

	switch task {
	case "1":
		task1()
	case "2":
		task2()
	case "3":
		task3()
	default:
		fmt.Println("Error")
	}
}

func task1() {
	var entStr string
	fmt.Print("Enter string: ")
	fmt.Scanln(&entStr)

	var realStr []rune
	realStr = append(realStr, []rune(entStr)[0])

	counterSymbolStr := 1
	counterAddSymbol := 0

	for i := 1; i < len(entStr); i++ {
		if entStr[i] == entStr[i-1] {
			if counterSymbolStr == 2 {
				counterSymbolStr = 1
				realStr = append(realStr, rune(entStr[i]+1))
				realStr = append(realStr, rune(entStr[i]))
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

	fmt.Printf("Result: %d = %s\n", counterAddSymbol, string(realStr))
}

func task2() {
	morseCode := map[rune]string{
		'A': "*-",
		'B': "-***",
		'W': "*--",
		'G': "--*",
		'D': "-**",
		'E': "*",
		'V': "***-",
		'Z': "--**",
		'I': "**",
		'J': "*---",
		'K': "-*-",
		'L': "*-**",
		'M': "--",
		'N': "-*",
		'O': "---",
		'P': "*--*",
		'R': "*-*",
		'S': "***",
		'T': "-",
		'U': "**-",
		'F': "**-*",
		'H': "****",
		'C': "-*-*",
		'Q': "--*-",
		'Y': "-*--",
		'X': "-**-",
		'1': "*----",
		'2': "**---",
		'3': "***--",
		'4': "****-",
		'5': "*****",
		'6': "-****",
		'7': "--***",
		'8': "---**",
		'9': "----*",
		'0': "-----",
	}

	var entStr string
	fmt.Print("Enter string: ")
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
		morseResult := morseTranslation(permutation, morseCode)
		fmt.Printf(" %s  =  %s\n", permutation, morseResult)

		mapWordMorse[morseResult]++
	}
}

func morseTranslation(word string, morseCode map[rune]string) string {
	var wordMorse string
	for _, ch := range word {
		wordMorse += morseCode[ch]
	}
	return wordMorse
}

func getUniquePermutations(word string) []string {
	var permutations []string
	getUniquePermutationsHelper([]rune(word), 0, len(word)-1, &permutations)
	return removeDuplicates(permutations)
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

func removeDuplicates(elements []string) []string {
	encountered := map[string]bool{}
	result := []string{}

	for v := range elements {
		if encountered[elements[v]] == false {
			encountered[elements[v]] = true
			result = append(result, elements[v])
		}
	}
	return result
}

func task3() {
	var amountNumbers int
	fmt.Print("Enter the number of numbers: ")
	fmt.Scanln(&amountNumbers)

	var vectorOddNumbers []int

	for i := 0; i < amountNumbers; i++ {
		var entNumbers int
		fmt.Print("Enter number: ")
		fmt.Scanln(&entNumbers)
		vectorOddNumbers = append(vectorOddNumbers, counterOddNumbers(entNumbers))
	}

	fmt.Println(vectorOddNumbers)
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
