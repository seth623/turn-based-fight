#include "attacks-struct.h"

attackInfo createAttack(string attkName, int attkNum)
{
	attackInfo createdAttack;

	createdAttack.name = attkName;
	createdAttack.attackNum = attkNum;

	createdAttack.attackDamage;
	createdAttack.attackBoost;
	createdAttack.defenseBoost;
	createdAttack.speedBoost;

	createdAttack.attackDamage = 0;
	createdAttack.attackBoost = 0;
	createdAttack.defenseBoost = 0;
	createdAttack.speedBoost = 0;

	return createdAttack;
}
