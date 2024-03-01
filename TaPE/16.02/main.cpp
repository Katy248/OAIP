#include <iostream>
#include <cstdlib>;
#include <windows.h>;
#include <algorithm>
using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int i = 0, k;
    char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyzАБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯабвгдеёжзийклмнопрстуфхцчшщъыьэюя";
    char msg[80];
    cout << "Enter message: " << endl;
    cin.getline(msg, 80);
    cout << endl << "Enter offset:" << endl;
    cin >> k;
    cout << endl;
    char* begin = alphabet;
    char* end = alphabet + sizeof(alphabet);
    for (; msg[i]; ++i)
    {
        char* ch = find(begin, end, msg[i]);
        if (ch != end) msg[i] = *(begin + (ch - begin + k) % sizeof(alphabet));
    }
    cout << "Encrypted message: " << endl;
    cout << msg << endl;
    return 0;
}
