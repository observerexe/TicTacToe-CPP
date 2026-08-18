#include <iostream>
#include "functions.h"
#include "gamemodes.h"

void pvp()
{
	char field[3][3];
	int turn = 1;
	char player;
	fillField(field);

	while (true)
	{
		player = (turn % 2 == 0) ? 'O' : 'X';

		printField(field);

		playerProcessing(field, player);

		if (checkWin(field, player))
		{
			printField(field);
			std::cout << player << " WIN!\n";
			return;
		}

		if (checkDraw(field))
		{
			printField(field);
			std::cout << "Draw";
			return;
		}

		turn++;
	}
}