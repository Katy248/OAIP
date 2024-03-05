#include <iostream>
#include <string>
#include <windows.h>
#include <math.h>

using namespace std;

string addValue(string value)
{
    string newNumber = "";
    string secondValue = value;
    bool flag = false;

    bool secFlag = false;
    std::reverse(secondValue.begin(), secondValue.end());
    for (long long i = value.length() - 1; i >= 0; i--)
    {
        int a = value[i] - '0';
        int b = secondValue[i] - '0';
        int val = a + b;
        if (flag)
        {
            val += 1;
            flag = false;
        }
        if (i == 0 && val >= 10)
        {
            secFlag = true;
        }
        if (val >= 10)
        {
            val -= 10;
            flag = true;
        }


        newNumber.push_back('0' + val);
    }
    std::reverse(newNumber.begin(), newNumber.end());
    if (secFlag == true)
    {
        newNumber = "1" + newNumber;
    }
    return newNumber;
}

bool if_palind(string value)
{
    bool returnFlag = false;
    for (long long i = 0; i < value.length(); i++)
    {
        if (value[i] == value[value.length() - i - 1])
        {
            returnFlag = true;
        }
        else
        {
            return false;
        }
    }
    return returnFlag;
}

int main()
{
    srand(time(0));
    setlocale(LC_ALL, "Russian");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    string input = "";
    cin >> input;

    int iter = 0;
    while (!if_palind(input))
    {
        input = addValue(input);
        cout << "Новое число после операции - " << input << endl;
        iter++;
    }

    cout << endl << "Количество итераций до палиндрома - " << iter;

}

