#ifndef CHARACTER_CLASS_H
#define CHARACTER_CLASS_H
#include <string>
#include "attacks-struct.h"

using namespace std;

class Character
{
public:
	int playerID{ 0 };
	int turnPos{ 0 }; // Turn Position

	string name;

	// Stats Declaration
	int health{ 100 };
	int attack{ 0 };
	int defense{ 0 };
	int speed{ 0 };

	// Attacks Declaration
	attackInfo attack1;
	attackInfo attack2;
	attackInfo statBoost1;
	attackInfo statBoost2;

	Character(string characterName = "not selected", int characterHealth = 100, int characterAttack = 0, int characterDefense = 0, int characterSpeed = 0)
	{
		name = characterName;

		health = characterHealth;
		attack = characterAttack;
		defense = characterDefense;
		speed = characterSpeed;

		attackInfo attack1;
		attackInfo attack2;
		attackInfo statBoost1;
		attackInfo statBoost2;
	}

	// Select Attack
	attackInfo selectAttack(int choice, Character player) // Turn number input into attack data
	{
		if (choice == 1)
		{
			return player.attack1;
		}
		else if (choice == 2)
		{
			return player.attack2;
		}
		else if (choice == 3)
		{
			return player.statBoost1;
		}
		else if (choice == 4)
		{
			return player.statBoost2;
		}
		else
		{
			cout << '\n' << "Invalid Input" << '\n';
			cin.clear();
			cin.ignore(INT_MAX, '\n');

			while ((choice != 1) && (choice != 2) && (choice != 3) && (choice != 4))
			{
				cout << "Enter a number from 1 to 4" << '\n';
				cin >> choice;

				return selectAttack(choice, player);
			}
		}
	}

};



#endif 