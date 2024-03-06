#include "card.h"
#include "includes.h"

void check_cell(Card &card, uint value)
{
    for (uint i = 0; i < BINGO_SIZE; i++)
    {
        for (uint j = 0; j < BINGO_SIZE; i++)
        {
            if (Card.lines[i][j].number == value)
            {
                Card.lines[i][j].checked = true;
                return;
            }
        }
    }
}
