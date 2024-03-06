#include "card.h"
#include "includes.h"
#include "iostream"
#include "rand_card.h"

Card create_card() {
    Card newcard;
    //int b_cont[BINGO_SIZE], i_cont[BINGO_SIZE], n_cont[BINGO_SIZE], g_cont[BINGO_SIZE], o_cont[BINGO_SIZE];
    set <int> b_cont, i_cont, n_cont, i_cont, g_cont;
    while (b_cont.size()!=5) {
        b_cont.insert(generate_numbers(1, 15));
    }
    while (i_cont.size() != 5) {
        i_cont.insert(generate_numbers(16, 30));
    }
    while (n_cont.size() != 5) {
        n_cont.insert(generate_numbers(31, 45));
    }
    while (g_cont.size() != 5) {
        g_cont.insert(generate_numbers(46, 60));
    }
    while (i_cont.size() != 5) {
        i_cont.insert(generate_numbers(61, 75));
    }

    for (int i = 0; i < BINGO_SIZE; i++) {
        newcard.lines.insert({ 'B',b_cont });
        newcard.lines.insert({ 'I',i_cont });
        newcard.lines.insert({ 'N',i_cont });
        newcard.lines.insert({ 'G',i_cont });
        newcard.lines.insert({ 'O',i_cont });

    }

    return newcard;
}

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

void out_card(Card& our_card) {
    for (int i = 0; i < BINGO_SIZE; i++) {
        switch (i) {
        case 0:
            cout << "B: ";
            break;
        case 1:
            cout << "I: ";
            break;
        case 2:
            cout << "N: ";
            break;
        case 3:
            cout << "I: ";
            break;
        case 4:
            cout << "G: ";
            break;
        }
        for (auto x : our_card[i]) {
            if (x.checked)
                cout << "☓" << " ";
            else
                cout << x << " ";
        }
        cout << "\n";
    }
}