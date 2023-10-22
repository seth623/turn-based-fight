#include <iostream>
#include <string>
#include "attacks-struct.h"
#include "character-class.h"
#include "character-selection.h"

Character selectCharacter()
{
	std::cout << '\n' << "Type a number from 1 to 3 to select a character:" << '\n';
	int choice;
	std::cin >> choice;

	// Character 1: Water Type
	if (choice == 1)
	{
		Character character1{};
		character1.name = "Water";

		// Character 1 Stats
		character1.health = 100;
		character1.attack = 10;
		character1.defense = 5;
		character1.speed = 30;

		// Character 1 Attack 1
		character1.attack1;
		character1.attack1.name = "Water Ball";
		character1.attack1.attackNum = 1;
		character1.attack1.attackDamage = 10;

		// Character 1 Attack 2
		character1.attack2;
		character1.attack2.name = "Lower Enemy Defense";
		character1.attack2.attackNum = 2;
		character1.attack2.defenseBoost = -5; // Lowers opponent's defense stat by 5

		// Character 1 Stat Boost 1
		character1.statBoost1;
		character1.statBoost1.name = "Raise Attack";
		character1.statBoost1.attackNum = 3;
		character1.statBoost1.attackBoost = 5; // Raises your attack stat by 5

		// Character 1 Stat Boost 2
		character1.statBoost2;
		character1.statBoost2.name = "Raise Speed";
		character1.statBoost2.attackNum = 4;
		character1.statBoost2.speedBoost = 5; // Raises your speed stat by 5

		return character1;
	}

	// Character 2: Fire Type
	else if (choice == 2)
	{
		Character character2{};

		// Character 2 Stats
		character2.health = 100;
		character2.attack = 15;
		character2.defense = 5;
		character2.speed = 25;

		// Character 2 Attack 1
		character2.attack1;
		character2.attack1.name = "Fire Ball";
		character2.attack1.attackNum = 1;
		character2.attack1.attackDamage = 15;

		// Character 2 Attack 2
		character2.attack2;
		character2.attack2.name = "Lower Enemy Defense";
		character2.attack2.attackNum = 2;
		character2.attack2.defenseBoost = -5; // Lowers opponenet's defense stat by 5

		// Character 2 Stat Boost 1
		character2.statBoost1;
		character2.statBoost1.name = "Raise Attack";
		character2.statBoost1.attackNum = 3;
		character2.statBoost1.attackBoost = 5; // Raises your attack stat by 5

		// Character 2 Stat Boost 2
		character2.statBoost2;
		character2.statBoost2.name = "Raise Speed";
		character2.statBoost2.attackNum = 4;
		character2.statBoost2.speedBoost = 5; // Raise your speed stat by 5

		return character2;
	}

	// Character3: Grass Type
	else if (choice == 3) 
	{
		Character character3{};

		// Character 3 Stats
		character3.health = 100;
		character3.attack = 5;
		character3.defense = 20;
		character3.speed = 20;

		// Character 3 Attack 1
		character3.attack1;
		character3.attack1.name = "Grass Ball";
		character3.attack1.attackNum = 1;
		character3.attack1.attackDamage = 5;

		// Character 3 Attack 2
		character3.attack2;
		character3.attack2.name = "Lower Enemy Attack";
		character3.attack2.attackNum = 2;
		character3.attack2.attackBoost = -5; // Lowers enemy attack stat by 5

		// Character 3 Stat Boost 1
		character3.statBoost1;
		character3.statBoost1.name = "Raise Defense";
		character3.statBoost1.attackNum = 3;
		character3.statBoost1.defenseBoost = 5; // Raises your defense stat by 5

		// Character 3 Stat Boost 2
		character3.statBoost2;
		character3.statBoost2.name = "Raise Speed";
		character3.statBoost2.attackNum = 4;
		character3.statBoost2.speedBoost = 5; // Raises your speed by 5

		return character3;
	}
	
	else
	{
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');

		return selectCharacter();
	}
}

