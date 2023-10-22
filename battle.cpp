#include <iostream>
#include "attacks-struct.h"
#include "character-class.h"
#include "character-selection.h"
#include "battle.h"


int inputAttackChoice(int playerNum)
{
	int attackChoice;
	std::cout << '\n' << "Player " << playerNum << "," << '\n'
	<< "Enter 1 through 4 to choose your attack:" << '\n';
	std::cin >> attackChoice;

	//If input fails
	if (std::cin.fail() || (attackChoice < 1 || attackChoice > 5))
	{
		std::cout << '\n' << "Invalid Input" << '\n';

		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');

		return inputAttackChoice(playerNum);
	}

	return attackChoice;
}

Character damageCalculation(attackInfo attackChoice, Character attackingPlayer, Character defendingPlayer)
{
	int origianlStat;
	origianlStat = defendingPlayer.health;

	int hpAfterDamage;
	hpAfterDamage = defendingPlayer.health - ((attackingPlayer.attack + attackChoice.attackDamage) - defendingPlayer.defense);
	defendingPlayer.health = hpAfterDamage;

	return defendingPlayer;
}

Character attackChange(attackInfo attackBoost, Character player)
{
	int originalStat;
	originalStat = player.attack;

	int newStat;
	newStat = originalStat + attackBoost.attackBoost;
	player.attack = newStat;

	return player;
}

Character defenseChange(attackInfo defenseBoost, Character player)
{
	int originalStat;
	originalStat = player.defense;

	int newStat;
	newStat = originalStat + defenseBoost.defenseBoost;
	player.defense = newStat;

	return player; 
}

Character speedChange(attackInfo speedBoost, Character player)
{
	int originalStat;
	originalStat = player.speed;

	int newStat;
	newStat = originalStat + speedBoost.speedBoost;
	player.speed = newStat;

	return player;
}

Character turn(Character fastPlayer, Character slowPlayer) // fastPlayer refers to the player who's turn it is, slow player is other player
{
	fastPlayer.turnPos;
	fastPlayer.turnPos = 1;

	slowPlayer.turnPos;
	slowPlayer.turnPos = 2;

	//Output Attack List
	std::cout << '\n' << "Player " << fastPlayer.playerID << " " << "Attacks:" << '\n';
	std::cout << fastPlayer.attack1.attackNum << "..." << fastPlayer.attack1.name << '\n';
	std::cout << fastPlayer.attack2.attackNum << "..." << fastPlayer.attack2.name << '\n';
	std::cout << fastPlayer.statBoost1.attackNum << "..." << fastPlayer.statBoost1.name << '\n';
	std::cout << fastPlayer.statBoost2.attackNum << "..." << fastPlayer.statBoost2.name << '\n';

	// Choose Attack
	int attackInt;
	attackInt = inputAttackChoice(fastPlayer.playerID);
	attackInfo attackChoice;
	attackChoice = fastPlayer.selectAttack(attackInt, fastPlayer.playerID);

	// Damage Calc Phase For Attack
	if (attackChoice.attackDamage != 0)
	{
		slowPlayer = damageCalculation(attackChoice, fastPlayer, slowPlayer);

		//End Turn
		return slowPlayer;
	}

	// Stat Boost Calc for Attack Change
	else if (attackChoice.attackBoost != 0)
	{
		// Attack Buff
		if (attackChoice.attackBoost > 0)
		{
			fastPlayer = attackChange(attackChoice, fastPlayer);
			return fastPlayer;
		}
		// Lower Enemy Attack
		else if (attackChoice.attackBoost < 0)
		{
			slowPlayer = attackChange(attackChoice, slowPlayer);
			return slowPlayer;
		}
	}
	// Stat Boost Calc for Defense Change
	else if (attackChoice.defenseBoost != 0)
	{
		// Defense Buff
		if (attackChoice.defenseBoost > 0)
		{
			fastPlayer = defenseChange(attackChoice, fastPlayer);
			return fastPlayer;
		}
		// Lower Enemy Defense
		else if (attackChoice.defenseBoost < 0)
		{
			slowPlayer = defenseChange(attackChoice, slowPlayer);
			return slowPlayer;
		}
	}
	// Stat Boost Calc for Speed Change
	else if (attackChoice.speedBoost != 0)
	{
		// Speed Buff
		if (attackChoice.speedBoost > 0)
		{
			fastPlayer = speedChange(attackChoice, fastPlayer);
			return fastPlayer;
		}
		// Lower Enemy Speed
		else if (attackChoice.speedBoost < 0)
		{
			slowPlayer = speedChange(attackChoice, slowPlayer);
			return slowPlayer;
		}
	}

}

