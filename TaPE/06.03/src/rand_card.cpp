#include <random>

#include "includes.h"
#include "rand_card.h"

uint generate_number(uint first, uint second)
{
	uint number = rand() % (second - first + 1) + first;
	// clog << "[LOG] Generated number " << number << endl;
	return number;
}
