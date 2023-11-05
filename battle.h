#ifndef BATTLE_H
#define BATTLE_H

Character attackChange(attackInfo attackBoost, Character &player);

Character battle(Character &player1, Character &player2);

Character damageCalculation(attackInfo attackChoice, Character attackingPlayer, Character defendingPlayer);

Character defenseChange(attackInfo defenseBoost, Character &player);

int inputAttackChoice(int playerNum);

Character speedChange(attackInfo speedBoost, Character &player);

Character turn(Character fastPlayer, Character slowPlayer);

#endif
