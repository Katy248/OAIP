#include "resolver.h"

bool is_safe(field *, uint, uint, uint);

bool solve(field *f, uint row, uint col)
{
    if (row == FIELD_SIZE && col == FIELD_SIZE)
        return true;

    if (col == FIELD_SIZE)
    {
        col = 0;
        row++;
    }

    if (f->cells[row][col] > 0)
        return solve(f, row, col + 1);

    for (uint num = 1; num < FIELD_SIZE; num++)
    {
        if (is_safe(f, row, col, num))
        {
            f->cells[row][col] = num;
            if (solve(f, row, col + 1))
            {
                return true;
            }
        }
        f->cells[row][col] = 0;
    }

    return false;
}
bool is_safe(field *f, uint row, uint col, uint num)
{
    for (uint x = 0; x < FIELD_SIZE - 1; x++)
    {
        if (f->cells[row][x] == num)
        {
            return false;
        }
    }
    for (uint y = 0; y < FIELD_SIZE - 1; y++)
    {
        if (f->cells[y][col] == num)
        {
            return false;
        }
    }

    int start_row = row - row % 3,
        start_col = col - col % 3;

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (f->cells[i + start_row][j +
                                        start_col] == num)
                return false;

    return true;
}
