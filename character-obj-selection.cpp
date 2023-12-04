// Author: Seth Jackson

#include <iostream>
#include <string>
#include <array>
#include "attacks-struct.h"
#include "character-class.h"
#include "character-obj-selection.h"

using namespace std;

Character selectCharacter()
{
	Character optionArray[3]; // 5. Array

	cout << '\n' << "Type a number from 1 to 3 to select a character:" << '\n';
	int choice;
	cin >> choice;

	// Character Init Values: (health, attack, defense, speed)

	// Character 1: Water Type
	Character character1("Water", 100, 15, 10, 30);

	// Build Character 1 Attack 1
	attackInfo char1Attack1;
	char1Attack1 = createAttack("Water Ball", 1);
	char1Attack1.attackDamage = 10;
	character1.attack1 = char1Attack1;

	// Build Character 1 Attack 2
	attackInfo char1Attack2;
	char1Attack2 = createAttack("Lower Enemy Defense", 2);
	char1Attack2.defenseBoost = -5; // Lowers opponent's defense stat by 5
	character1.attack2 = char1Attack2;

	// Build Character 1 Stat Boost 1
	attackInfo char1StatBoost1;
	char1StatBoost1 = createAttack("Raise Attack", 3);
	char1StatBoost1.attackBoost = 5; // Raises your attack stat by 5
	character1.statBoost1 = char1StatBoost1;

	// Build Character 1 Stat Boost 2
	attackInfo char1StatBoost2;
	char1StatBoost2 = createAttack("Raise Speed", 4);
	char1StatBoost2.speedBoost = 5; // Raises your speed stat by 5
	character1.statBoost2 = char1StatBoost2;

	optionArray[0] = character1;

	//*******************************************

	// Character 2: Fire Type
	Character character2("Fire", 100, 20, 5, 25);

	// Build Character 2 Attack 1
	attackInfo char2Attack1;
	char2Attack1 = createAttack("Fire Ball", 1);
	char2Attack1.attackDamage = 15;
	character2.attack1 = char2Attack1;

	// Character 2 Attack 2
	attackInfo char2Attack2;
	char2Attack2 = createAttack("Lower Enemy Defense", 2);
	char2Attack2.defenseBoost = -5; // Lowers opponenet's defense stat by 5
	character2.attack2 = char2Attack2;

	// Character 2 Stat Boost 1
	attackInfo char2StatBoost1;
	char2StatBoost1 = createAttack("Raise Attack", 3);
	char2StatBoost1.attackBoost = 5;
	character2.statBoost1 = char2StatBoost1;// Raises your attack stat by 5

	// Character 2 Stat Boost 2
	attackInfo char2StatBoost2;
	char2StatBoost2 = createAttack("Raise Speed", 4);
	char2StatBoost2.speedBoost = 5; // Raise your speed stat by 5
	character2.statBoost2 = char2StatBoost2;

	optionArray[1] = character2;

	//*******************************************

	// Character3: Grass Type
	Character character3("Grass", 100, 10, 15, 20);

	// Character 3 Attack 1
	attackInfo char3Attack1;
	char3Attack1 = createAttack("Grass Ball", 1);
	char3Attack1.attackDamage = 5;
	character3.attack1 = char3Attack1;

	// Character 3 Attack 2
	attackInfo char3Attack2;
	char3Attack2 = createAttack("Lower Enemy Attack", 2);
	char3Attack2.attackBoost = -5; // Lowers enemy attack stat by 5
	character3.attack2 = char3Attack2;

	// Character 3 Stat Boost 1
	attackInfo char3StatBoost1;
	char3StatBoost1 = createAttack("Raise Defense", 3);
	char3StatBoost1.defenseBoost = 5; // Raises your defense stat by 5
	character3.statBoost1 = char3StatBoost1;

	// Character 3 Stat Boost 2
	attackInfo char3StatBoost2;
	char3StatBoost2 = createAttack("Raise Attack", 4);
	char3StatBoost2.attackBoost = 5; // Raises your speed by 5
	character3.statBoost2 = char3StatBoost2;	

	optionArray[2] = character3;

	//*******************************************

	if (choice == 1)
	{
		return optionArray[0];
	}
	else if (choice == 2)
	{
		return optionArray[1];
	}
	else if (choice == 3)
	{
		return optionArray[2];
	}
	else
	{
		cin.clear();
		cin.ignore(INT_MAX, '\n');

		return selectCharacter();
	}
}




