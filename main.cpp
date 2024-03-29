#include <iostream>
#include <string>
#include <vector>
#include <sstream> //для разделение строки
#include <cctype>  //перевод ригистров
#include <map>
#include <set>

using namespace std;

void task1();
void task2();

int main()
{
    setlocale(LC_ALL, "RUS");
    system("chcp 1251");

    char task;
    cout << "Enter task: ";
    cin >> task;
    cin.ignore(); // иначе в буфере остается символ \n

    switch (task)
    {
    case '1':
        task1();
        break;

    case '2':
        task2();
        break;

    case '3':
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
    int counterAddSymbol = 0;

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

    cout << "Resul: " << counterAddSymbol << " = ";
    for (auto i : realStr)
    {
        cout << i;
    }
}

void task2()
{

    map<char, string> morseCode = {
        {'A', "*-"}, {'B', "-***"}, {'W', "*--"}, {'G', "--*"}, {'D', "-**"}, {'E', "*"}, {'V', "***-"}, {'Z', "--**"}, {'I', "**"}, {'J', "*---"}, {'K', "-*-"}, {'L', "*-**"}, {'M', "--"}, {'N', "-*"}, {'O', "---"}, {'P', "*--*"}, {'R', "*-*"}, {'S', "***"}, {'T', "-"}, {'U', "**-"}, {'F', "**-*"}, {'H', "****"}, {'C', "-*-*"}, {'Q', "--*-"}, {'Y', "-*--"}, {'X', "-**-"}};

    string entStr;
    cout << "Enter string: ";
    getline(cin, entStr);

    if (1 > entStr.length() || entStr.length() > 100)
    {
        cout << "Error";
        return;
    }

    istringstream iss(entStr); // позволяет работать с строкой как с потоком ввода
    vector<string> splitWordEntStr;

    string word; // слово из строки entStr

    while (iss >> word)
    {
        if (1 <= word.size() && word.size() <= 12)
        {
            splitWordEntStr.push_back(word);
        }
        else
        {
            continue;
        }
        // word.length() <= 11 ? splitWordEntStr.push_back(word) : continue;???
    }

    if (splitWordEntStr.size() == 0)
    {
        cout << "Error";
        return;
    }

    set<string> setWordMorse;
    string wordMorse;

    for (auto x : splitWordEntStr)
    {
        for (int i = 0; i < x.length(); i++)
        {
            wordMorse += morseCode[toupper(x[i])];
        }
        setWordMorse.insert(wordMorse);
        wordMorse = "";
    }

    cout << "Resul: " << setWordMorse.size() << " = ";
    for (auto i : setWordMorse)
    {
        cout << i << " ";
    }
}