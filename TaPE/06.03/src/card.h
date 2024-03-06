#include <map>
#include "includes.h"
#define BINGO_SIZE 5


struct Card
{
	Cell lines[BINGO_SIZE][BINGO_SIZE];
};
struct Cell
{
	uint number;
	bool checked = false;
};

Card create_card();
void out_card(Card &);
/// <summary>
///
/// </summary>
/// <param name=""></param>
/// <param name=""></param>
void check_cell(Card &, uint);

bool is_winner(Card &);
