#ifndef ATTACKS_STRUCT_H
#define ATTACKS_STRUCT_H

struct attackInfo
{
	std::string name{"no name"};
	int attackNum{0};
	int attackDamage{0};
	int attackBoost{ 0 };
	int defenseBoost{ 0 };
	int speedBoost{ 0 };
};

#endif