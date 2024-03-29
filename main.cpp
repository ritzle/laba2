#include <iostream>
#include <string>
#include <vector>

using namespace std;

void task1();

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