Character battle(Character player1, Character player2)
{
	// Battle 
	while (player1.health != 0 && player2.health != 0)
	{
		// Player 1 Goes
		Character turnOnePlayer{ player1 };
		Character turnTwoPlayer{ player2 };
		Character moddedPlayer;

		if (player1.speed == player2.speed)
		{
			moddedPlayer = turn(player1, player2);

			if (moddedPlayer.playerID == 1)
			{
				player1 = moddedPlayer;

				std::cout << '\n' << "Player One's Stats:" << '\n' << "Health: " << player1.health << '\n' <<
					"Attack: " << player1.attack << '\n' << "Defense: " << player1.defense << '\n' <<
					"Speed: " << player1.speed << '\n';
			}
			else if (moddedPlayer.playerID == 2)
			{
				player2 = moddedPlayer;

				std::cout << '\n' << "Player Two's Stats:" << '\n' << "Health: " << player2.health << '\n' <<
					"Attack: " << player2.attack << '\n' << "Defense: " << player2.defense << '\n' <<
					"Speed: " << player2.speed << '\n';
			}
			turnTwoPlayer = player2;
		}
		else if (player1.speed > player2.speed)
		{
			moddedPlayer = turn(player1, player2);

			if (moddedPlayer.playerID == 1)
			{
				player1 = moddedPlayer;

				std::cout << '\n' << "Player One's Stats:" << '\n' << "Health: " << player1.health << '\n' <<
					"Attack: " << player1.attack << '\n' << "Defense: " << player1.defense << '\n' <<
					"Speed: " << player1.speed << '\n';
			}
			else if (moddedPlayer.playerID == 2)
			{
				player2 = moddedPlayer;

				std::cout << '\n' << "Player Two's Stats:" << '\n' << "Health: " << player2.health << '\n' <<
					"Attack: " << player2.attack << '\n' << "Defense: " << player2.defense << '\n' <<
					"Speed: " << player2.speed << '\n';
			}

			turnTwoPlayer = player2;
		}
		else if (player2.speed > player1.speed)
		{
			moddedPlayer = turn(player2, player1);

			if (moddedPlayer.playerID == 1)
			{
				player1 = moddedPlayer;

				std::cout << '\n' << "Player One's Stats:" << '\n' << "Health: " << player1.health << '\n' <<
					"Attack: " << player1.attack << '\n' << "Defense: " << player1.defense << '\n' <<
					"Speed: " << player1.speed << '\n';
			}
			else if (moddedPlayer.playerID == 2)
			{
				player2 = moddedPlayer;

				std::cout << '\n' << "Player Two's Stats:" << '\n' << "Health: " << player2.health << '\n' <<
					"Attack: " << player2.attack << '\n' << "Defense: " << player2.defense << '\n' <<
					"Speed: " << player2.speed << '\n';
			}

			turnTwoPlayer = player1;
		}

		// Slow Player Goes
		if (turnTwoPlayer.playerID == 1)
		{
			moddedPlayer = turn(turnTwoPlayer, turnOnePlayer);

			if (moddedPlayer.playerID == 1)
			{
				player1 = moddedPlayer;

				std::cout << '\n' << "Player One's Stats:" << '\n' << "Health: " << player1.health << '\n' <<
					"Attack: " << player1.attack << '\n' << "Defense: " << player1.defense << '\n' <<
					"Speed: " << player1.speed << '\n';
			}
			else if (moddedPlayer.playerID == 2)
			{
				player2 = moddedPlayer;

				std::cout << '\n' << "Player Two's Stats:" << '\n' << "Health: " << player2.health << '\n' <<
					"Attack: " << player2.attack << '\n' << "Defense: " << player2.defense << '\n' <<
					"Speed: " << player2.speed << '\n';
			}
		}
		else if (turnTwoPlayer.playerID == 2)
		{
			moddedPlayer = turn(turnTwoPlayer, turnOnePlayer);

			if (moddedPlayer.playerID == 1)
			{
				player1 = moddedPlayer;

				std::cout << '\n' << "Player One's Stats:" << '\n' << "Health: " << player1.health << '\n' <<
					"Attack: " << player1.attack << '\n' << "Defense: " << player1.defense << '\n' <<
					"Speed: " << player1.speed << '\n';
			}
			else if (moddedPlayer.playerID == 2)
			{
				player2 = moddedPlayer;

				std::cout << '\n' << "Player Two's Stats:" << '\n' << "Health: " << player2.health << '\n' <<
					"Attack: " << player2.attack << '\n' << "Defense: " << player2.defense << '\n' <<
					"Speed: " << player2.speed << '\n';
			}
		}

	}

	// Congratulate Victor
	if (player1.health == 0)
	{
		return player2;
	}
	else if (player2.health == 0)
	{
		return player1;
	}
}
