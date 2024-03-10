#include <stdlib.h>
#include <thread>

#include "game.h"
#include "card.h"
#include "rand_card.h"

using std::stoi;
using std::chrono::milliseconds;

uint play();

int start(int argc, char **argv)
{
    uint sim_count = 10;

    if (argc >= 2)
    {
        sim_count = stoi(argv[1]);
    }

    // clog << "[LOG] Start game" << endl;
    long uint all_times = 0;
    for (uint i = 0; i < sim_count; i++)
    {
        all_times += play();
    }
    cout << "Average iterations: " << all_times / sim_count << endl;
    // clog << "[LOG] End game" << endl;
    return 0;
}

uint play()
{
    // clog << "[LOG] Start session" << endl;
    Card game_card = create_card();
    int iter_count = 0;
    cout << endl;
    while (!is_winner(game_card))
    {
        iter_count++;
        uint number = generate_number(1, 80);
        // clog << "[LOG] Generate next number " << number << endl;
        check_cell(game_card, number);
#ifdef __WIN32__
        system("cls");
#else
        system("clear");
#endif

        out_card(game_card);
        // std::this_thread::sleep_for(milliseconds(500));
    }

    cout << "Iteration count: " << iter_count << endl;

    clog << "[LOG] End session" << endl;
    return iter_count;
}
