#include <iostream>
#include <string>
#include <windows.h>
#include <math.h>

using namespace std;

string encrypt(string value)
{
    string temp = value;
    for (int i = 0; i < 4; i++)
    {
        temp[i] = ((temp[i] - '0' + 7) % 10) + '0';
    }
    for (int i = 0; i < 2; i++)
    {
        swap(temp[i], temp[i + 2]);
    }
    return temp;
}

string decrypt(string value)
{
    string temp = value;
    for (int i = 0; i < 2; i++)
    {
        swap(temp[i], temp[i + 2]);
    }
    for (int i = 0; i < 4; i++)
    {
        int t = temp[i] - '0';
        int b;
        if ((t + 10) - 7 > 10)
            b = t - 7;
        else
            b = (t + 10) - 7;
        temp[i] = b + '0';
    }

    return temp;
}

int main()
{
    srand(time(0));
    setlocale(LC_ALL, "Russian");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    string input;
    cin >> input;
    cout << "Шифруем - " << encrypt(input) << endl;
    input = encrypt(input);
    cout << "Дешифруем - " << decrypt(input);
    
}

