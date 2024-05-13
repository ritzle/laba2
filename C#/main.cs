using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

class Program
{
    static void Main()
    {
        char task;
        Console.Write("Enter task (1, 2, 3): ");
        task = Console.ReadKey().KeyChar;

        switch (task)
        {
            case '1':
                Task1();
                break;

            case '2':
                Task2();
                break;

            case '3':
                Task3();
                break;

            default:
                Console.WriteLine("Error");
                break;
        }
    }

    static void Task1()
    {
        Console.Write("Enter string: ");
        string entStr = Console.ReadLine();

        List<char> realStr = new List<char>();
        realStr.Add(entStr[0]);

        int counterSymbolStr = 1;
        int counterAddSymbol = 0;

        for (int i = 1; i < entStr.Length; i++)
        {
            if (entStr[i] == entStr[i - 1])
            {
                if (counterSymbolStr == 2)
                {
                    counterSymbolStr = 1;
                    realStr.Add((char)(entStr[i] + 1));
                    realStr.Add(entStr[i]);
                    counterAddSymbol++;
                }
                else
                {
                    counterSymbolStr++;
                    realStr.Add(entStr[i]);
                }
            }
            else
            {
                counterSymbolStr = 1;
                realStr.Add(entStr[i]);
            }
        }

        Console.Write("Result: " + counterAddSymbol + " = ");
        foreach (var ch in realStr)
        {
            Console.Write(ch);
        }
    }

static void Task2()
    {
        Dictionary<char, string> morseCode = new Dictionary<char, string>
        {
            {'A', "*-"},
            {'B', "-***"},
            {'W', "*--"},
            {'G', "--*"},
            {'D', "-**"},
            {'E', "*"},
            {'V', "***-"},
            {'Z', "--**"},
            {'I', "**"},
            {'J', "*---"},
            {'K', "-*-"},
            {'L', "*-**"},
            {'M', "--"},
            {'N', "-*"},
            {'O', "---"},
            {'P', "*--*"},
            {'R', "*-*"},
            {'S', "***"},
            {'T', "-"},
            {'U', "**-"},
            {'F', "**-*"},
            {'H', "****"},
            {'C', "-*-*"},
            {'Q', "--*-"},
            {'Y', "-*--"},
            {'X', "-**-"},
            {'1', "*----"},
            {'2', "**---"},
            {'3', "***--"},
            {'4', "****-"},
            {'5', "*****"},
            {'6', "-****"},
            {'7', "--***"},
            {'8', "---**"},
            {'9', "----*"},
            {'0', "-----"}
        };

        Console.Write("Enter string: ");
        string entStr = Console.ReadLine();

        if (entStr.Length < 1 || entStr.Length > 100)
        {
            Console.WriteLine("Error");
            return;
        }

        string[] words = entStr.Split(' ');

        Dictionary<string, int> mapWordMorse = new Dictionary<string, int>();

        foreach (string word in words)
        {
            if (word.Length >= 1 && word.Length <= 12)
            {
                WordMorseCombinations(word, mapWordMorse, morseCode);
                Console.WriteLine();
            }
        }

        int uniqueWordCounter = mapWordMorse.Count(kv => kv.Value == 1);
        Console.WriteLine("Result: " + uniqueWordCounter);
    }

static void WordMorseCombinations(string word, Dictionary<string, int> mapWordMorse, Dictionary<char, string> morseCode)
{

    var uniquePermutations = GetUniquePermutations(word);

    foreach (var permutation in uniquePermutations)
    {
        string morseResult = MorseTranslation(permutation, morseCode);
        Console.WriteLine(" " + permutation + "  =  " + morseResult);

        // Проверка наличия слова в словаре и его добавление или увеличение счетчика
        if (!mapWordMorse.ContainsKey(morseResult))
        {
            mapWordMorse.Add(morseResult, 1);
        }
        else
        {
            mapWordMorse[morseResult]++;
        }
    }



}

    static string MorseTranslation(string word, Dictionary<char, string> morseCode)
    {
        string wordMorse = "";
        foreach (char ch in word)
        {
            wordMorse += morseCode[char.ToUpper(ch)];
        }
        return wordMorse;
    }


// Method to swap two characters using XOR operation
    private static void Swap(ref char a, ref char b)
    {
        if (a == b) return; // No need to swap if the characters are the same

        a ^= b; // XOR operation to swap characters
        b ^= a;
        a ^= b;
    }

    // Method to get unique permutations of characters in the list
    public static List<string> GetUniquePermutations(string word)
    {
        var permutations = new List<string>();
        GetUniquePermutations(word.ToCharArray(), 0, word.Length - 1, permutations);
        return permutations.Distinct().ToList();
    }

    // Recursive method to generate unique permutations
    private static void GetUniquePermutations(char[] list, int k, int m, List<string> result)
    {
        if (k == m)
        {
            result.Add(new string(list));
        }
        else
        {
            for (int i = k; i <= m; i++)
            {
                Swap(ref list[k], ref list[i]);
                GetUniquePermutations(list, k + 1, m, result);
                Swap(ref list[k], ref list[i]);
            }
        }
    }

    static void Task3()
    {
        Console.Write("Enter the number of numbers: ");
        int amountNumbers = int.Parse(Console.ReadLine());

        //List<int> vectorOddNumbers = new List<int>();

        for (int i = 0; i < amountNumbers; i++)
        {
            int entNumbers = int.Parse(Console.ReadLine());
            Console.Write("Number of odd digits: " + CounterOddNumbers(entNumbers) + "\n");
            //vectorOddNumbers.Add(CounterOddNumbers(entNumbers));
        }

        // foreach (int oddNumbers in vectorOddNumbers)
        // {
        //     Console.Write(oddNumbers + " ");
        // }
    }

    static int CounterOddNumbers(int number)
    {
        int counterOddNumbers = 0;

        while (number != 0)
        {
            if ((number % 10) % 2 != 0)
            {
                counterOddNumbers++;
            }
            number /= 10;
        }

        return counterOddNumbers;
    }

}