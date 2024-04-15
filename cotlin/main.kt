import java.util.*

fun main() {
    val scanner = Scanner(System.`in`)
    print("Enter task (1, 2, 3): ")
    val task = scanner.nextLine()[0]

    when (task) {
        '1' -> task1()
        '2' -> task2()
        '3' -> task3()
        else -> println("Error")
    }
}

fun task1() {
    val scanner = Scanner(System.`in`)
    print("Enter string: ")
    val entStr = scanner.nextLine()

    val realStr = mutableListOf<Char>()
    realStr.add(entStr[0])

    var counterSymbolStr = 1
    var counterAddSymbol = 0

    for (i in 1 until entStr.length) {
        if (entStr[i] == entStr[i - 1]) {
            if (counterSymbolStr == 2) {
                counterSymbolStr = 1
                realStr.add((entStr[i] + 1).toChar())
                realStr.add(entStr[i])
                counterAddSymbol++
            } else {
                counterSymbolStr++
                realStr.add(entStr[i])
            }
        } else {
            counterSymbolStr = 1
            realStr.add(entStr[i])
        }
    }

    print("Result: $counterAddSymbol = ")
    realStr.forEach { print(it) }
}

fun task2() {
    val scanner = Scanner(System.`in`)
    val morseCode = hashMapOf(
        'A' to "*-",
        'B' to "-***",
        'W' to "*--",
        'G' to "--*",
        'D' to "-**",
        'E' to "*",
        'V' to "***-",
        'Z' to "--**",
        'I' to "**",
        'J' to "*---",
        'K' to "-*-",
        'L' to "*-**",
        'M' to "--",
        'N' to "-*",
        'O' to "---",
        'P' to "*--*",
        'R' to "*-*",
        'S' to "***",
        'T' to "-",
        'U' to "**-",
        'F' to "**-*",
        'H' to "****",
        'C' to "-*-*",
        'Q' to "--*-",
        'Y' to "-*--",
        'X' to "-**-",
        '1' to "*----",
        '2' to "**---",
        '3' to "***--",
        '4' to "****-",
        '5' to "*****",
        '6' to "-****",
        '7' to "--***",
        '8' to "---**",
        '9' to "----*",
        '0' to "-----"
    )

    print("Enter string: ")
    val entStr = scanner.nextLine()

    if (entStr.length < 1 || entStr.length > 100) {
        println("Error")
        return
    }

    val words = entStr.split(" ")

    val mapWordMorse = hashMapOf<String, Int>()

    words.forEach { word ->
        if (word.length in 1..12) {
            wordMorseCombinations(word, mapWordMorse, morseCode)
            println()
        }
    }

    val uniqueWordCounter = mapWordMorse.values.count { it == 1 }
    println("Result: $uniqueWordCounter")
}

fun wordMorseCombinations(word: String, mapWordMorse: MutableMap<String, Int>, morseCode: Map<Char, String>) {
    val uniquePermutations = getUniquePermutations(word)

    uniquePermutations.forEach { permutation ->
        val morseResult = morseTranslation(permutation, morseCode)
        println(" $permutation  =  $morseResult")

        mapWordMorse.merge(morseResult, 1, Integer::sum)
    }
}

fun morseTranslation(word: String, morseCode: Map<Char, String>): String {
    val wordMorse = StringBuilder()
    word.forEach { ch ->
        wordMorse.append(morseCode.getOrDefault(ch.toUpperCase(), ""))
    }
    return wordMorse.toString()
}

fun getUniquePermutations(word: String): List<String> {
    val permutations = mutableListOf<String>()
    getUniquePermutationsHelper(word.toCharArray(), 0, word.length - 1, permutations)
    return permutations.toSet().toList()
}

private fun getUniquePermutationsHelper(list: CharArray, k: Int, m: Int, result: MutableList<String>) {
    if (k == m) {
        result.add(String(list))
    } else {
        for (i in k..m) {
            list.swap(k, i)
            getUniquePermutationsHelper(list, k + 1, m, result)
            list.swap(k, i)
        }
    }
}

private fun CharArray.swap(a: Int, b: Int) {
    if (this[a] == this[b]) return // No need to swap if the characters are the same

    this[a] = (this[a].toInt() xor this[b].toInt()).toChar() // XOR operation to swap characters
    this[b] = (this[b].toInt() xor this[a].toInt()).toChar()
    this[a] = (this[a].toInt() xor this[b].toInt()).toChar()
}

fun task3() {
    val scanner = Scanner(System.`in`)
    print("Enter the number of numbers: ")
    val amountNumbers = scanner.nextLine().toInt()

    val vectorOddNumbers = mutableListOf<Int>()

    repeat(amountNumbers) {
        print("Enter number: ")
        val entNumbers = scanner.nextLine().toInt()
        vectorOddNumbers.add(counterOddNumbers(entNumbers))
    }

    vectorOddNumbers.forEach { print("$it ") }
}

fun counterOddNumbers(number: Int): Int {
    var counterOddNumbers = 0
    var num = number
    while (num != 0) {
        if ((num % 10) % 2 != 0) {
            counterOddNumbers++
        }
        num /= 10
    }
    return counterOddNumbers
}
