#ifndef ATTACKS_STRUCT_H
#define ATTACKS_STRUCT_H
#include <string>

using namespace std;

struct attackInfo
{
	string name{"null"};
	int attackNum{ 0 };
	int attackDamage{0};
	int attackBoost{0};
	int defenseBoost{0};
	int speedBoost{ 0 };
};

attackInfo createAttack(string attkName, int attkNum);

#endif