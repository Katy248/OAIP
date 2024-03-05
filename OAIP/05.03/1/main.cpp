#include <iostream>
#include <string>
#include <algorithm>
#include <locale.h>

#if __WIN32__
#include <Windows.h>
#endif

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::to_string;

bool palindrome(string str)
{
    int len = str.length();
    for (int i = 0; i < len / 2; i++)
    {
        if (str[i] != str[len - 1 - i])
            return false;
    }
    return true;
}

string addBigNumbers(string number1, string number2)
{
    string sum = "";
    int perenos = 0, newadd;
    int len = number1.length();

    for (int i = len - 1; i >= 0; i--)
    {
        int first = number1[i] - '0';
        int second = number2[i] - '0';

        newadd = perenos + first + second;
        newadd > 9 ? perenos = 1 : perenos = 0;

        sum += to_string(newadd % 10);
    }
    if (perenos != 0)
        sum += to_string(perenos);

    reverse(sum.begin(), sum.end());
    return sum;
}

string addiction(string a)
{
    string b = a;
    reverse(b.begin(), b.end());
    if (a[0] == '0')
        return "0";

    return (addBigNumbers(a, b));
}

int main()
{
#ifdef __WIN32__
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
#endif
    setlocale(LC_ALL, "RUS");

    int n, count = 0;
    cin >> n;
    string number = to_string(n);

    if (number == "0")
    {
        cout << "Число не входит в список чисел Лишера" << endl;
        return 0;
    }

    while (!palindrome(number))
    {
        number = addiction(number);
        count++;
    }
    cout << "Количество раз: " << count << " и число " << number << endl;
    return 0
}
