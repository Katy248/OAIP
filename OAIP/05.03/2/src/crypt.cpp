#include "crypt.h"

uint *to_digits_array(uint number)
{
    uint *digits = new uint[ENCRYPTION_MAX_LENGTH];
    for (int i = 0; i < 4; i++)
    {
        digits[4 - 1 - i] = number % 10;
        number /= 10;
    }

    return digits;
}
uint encrypt(uint digits[ENCRYPTION_MAX_LENGTH])
{
    uint result = 0;
    for (uint i = 0; i < ENCRYPTION_MAX_LENGTH; i++)
    {
        result *= 10;
        result += (digits[i] + 7) % 10;
    }
    return result;
}
uint decrypt(uint digits[ENCRYPTION_MAX_LENGTH])
{
    uint result = 0;
    for (uint i = 0; i < ENCRYPTION_MAX_LENGTH; i++)
    {
        result *= 10;
        uint cur_digit = digits[i];
        if (cur_digit < 7)
        {
            cur_digit += 10;
        }

        result += cur_digit - 7;
    }
    return result;
}
