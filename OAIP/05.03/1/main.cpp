/*
1)	Число Лишрел (Lychrel number) — это натуральное число, которое не может стать палиндромом 
(числом, читающимся с конца так же, как с начала) с помощью итеративного процесса «перевернуть и сложить» в десятичной системе счисления.
Например: 57 становится палиндромом после двух итераций: 57 + 75 = 132, 132 + 231 = 363 
Сформулирована не решённая до сих пор в математике гипотеза 
«Проблема 196»: неизвестно, приведёт ли операция «перевернуть и сложить», применённая к числу 196 какое-то количество раз, к палиндрому.

Написать программу, которая для вводимых чисел выполняет итерации «перевернуть и сложить», 
и при получении в результате палиндрома выводит его значение и число потребовавшихся для этого итераций. 

Сложность задания состоит в том, что разрядность чисел может быть очень высокой (до сотен знаков), 
поэтому для операций с числами в итерациях нельзя применять арифметические операции (в том числе и сложение), 
а реализовать всё нужно в символьных отображениях этих чисел.
*/

#include <iostream>
#include <Windows.h>
#include <string>
#include <algorithm>

using namespace std;

bool palindrome(string str) {
    int len = str.length();
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - 1 - i])
            return false;
    }
    return true;
}


string addBigNumbers(string number1, string number2) {
    string sum = "";
    int perenos = 0, newadd;
    int len = number1.length();

    for (int i = len - 1; i >= 0; i--) {
        int first = number1[i]-'0';
        int second = number2[i]-'0';

        newadd = perenos + first + second;
        newadd > 9 ? perenos = 1 : perenos = 0;

        sum += to_string(newadd % 10);
    }
    if(perenos!=0)
        sum += to_string(perenos);

    reverse(sum.begin(), sum.end());
    return sum;
}

string addiction(string a) {
    string b = a;
    reverse(b.begin(), b.end());
    if (a[0] == '0')
        return "0";

    return(addBigNumbers(a, b));
    
}


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "RUS"); 

    int n,count = 0;
    cin >> n;
    string number = to_string(n);

    while (!palindrome(number)) {
        number = addiction(number);
        count++;
    }

    if (number == "0")
        cout << "Число не входит в список чисел Лишера";
    else
        cout << "Количество раз: " << count << " и число " << number;
}
