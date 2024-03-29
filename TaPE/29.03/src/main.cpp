#include "game.h"

int main(int argc, char **argv)
{
    generate_number();

    cout << get_number() << "\n";
    bool is_win = false;

    while (!is_win)
    {
        uint input;
        cout << "Введите число:\n";
        cin >> input;
        uint digits = get_guessed_digits_count(input);
        uint positions = get_guessed_digits_positions_count(input);

        is_win = digits == 3 && positions == 3;
        cout << "Ваш вариант -> " << input << " Угадано: " << digits << ". На своих местах: " << positions << "\n";
    }

    cout << "*** ВЫ ВЫИГРАЛИ! ***";

    return 0;
}
