#include <iostream>
#include "crypt.h"

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

    uint *digits = to_digits_array(value);

    cout << decrypt(digits) << endl;

    return 0;
}
