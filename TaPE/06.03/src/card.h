#include <map>
#include "includes.h"
#define BINGO_SIZE 5

struct Cell
{
	uint number;
	bool checked = false;
};
struct Card
{
	Cell lines[BINGO_SIZE][BINGO_SIZE];
};

Card create_card();
void out_card(Card &);

/// @brief Mark cell with same value as checked
/// @param  card
/// @param  value
void check_cell(Card &, uint);

bool is_winner(Card &);
