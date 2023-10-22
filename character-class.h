#ifndef CHARACTER_CLASS_H
#define CHARACTER_CLASS_H
#include <string>

class Character
{
public:
	int playerID{ 0 };
	int turnPos{ 0 }; // Turn Position

	std::string name;

	int health{ 100 };
	int attack{ 0 };
	int defense{ 0 };
	int speed{ 0 };

	attackInfo attack1;
	attackInfo attack2;
	attackInfo statBoost1;
	attackInfo statBoost2;
	attackInfo invalidChoice;

	attackInfo selectAttack(int choice, int playerNum) // Turn number input into attack data
	{
		if (choice == 1)
		{
			return attack1;
		}
		else if (choice == 2)
		{
			return attack2;
		}
		else if (choice == 3)
		{
			return statBoost1;
		}
		else if (choice == 4)
		{
			return statBoost2;
		}
		else
		{
			std::cout << '\n' << "Invalid Input" << '\n';
			std::cin.clear();
			std::cin.ignore(INT_MAX, '\n');

			while ((choice != 1) && (choice != 2) && (choice != 3) && (choice != 4))
			{
				std::cout << "Enter a number from 1 to 4" << '\n';
				std::cin >> choice;
				
				return selectAttack(choice, playerNum);
			}
		}
	}

};

#endif