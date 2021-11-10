#include <iostream>
#include <string>
#include <Windows.h>
#include <conio.h>

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string s, f;
    int count = 0, exc, i = 0, j = 0;;
    int pr = 1;

    do {
        cout << "Введите предложение: " << endl;
        getline(cin, s);
    } while (s.empty());
    
    do
    {
        cout << "Введите ограничение: " << endl;
        getline(cin, f);
    } while (f.empty());
    exc = atoi(f.c_str());
    string* str = new string[s.size()];

    while (s[i] != '\0')                            //obrabotka vvodimoi ctroki
    {
        while (s[i] == ',' or s[i] == '.' or s[i] == ';' or s[i] == '\"' or s[i] == ' ')//перепрыгивает разделители
        {
            j++;
            i++;
        }
        str[j] += s[i];
        pr = j + 1;
        i++;
    }
    
    for (int i = 0; i < pr; i++) // Работает пока не закончатся слова в массиве
    {
        for (int j = 0; j < pr; j++) // Ищетв в строке первое повторяющееся n раз слово
        {
            if (i == j) j++;
            if (str[i] == str[j])
            {
                s = str[i];
            }
        }
        for (int j = 0; j < pr; j++)
        {
            if (str[j] == s)
            {
                str[j] = "";
            }
        }
    }
    cout << "BOT: " << endl;
    for (size_t i = 0; i < pr; i++)
    {
        if (str[i] != "")
        {
            cout << str[i] << ' ';
        }
    }
    delete[] str;

}