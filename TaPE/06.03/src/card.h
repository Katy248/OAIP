#define BINGO_SIZE 5
#include "includes.h"

public struct Card {
	map<char, Cell[BINGO_SIZE]> lines;
};
public struct Cell {
	uint number;
	bool checked = false;
};

Card create_card();
void out_card(Card*);
/// <summary>
/// 
/// </summary>
/// <param name=""></param>
/// <param name=""></param>
void check_cell(Card*, uint); 

bool winner(Card);