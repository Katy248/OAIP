#include <iostream>
#include <cstdlib>
#include <algorithm>

/* Windows specific lib */
#if __WIN32__
#include <windows.h>
#endif
using namespace std;

int main()
{
    const unsigned int MESSAGE_LENGTH = 80;
    
    /* If current OS is Windows it will work with russian letters othervise only with english */
    #if __WIN32__
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyzАБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯабвгдеёжзийклмнопрстуфхцчшщъыьэюя";
    #else
    char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    #endif

    
    int 
        i = 0, 
        k;
    char msg[MESSAGE_LENGTH];

    cout << "Enter message: " << endl;
    cin.getline(msg, MESSAGE_LENGTH);
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
