#include <iostream>
#include "attacks-struct.h"
#include "character-class.h"
#include "character-obj-selection.h"
#include "stats.h"
#include "battle.h"

using namespace std;

// Option to Output Stats
void viewStats(Character& fastPlayer, Character& slowPlayer)
{
	string statView{ "" };

	while (statView != "attack")
	{
		cout << '\n';
		cout << "Player " << fastPlayer.playerID << ":" << '\n';
		cout << "To view your stats, enter \"s1\"" << '\n';
		cout << "To view the opponenet's stats, enter \"s2\"" << '\n';
		cout << "To choose an attack, enter \"attack\"." << '\n';
		cin >> statView;

		if (statView == "s1" && fastPlayer.playerID == 1)
		{
			outP1Stats(fastPlayer);
		}
		else if (statView == "s1" && fastPlayer.playerID == 2)
		{
			outP2Stats(fastPlayer);
		}
		else if (statView == "s2" && fastPlayer.playerID == 1)
		{
			outP2Stats(slowPlayer);
		}
		else if (statView == "s2" && fastPlayer.playerID == 2)
		{
			outP1Stats(slowPlayer);
		}
		else
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');

			continue;
		}
	}
	
}
