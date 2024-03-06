#include <iostream>

#include "game.h"
#include "card.h"
#include "rand_card.h"

using std::cout;
using std::endl;

int start()
{
    uint sim_count = 1000;
    long uint all_times = 0;
    for (uint i = 0; i < sim_count; i++)
    {
        all_times += play();
    }
    cout << "Average iterations: " << all_times / sim_count << endl;
}

uint play()
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