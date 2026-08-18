#include <iostream>
#include "functions.h"
#include "gamemodes.h"

void pve()
{
	char field[3][3];
	int turn = 1;
	char player;
	char playerChoose;

	std::cout << "Choose X or O: ";
	while (!(std::cin >> playerChoose) || (playerChoose != 'X' && playerChoose != 'O'))
	{
		std::cout << "Wrong input!\n";
		std::cin.clear();
		std::cin.ignore(1000, '\n');
	}

	fillField(field);

	while (true)
	{
		player = (turn % 2 == 0) ? 'O' : 'X';

		printField(field);

		if (player == playerChoose) playerProcessing(field, player);
		else botProcessing(field, player);

		if (checkWin(field, player))
		{
			printField(field);
			std::cout << player << " WIN!\n";
			return;
		}

		if (checkDraw(field))
		{
			printField(field);
			std::cout << "Draw\n";
			return;
		}

		turn++;
	}
}