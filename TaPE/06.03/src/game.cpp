#include <iostream>

#include "game.h"
#include "card.h"
#include "rand_card.h"

using std::cout;
using std::endl;

int start()
{
    Card card = create_card();
    int iter_count = 0;
    while (!is_winner(card))
    {
        iter_count++;
        uint number = generate_numbers(1, 60);
        check_cell(Card, number);
    }

    cout << "Iteration count: " << iter_count << endl;
}
