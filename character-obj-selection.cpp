// Author: Seth Jackson

#include <iostream>
#include <string>
#include "attacks-struct.h"
#include "character-class.h"
#include "character-obj-selection.h"

using namespace std;

Character selectCharacter()
{
	cout << '\n' << "Type a number from 1 to 3 to select a character:" << '\n';
	int choice;
	cin >> choice;

	// Character Init Values: (health, attack, defense, speed)

	// Character 1: Water Type
	if (choice == 1)
	{
		Character character1("Water", 100, 10, 5, 30);

		// Build Character 1 Attack 1
		attackInfo attack1;
		attack1 = createAttack("Water Ball", 1);
		attack1.attackDamage = 10;
		character1.attack1 = attack1;

		// Build Character 1 Attack 2
		attackInfo attack2;
		attack2 = createAttack("Lower Enemy Defense", 2);
		attack2.defenseBoost = -5; // Lowers opponent's defense stat by 5
		character1.attack2 = attack2;

		// Build Character 1 Stat Boost 1
		attackInfo statBoost1;
		statBoost1 = createAttack("Raise Attack", 3);
		statBoost1.attackBoost = 5; // Raises your attack stat by 5
		character1.statBoost1 = statBoost1;

		// Build Character 1 Stat Boost 2
		attackInfo statBoost2;
		statBoost2 = createAttack("Raise Speed", 4);
		statBoost2.speedBoost = 5; // Raises your speed stat by 5
		character1.statBoost2 = statBoost2;

		return character1;
	}

	// Character 2: Fire Type
	else if (choice == 2)
	{
		Character character2("Fire", 100, 15, 5, 25);

		// Build Character 2 Attack 1
		attackInfo attack1;
		attack1 = createAttack("Fire Ball", 1);
		attack1.attackDamage = 15;
		character2.attack1 = attack1;

		// Character 2 Attack 2
		attackInfo attack2;
		attack2 = createAttack("Lower Enemy Defense", 2);
		attack2.defenseBoost = -5; // Lowers opponenet's defense stat by 5
		character2.attack2 = attack2;

		// Character 2 Stat Boost 1
		attackInfo statBoost1;
		statBoost1 = createAttack("Raise Attack", 3);
		statBoost1.attackBoost = 5;
		character2.statBoost1 = statBoost1;// Raises your attack stat by 5

		// Character 2 Stat Boost 2
		attackInfo statBoost2;
		statBoost2 = createAttack("Raise Speed", 4);
		statBoost2.speedBoost = 5; // Raise your speed stat by 5
		character2.statBoost2 = statBoost2; 

		return character2;
	}

	// Character3: Grass Type
	else if (choice == 3) 
	{
		Character character3("Grass", 100, 5, 20, 20);

		// Character 3 Attack 1
		attackInfo attack1;
		attack1 = createAttack("Grass Ball", 1);
		attack1.attackDamage = 5;
		character3.attack1 = attack1;

		// Character 3 Attack 2
		attackInfo attack2;
		attack2 = createAttack("Lower Enemy Attack", 2);
		attack2.attackBoost = -5; // Lowers enemy attack stat by 5
		character3.attack2 = attack2;

		// Character 3 Stat Boost 1
		attackInfo statBoost1;
		statBoost1 = createAttack("Raise Defense", 3);
		statBoost1.defenseBoost = 5; // Raises your defense stat by 5
		character3.statBoost1 = statBoost1;

		// Character 3 Stat Boost 2
		attackInfo statBoost2;
		statBoost2 = createAttack("Raise Speed", 4);
		statBoost2.speedBoost = 5; // Raises your speed by 5
		character3.statBoost2 = statBoost2;

		return character3;
	}
	
	else
	{
		cin.clear();
		cin.ignore(INT_MAX, '\n');

		return selectCharacter();
	}
}



