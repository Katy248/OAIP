#include <stdlib.h>

#include "game.h"

#define ASCII_DIGITS_OFFSET 48

uint NUMBER = 0;
uint NUMBER_ARRAY[3] = {0, 0, 0};
char NUMBER_CHAR[3] = {'0', '0', '0'};

void number_to_array(uint number, uint array[3])
{
    array[0] = number / 100;
    array[1] = number % 100;
    array[2] = number % 10;
}

void generate_number()
{
    srand(time(NULL));
    while (NUMBER < 100)
        NUMBER = rand() % 1000;

    number_to_array(NUMBER, NUMBER_ARRAY);

    for (uint i = 0; i < 3; i++)
    {
        NUMBER_CHAR[i] = NUMBER_ARRAY[i] + ASCII_DIGITS_OFFSET;
    }
}

uint get_number()
{
    return NUMBER;
}

uint get_guessed_digits_count(uint number)
{
    int result = 0;
    uint digits[3];
    number_to_array(number, digits);
    for (uint i = 0; i < 3; i++)
    {
        for (uint j = 0; j < 3; j++)
        {
            if (digits[i] == NUMBER_ARRAY[j])
            {
                result++;
                continue;
            }
        }
    }
    return result;
}
uint get_guessed_digits_positions_count(uint number)
{
    uint counter = 0;
    uint digits[3];
    number_to_array(number, digits);

    for (uint i = 0; i < 3; i++)
    {
        if (NUMBER_ARRAY[i] == digits[i])
            counter++;
    }
    return counter;
}
