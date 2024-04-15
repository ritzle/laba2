#include <iostream>
#include <stdio.h>

#include <string>
#include <vector>
#include <sstream> //для разделение строки
#include <cctype>  //перевод регистров
#include <algorithm>
#include <map>
#include <set>

using namespace std;

void task1();
void task2();
void task3();

int counterOddNumbers(int number);
string morseTranslation(string word, map<char, string> &morseCode);
void WordMorseCombinations(string word, map<string, int> &mapWordMorse, map<char, string> &morseCode);

int main()
{
    setlocale(LC_ALL, "RUS");
    system("chcp 1251");

    char task;
    cout << "Enter task (1, 2, 3): ";
    cin >> task;
    cin.ignore(); // иначе в буфере остается символ \n

    switch (task) // для выбора задания
    {
    case '1':
        task1();
        break;

    case '2':
        task2();
        break;

    case '3':
        task3();
        break;

    default:
        cout << "Error";
    }

    return 0;
}

void task1()
{

    string entStr;
    cout << "Enter string: ";
    getline(cin, entStr);

    vector<char> realStr;

    realStr.push_back(entStr[0]); // первая буква строки

    int counterSymbolStr = 1; // счетчик повторяющихся букв
    int counterAddSymbol = 0; // счетчик добавленных букв

    // посимвольно идем по строке, и проверяем совпадает ли символ с предыдущим
    for (int i = 1; i < entStr.length(); i++)
    {
        if (entStr[i] == entStr[i - 1])
        {
            if (counterSymbolStr == 2)
            {
                counterSymbolStr = 1;
                realStr.push_back(entStr[i] + 1); // берем следующий символ по аски что бы не повторились
                realStr.push_back(entStr[i]);
                counterAddSymbol++;
            }
            else
            {
                counterSymbolStr++;
                realStr.push_back(entStr[i]);
            }
        }
        else
        {
            counterSymbolStr = 1;
            realStr.push_back(entStr[i]);
        }
    }

    // собираем строку из vectora
    cout << "Resul: " << counterAddSymbol << " = ";
    for (auto i : realStr)
    {
        cout << i;
    }
}

void task2()
{

    map<char, string> morseCode = {
        // шифр морзе
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
        {'0', "-----"}};

    string entStr;
    cout << "Enter string: ";
    getline(cin, entStr);

    if (1 > entStr.length() || entStr.length() > 100) // проверка на ограничение
    {
        cout << "Error";
        return;
    }

    istringstream iss(entStr); // позволяет работать с строкой как с потоком ввода

    if (!iss) // проверка ограничений
    {
        cout << "Error";
        return;
    }

    string word; // слово из строки entStr

    map<string, int> mapWordMorse;

    while (iss >> word)
    {
        if (1 <= word.size() && word.size() <= 12)
        {
            WordMorseCombinations(word, mapWordMorse, morseCode);
            cout << endl;
        }
    }

    // вывод
    int uniqueWordCounter = 0;

    for (auto i : mapWordMorse)
    {
        if (i.second == 1)
        {
            uniqueWordCounter++;
            // cout << i.first << "   ";
        }
    }

    cout << "Result: " << uniqueWordCounter;
}

void WordMorseCombinations(string word, map<string, int> &mapWordMorse, map<char, string> &morseCode)
{
    sort(word.begin(), word.end());

    do
    {
        string morseResult = morseTranslation(word, morseCode);
        cout << " " << word << "  =  " << morseResult << endl;
        mapWordMorse[morseResult]++;
    } while (next_permutation(word.begin(), word.end()));
}

string morseTranslation(string word, map<char, string> &morseCode)
{

    string wordMorse;

    for (int i = 0; i < word.length(); i++)
    {
        wordMorse += morseCode[toupper(word[i])];
    }

    return wordMorse;
}

void task3()
{

    cout << "Enter the number of numbers: ";

    int amountNumbers;
    char isCheckChar;

    if (scanf("%d%c", &amountNumbers, &isCheckChar) == 2 && (isCheckChar == ' ' || isCheckChar == '\n') && amountNumbers > 0)
    {
        cout << "Enter numbers: ";
        vector<int> vectorOddNumbers;

        for (int i = 0; i < amountNumbers; i++)
        {

            int entNumbers;

            if (scanf("%d%c", &entNumbers, &isCheckChar) == 2 && (isCheckChar == ' ' || isCheckChar == '\n') && entNumbers > 0)
            {
                vectorOddNumbers.push_back(counterOddNumbers(entNumbers));
            }
            else
            {
                cout << "Error";
                return;
            }
        }

        for (auto oddNumbers : vectorOddNumbers)
        {
            cout << oddNumbers << " ";
        }
    }
    else
    {
        cout << "Error";
        return;
    }
}

int counterOddNumbers(int number)
{

    int counterOddNumbers = 0;

    while (number)
    {

        if ((number % 10) % 2 != 0)
        {
            counterOddNumbers++;
        }

        number /= 10;
    }

    return counterOddNumbers;
}