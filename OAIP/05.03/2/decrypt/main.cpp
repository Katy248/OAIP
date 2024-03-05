#include <iostream>

using std::cerr;
using std::cin;
using std::clog;
using std::cout;
using std::endl;

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        cerr << "Not enough args" << endl;
        return 1;
    }

    unsigned int value = std::stoi(argv[1]);

    if (value < 1000 || value > 9999)
    {
        cerr << "Input value not of 4 digits" << endl;
        return 2;
    }

    int digits[4];

    for (int i = 0; i < 4; i++)
    {
        digits[4 - 1 - i] = value % 10; /* get digit */
        if (digits[4 - 1 - i] < 7)
            digits[4 - 1 - i] += 10;
        digits[4 -1 - i] = digits[4 -1 - i] - 7; /* decrypt digit */

        value /= 10;
    }

    for (int i = 0; i < 4; i++)
    {
        cout << digits[i]; 
    }
    cout << endl;

    return 0;
}
