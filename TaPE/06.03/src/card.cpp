#include "card.h"
#include "includes.h"
#include "rand_card.h"

bool is_unique(Cell line[BINGO_SIZE], uint cell_index)
{
    if (cell_index == 0)
        return true;
    for (uint i = 0; i < cell_index - 1; i++)
    {
        // clog << "[LOG] Cell number " << line[i].number << "; " << line[cell_index].number << "; cell index " << cell_index << "; index " << i << endl;

        if (line[i].number == line[cell_index].number)
            return false;
    }
    return true;
}

Card create_card()
{
    Card new_card;

    for (uint i = 0; i < BINGO_SIZE; i++)
    {
        // clog << "[LOG] Start Generate line[" << i << "]" << endl;
        for (uint j = 0; j < BINGO_SIZE; j++)
        {
            uint
                min = 1 + (i * 15),
                max = min + 15;
            // clog << "[LOG] Start Generate cell[" << j << "] min " << min << " max " << max << endl;
            new_card.lines[i][j] = {0};
            do
            {
                uint number = generate_number(min, max);
                new_card.lines[i][j] = Cell{number};
            } while (!is_unique(new_card.lines[i], j));
        }
    }
    return new_card;
}

void check_cell(Card &card, uint value)
{
    for (uint i = 0; i < BINGO_SIZE; i++)
    {
        for (uint j = 0; j < BINGO_SIZE; j++)
        {
            if (card.lines[i][j].number == value)
            {
                card.lines[i][j].checked = true;
                return;
            }
        }
    }
}

void out_card(Card &our_card)
{
    const char BINGO[BINGO_SIZE]{'B', 'I', 'N', 'G', 'O'};
    for (int i = 0; i < BINGO_SIZE; i++)
    {
        cout << BINGO[i] << " | ";

        for (uint j = 0; j < BINGO_SIZE; j++)
        {
            Cell x = our_card.lines[i][j];
            /*
            if (x.checked)
            {
                cout << "[" << x.number << "]"
                     << " ";
            }
            else
            {
            }
            */
            cout << x.number << " (" << (x.checked ? "X" : " ") << ") ";
        }
        cout << std::endl;
    }
}

bool is_winner(Card &card)
{
    for (uint i = 0; i < BINGO_SIZE; i++)
    {
        uint checked_count = 0;
        for (uint j = 0; j < BINGO_SIZE; j++)
        {
            if (card.lines[i][j].checked)
                checked_count++;
        }
        if (checked_count == BINGO_SIZE)
            return true;
    }
    return false;
}
