#include <iostream>
#include <string>
#include <vector>
#include <sstream> //для разделение строки
#include <cctype>  //перевод регистров
#include <map>
#include <set>

using namespace std;

void task1();
void task2();
void task3();

int counterOddNumbers(int number);
string morseTranslation(string word, map<char, string> &morseCode);
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

    map<char, string> morseCode = {// шифр морзе
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
                                   {'X', "-**-"}};

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

    set<string> setWordMorse; // множество уникальных слов в морзе
    string word;              // слово из строки entStr

    while (iss >> word)
    {
        if (1 <= word.size() && word.size() <= 12)
        {
            string morseResult = morseTranslation(word, morseCode);
            setWordMorse.insert(morseResult);
            // setWordMorse.insert(morseTranslation(word, morseCode));
        }
    }

    // вывод
    cout << "Resul: " << setWordMorse.size() << " = ";
    for (auto i : setWordMorse)
    {
        cout << i << " ";
    }
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

    cout << "Enter numbers: ";
    string strNumbers;
    getline(cin, strNumbers);

    istringstream iss(strNumbers); // позволяет работать с строкой как с потоком ввода

    int number; // число из строки entStr

    cout << "Resul: ";
    while (iss >> number)
    {
        cout << counterOddNumbers(number) << " ";
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