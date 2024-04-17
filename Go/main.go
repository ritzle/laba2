package main

import (
	"fmt"
	"strings"
)

func main() {
	var task rune
	fmt.Print("Enter task (1, 2, 3): ")
	fmt.Scanf("%c", &task)

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
	var entStr string
	fmt.Print("Enter string: ")
	if _, err := fmt.Scanln(&entStr); err != nil {
		fmt.Println("Error:", err)
		return
	}

	if len(entStr) == 0 {
		fmt.Println("Error: String cannot be empty")
		return
	}

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
	if _, err := fmt.Scanln(&entStr); err != nil {
		fmt.Println("Error:", err)
		return
	}

	if len(entStr) < 1 || len(entStr) > 100 {
		fmt.Println("Error: Input length out of range")
		return
	}

	words := strings.Fields(entStr)
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
	fmt.Printf("Result: %d\n", uniqueWordCounter)
}

func wordMorseCombinations(word string, mapWordMorse map[string]int, morseCode map[rune]string) {
	uniquePermutations := getUniquePermutations(word)

	for _, permutation := range uniquePermutations {
		morseResult := morseTranslation(permutation, morseCode)
		fmt.Printf(" %s = %s\n", permutation, morseResult)

		mapWordMorse[morseResult]++
	}
}

func morseTranslation(word string, morseCode map[rune]string) string {
	var wordMorse strings.Builder
	for _, ch := range word {
		wordMorse.WriteString(morseCode[ch])
	}
	return wordMorse.String()
}

func getUniquePermutations(word string) []string {
	var permutations []string
	getUniquePermutationsHelper([]rune(word), 0, len(word)-1, &permutations)
	return unique(permutations)
}

func getUniquePermutationsHelper(list []rune, k, m int, result *[]string) {
	if k == m {
		*result = append(*result, string(list))
	} else {
		for i := k; i <= m; i++ {
			swap(&list[k], &list[i])
			getUniquePermutationsHelper(list, k+1, m, result)
			swap(&list[k], &list[i])
		}
	}
}

func swap(a, b *rune) {
	if *a == *b {
		return
	}
	*a, *b = *b, *a
}

func unique(slice []string) []string {
	keys := make(map[string]bool)
	list := []string{}
	for _, entry := range slice {
		if _, value := keys[entry]; !value {
			keys[entry] = true
			list = append(list, entry)
		}
	}
	return list
}

func task3() {
	var amountNumbers int
	fmt.Print("Enter the number of numbers: ")
	if _, err := fmt.Scanln(&amountNumbers); err != nil {
		fmt.Println("Error:", err)
		return
	}

	vectorOddNumbers := make([]int, 0, amountNumbers)

	for i := 0; i < amountNumbers; i++ {
		var entNumbers int
		fmt.Print("Enter number: ")
		if _, err := fmt.Scanln(&entNumbers); err != nil {
			fmt.Println("Error:", err)
			return
		}
		vectorOddNumbers = append(vectorOddNumbers, counterOddNumbers(entNumbers))
	}

	for _, oddNumbers := range vectorOddNumbers {
		fmt.Printf("%d ", oddNumbers)
	}
}

func counterOddNumbers(number int) int {
	counterOddNumbers := 0
	num := number

	for num != 0 {
		if (num % 10) % 2 != 0 {
			counterOddNumbers++
		}
		num /= 10
	}

	return counterOddNumbers
}
