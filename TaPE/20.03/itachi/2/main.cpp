#include <algorithm>
#include <iterator>
#include <iostream>
#include <cstring>

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::stoi;

int* strtoi(string line)
{
    string temp = line;
    int* arr = new int[1];

    int size = 1;
    while(temp.find_first_not_of(" ") != string::npos)
    {
        //arr = new int[5];
        int newVal = 0;
        int pos = temp.find_first_not_of(" ");
        temp.erase (0, pos);
        int temp3 = temp.find_first_of("\0");
        int temp2 =  temp.find_first_of("\n");
        pos = temp.find_first_of(" ") == -1 ? temp.find_first_of("\0") : temp.find_first_of(" ");
        int i = 0;
        for(int i = 0; i < pos; i++)
            newVal = newVal * 10 + (temp[i] - '0');

        if(size == 1)
        {
            arr[size - 1] = newVal;
        }
        else
        {
            int* newArr = new int[size];
            std::memcpy(newArr, arr, size * sizeof(int));
            delete [] arr;
            arr = new int[size];
            newArr[size] = newVal;
            arr = newArr;
        }
            
        size++;

        temp.erase(0, pos);
    }

    return arr;
}

int main()
{
    string a;
    getline(cin, a);
    int* d = strtoi(a);

    for (int i = 0; i < sizeof(d) / sizeof(int); i++)
    {
        cout << d[i] << " ";
    }
    return 0;
}