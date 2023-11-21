// Author: Seth Jackson

#include <iostream>
#include "attacks-struct.h"
#include "character-class.h"
#include "character-obj-selection.h"
#include "battle.h"

using namespace std;

// Attack Stat Change
Character attackChange(attackInfo attackBoost, Character &player)
{
	player.attack += attackBoost.attackBoost;

	if (player.attack < 0)
	{
		player.attack = 0;
	}

	return player;
}

// Damage Calc 
Character damageCalculation(attackInfo attackChoice, Character attackingPlayer, Character defendingPlayer)
{
	int originalStat;
	originalStat = defendingPlayer.health;

	defendingPlayer.health = originalStat - ((attackingPlayer.attack + attackChoice.attackDamage) - defendingPlayer.defense);

	if (defendingPlayer.health < 0)
	{
		defendingPlayer.health = 0;
	}

	return defendingPlayer;
}

// Defense Stat Change
Character defenseChange(attackInfo defenseBoost, Character &player)
{
	player.defense += defenseBoost.defenseBoost;

	if (player.defense < 0)
	{
		player.defense = 0;
	}

	return player;
}

// Select Attack
int inputAttackChoice(int playerNum)
{
	int attackChoice;
	cout << '\n' << "Player " << playerNum << "," << '\n'
	<< "Enter 1 through 4 to choose your attack:" << '\n';
	cin >> attackChoice;

	//If input fails
	if (cin.fail() || (attackChoice < 1 || attackChoice > 5))
	{
		cout << '\n' << "Invalid Input" << '\n';

		cin.clear();
		cin.ignore(INT_MAX, '\n');

		return inputAttackChoice(playerNum);
	}

	return attackChoice;
}

// Output Player 1 Stats
void outP1Stats(Character player1)
{
	cout << '\n' << "Player One's Stats:" << '\n' << "Health: " << player1.health << '\n' <<
	"Attack: " << player1.attack << '\n' << "Defense: " << player1.defense << '\n' <<
	"Speed: " << player1.speed << '\n';
}

// Ouput Player 2 Stats
void outP2Stats(Character player2)
{
	cout << '\n' << "Player Two's Stats:" << '\n' << "Health: " << player2.health << '\n' <<
	"Attack: " << player2.attack << '\n' << "Defense: " << player2.defense << '\n' <<
	"Speed: " << player2.speed << '\n';
}

// Speed Stat Change
Character speedChange(attackInfo speedBoost, Character &player)
{
	player.speed += speedBoost.speedBoost;

	if (player.speed < 0)
	{
		player.speed = 0;
	}

	return player;
}



// Turn and Battle functions below

// Single Attacking Phase
Character turn(Character fastPlayer, Character slowPlayer) // fastPlayer refers to the player who's turn it is, slow player is other player
{
	fastPlayer.turnPos;
	fastPlayer.turnPos = 1;

	slowPlayer.turnPos;
	slowPlayer.turnPos = 2;

	//Output Attack List
	cout << '\n' << "Player " << fastPlayer.playerID << " " << "Attacks:" << '\n';
	cout << fastPlayer.attack1.attackNum << "..." << fastPlayer.attack1.name << '\n';
	cout << fastPlayer.attack2.attackNum << "..." << fastPlayer.attack2.name << '\n';
	cout << fastPlayer.statBoost1.attackNum << "..." << fastPlayer.statBoost1.name << '\n';
	cout << fastPlayer.statBoost2.attackNum << "..." << fastPlayer.statBoost2.name << '\n';

	// Choose Attack
	int attackInt;
	attackInt = inputAttackChoice(fastPlayer.playerID);
	attackInfo attackChoice;
	attackChoice = fastPlayer.selectAttack(attackInt, fastPlayer);

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

// Battle: Loops turn() Function and Has Logic for Deciding Who Goes First
Character battle(Character &player1, Character &player2)
{

	while (player1.health > 0 && player2.health > 0)
	{
		Character turnOnePlayer;
		Character turnTwoPlayer;
		Character moddedPlayer;

		// Faster Player Goes

		if (player1.speed == player2.speed) // if speed is equal, player 1 goes first
		{
			turnOnePlayer = player1;
			moddedPlayer = turn(player1, player2); // the player who's stats change is returned from the turn() function is saved as moddedPlayer

			if (moddedPlayer.playerID == 1) // player 1 stat change
			{
				player1 = moddedPlayer; // update player object

				outP1Stats(player1); // Ouput Player 1 Stats
			}
			else if (moddedPlayer.playerID == 2) // player 2 stat change
			{
				player2 = moddedPlayer;

				outP2Stats(player2); // Ouput Player 2 Stats
			}

			turnTwoPlayer = player2; // player 2 goes next
		}
		else if (player1.speed > player2.speed) // if player one has higher speed, player 1 goes first
		{
			turnOnePlayer = player1;
			moddedPlayer = turn(player1, player2); 

			if (moddedPlayer.playerID == 1) // player 1 stat change
			{
				player1 = moddedPlayer;

				outP1Stats(player1); // Ouput Player 1 Stats
			}
			else if (moddedPlayer.playerID == 2) // player 2 stat change
			{
				player2 = moddedPlayer;

				outP2Stats(player2); // output player 2 stats
			}

			turnTwoPlayer = player2; // player 2 goes next
		}
		else if (player2.speed > player1.speed) // player 2 has higher speed, player 2 goes first
		{
			turnOnePlayer = player2;
			moddedPlayer = turn(player2, player1);

			if (moddedPlayer.playerID == 1) // player 1 stat change
			{
				player1 = moddedPlayer;

				outP1Stats(player1); 
			}
			else if (moddedPlayer.playerID == 2) // player 2 stat change
			{
				player2 = moddedPlayer;

				outP2Stats(player2);
			}

			turnTwoPlayer = player1; // player 1 goes next
		}

		// This is between turns... begin middle phase
		// If someone's health becomes zero before the turn would normally end, return the winner:
		if (player1.health <= 0)
		{
			return player2;
		}
		else if (player2.health <= 0)
		{
			return player1;
		}
		// end of middle phase

		// Slow Player Goes
		if (turnTwoPlayer.playerID == 1) // if player 2 went first
		{
			moddedPlayer = turn(turnTwoPlayer, turnOnePlayer);

			// decide who's stats to output
			if (moddedPlayer.playerID == 1) 
			{
				player1 = moddedPlayer;

				outP1Stats(player1);
			}
			else if (moddedPlayer.playerID == 2) 
			{
				player2 = moddedPlayer;

				outP2Stats(player2);
			}
		}
		else if (turnTwoPlayer.playerID == 2) // if player two went second
		{
		
			moddedPlayer = turn(turnTwoPlayer, turnOnePlayer);

			if (moddedPlayer.playerID == 1)
			{
				player1 = moddedPlayer;

				outP1Stats(player1);
			}
			else if (moddedPlayer.playerID == 2)
			{
				player2 = moddedPlayer;

				outP2Stats(player2);
			}
		}

	}

	// Return Winner to Main Function
	if (player1.health <= 0)
	{
		return player2;
	}
	else if (player2.health <= 0)
	{
		return player1;
	}
}
