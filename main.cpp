#include <iostream>
#include <cstdlib>
#include <ctime>
#include "gamemodes.h"

int main()
{
	srand(static_cast<unsigned>(time(nullptr)));

	while (true)
	{
		std::cout << "Choose gamemode:\n1 PVP\n2 PVE\n> ";
		int gamemode;

		while (!(std::cin >> gamemode) || gamemode < 1 || gamemode > 2)
		{
			std::cout << "Wrong input!\n";
			std::cin.clear();
			std::cin.ignore(1000, '\n');
		}

		if (gamemode == 1) pvp();
		else pve();
	}
}
