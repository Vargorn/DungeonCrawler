#pragma once
#include "Creature.h"
#include "Enemy.h"

class Player : public Creature
{
private:
	std::string name;	
	unsigned int skill_points;
	unsigned int expirience;
	unsigned int expTillNextLvl;

	//TODO inventory, backpack

public:
	Player();
	void levelUp();
	void showStats();
	int getDodgeChance();
	void attack(Enemy& target);
	
};

