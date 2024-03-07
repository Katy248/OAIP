#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    int n;
    cout << "Enter number: ";
    cin >> n;
    int **A = new int *[n];

    for (int i = 0; i < n; i++)
    {
        A[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            if (i > j)
                A[i][j] = 2;
            else if (i < j)
                A[i][j] = 1;
            else
                A[i][j] = 0;
        }
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
