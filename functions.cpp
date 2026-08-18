#include <iostream>
#include <cstdlib>
#include "functions.h"

constexpr int wins[8][3][2] = {
	//Horisontals
	{{0,0},{0,1},{0,2}},
	{{1,0},{1,1},{1,2}},
	{{2,0},{2,1},{2,2}},
	// Verticals
	{{0,0},{1,0},{2,0}},
	{{0,1},{1,1},{2,1}},
	{{0,2},{1,2},{2,2}},
	//Diagonals
	{{0,0},{1,1},{2,2}},
	{{0,2},{1,1},{2,0}}
};

void printField(const char field[3][3]) 
{	
	system("cls");
	std::cout << "  1  2  3" << std::endl;
	for (int i = 0; i < 3; i++) 
	{
		std::cout << i + 1;
		for (int j = 0; j < 3; j++) 
		{
			std::cout << "[" << field[i][j] << "]";
		}
		std::cout << std::endl;
	}
}

void fillField(char field[3][3])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			field[i][j] = ' ';
		}
	}
}

bool checkWin(const char field[3][3], const char player) 
{
	for (int i = 0; i < 8; i++) 
	{
		if (field[wins[i][0][0]][wins[i][0][1]] == player &&
			field[wins[i][1][0]][wins[i][1][1]] == player &&
			field[wins[i][2][0]][wins[i][2][1]] == player)
		{
			return true;
		}
	}
	return false;
}

bool checkDraw(const char field[3][3]) // Погана функція не універсальна залежить від порядку використання з checkWin
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (field[i][j] == ' ')
			{
				return false;
			}
		}
	}
	return true;
}

void playerInput(int& row, int& col)
{
	while (!(std::cin >> row >> col) || row < 1 || row > 3 || col < 1 || col > 3)
	{
		std::cout << "Wrong input!\n";
		std::cin.clear();
		std::cin.ignore(1000, '\n');
	}
	row--, col--;
}
/*
ВИКОРИСТАННЯ 
int row, col;
playerinput(row, col);
*/

void playerProcessing(char field[3][3], char player)
{
	int row, col;

	while (true)
	{
		std::cout << "Enter row and col for " << player << ": ";
		playerInput(row, col);

		if (field[row][col] == ' ') {
			field[row][col] = player;
			return;
		}
		else {
			std::cout << "This cell is already taken" << std::endl;
		}
	}
}

void botProcessing(char field[3][3], char player)
{
	int row, col;

	while (true) 
	{
		row = rand() % 3;
		col = rand() % 3;

		if (field[row][col] == ' ') {
			field[row][col] = player;
			return;
		}
	}
}