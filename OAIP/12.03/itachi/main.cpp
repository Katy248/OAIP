#include <iostream>
#include <string>
#include <fstream>
#define GRID_SIZE 9

class Sudoku
{

public:
    Sudoku()
    {
        grid = new int*[GRID_SIZE];
        for(int i = 0; i < GRID_SIZE; i++)
        {
            grid[i] = new int[GRID_SIZE];
        }
    }

    bool solve(int posY = 0, int posX = 0)
    {
        for(int i = 0; i < GRID_SIZE; i++)
        {
            for(int j = 0; j < GRID_SIZE; j++)
            {
                if(grid[i][j] != 0)
                    continue;

                for(int number = 1; number <= 9; number++)
                {
                    if (check_number(j, i, number))
                    {
                        grid[i][j] = number;

                        if(solve())
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
        for(int i = 0; i < GRID_SIZE; i++)
        {
            if (grid[i][posX] == number)
                return false;
            if (grid[posY][i] == number)
                return false;
        }
        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                if(grid[posY-posY%3+i][posX-posX%3+j] == number)
                    return false;
            }
        }

        return true;
    }

    void set_number(int posY, int posX, int number)
    {
        grid[posY][posX] = number;
    }

    int** get_grid()
    {
        return grid;
    }

    void print()
    {
        for(int i = 0; i < GRID_SIZE; i++)
        {
            for(int j = 0; j < GRID_SIZE; j++)
                std::cout << grid[i][j] << " ";
            std::cout << std::endl;
        }
    }

private:
    int **grid;
};
int main()
{
    setlocale(LC_ALL, "Russian");

    std::ifstream input_file("sudoku1_5.txt"); 
    std::string line;
    Sudoku sudo;

    int currentPosY = 0;
    int sum = 0;
    if (input_file.is_open())
    {
        while(getline(input_file, line))
        {
            if(line.find("Grid") != std::string::npos)
                std::cout << "\n" << line << std::endl;
            else
            {
                for(int i = 0; i < GRID_SIZE; i++)
                    sudo.set_number(currentPosY, i, std::stoi(std::to_string(line[i] - '0')));

                currentPosY++;
            }
            if(currentPosY == 9)
            {
                currentPosY = 0;

                std::cout << "Судоку до решения:" << std::endl;
                sudo.print();
                std::cout << "\nСудоку после решения:" << std::endl;
                sudo.solve();
                sudo.print();
                int** temp = sudo.get_grid();
                sum += temp[0][0] * 100 + temp[0][1] * 10 + temp[0][2];
                sudo = Sudoku();          
            }
        }
        std::cout << "\nСумма чисел - " << sum << std::endl;
    }


    return 0;
}