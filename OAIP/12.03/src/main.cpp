#include <iostream>
#include <string>
#define GRID_SIZE 9

using std::cin;
using std::cout;
using std::endl;
using std::string;

class Sudoku
{

public:
    Sudoku()
    {
        grid = new int *[GRID_SIZE];
        for (int i = 0; i < GRID_SIZE; i++)
        {
            grid[i] = new int[GRID_SIZE];
        }
    }

    bool solve(int posY = 0, int posX = 0)
    {
        for (int i = 0; i < GRID_SIZE; i++)
        {
            for (int j = 0; j < GRID_SIZE; j++)
            {
                if (grid[i][j] != 0)
                    continue;

                for (int number = 1; number <= 9; number++)
                {
                    if (check_number(j, i, number))
                    {
                        grid[i][j] = number;

                        if (solve())
                            return true;

                        grid[i][j] = 0;
                    }
                }
                return false;
            }
        }

        return true;
    }

    bool check_number(int posX, int posY, int number)
    {
        for (int i = 0; i < GRID_SIZE; i++)
        {
            if (grid[i][posX] == number)
                return false;
            if (grid[posY][i] == number)
                return false;
        }
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (grid[posY - posY % 3 + i][posX - posX % 3 + j] == number)
                    return false;
            }
        }

        return true;
    }

    void set_number(int posY, int posX, int number)
    {
        grid[posY][posX] = number;
    }

    int **get_grid()
    {
        return grid;
    }

    void print()
    {
        for (int i = 0; i < GRID_SIZE; i++)
        {
            for (int j = 0; j < GRID_SIZE; j++)
            {
                cout << grid[i][j] << " ";
            }
            cout << endl;
        }
    }

private:
    int **grid;
};

/// @return Returns top left 3-digits number.
int run()
{
    Sudoku sudo;

    for (int y = 0; y < GRID_SIZE; y++)
    {
        for (int x = 0; x < GRID_SIZE; x++)
        {
            int num;
            cin >> num;
            sudo.set_number(y, x, num);
        }
    }
    cout << "Before:" << endl;
    sudo.print();
    if (sudo.solve())
    {
        cout << endl
             << "After:" << endl;
        sudo.print();
        int **temp = sudo.get_grid();
        return temp[0][0] * 100 + temp[0][1] * 10 + temp[0][2];
    }
    return 0;
}
int main()
{
#ifdef __WIN32__
    setlocale(LC_ALL, "Russian");
#endif

    const int GRID_COUNT = 9;

    int sum = 0;
    for (int i = 0; i < GRID_COUNT; i++)
    {
        cout << "Grid 0" << i << endl;
        sum += run();
    }
    cout << "\nСумма чисел - " << sum << endl;

    return 0;
}
