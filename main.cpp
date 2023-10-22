#include <iostream>
#include <string>
#include "attacks-struct.h"
#include "character-class.h"
#include "character-selection.h"
#include "battle.h"



int main()
{
	std::cout << "Welcome to BattleFrogs" << '\n';

	// Choose Character
	// Player 1
	Character player1;
	std::cout << '\n' << "Player 1:";
	player1 = selectCharacter();
	player1.playerID = 1;

	// Player 2
	Character player2;
	std::cout << '\n' << "Player 2:";
	player2 = selectCharacter();
	player2.playerID = 2;

	// Battle
	Character winner = battle(player1, player2);

	std::cout << '\n' << "The Winner is player " << winner.playerID;

	return 0;
}