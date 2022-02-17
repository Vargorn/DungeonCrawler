#pragma once
#include "Creature.h"
#include "Enemy.h"

class Player : public Creature
{
private:
	std::string name;	
	unsigned int skill_points;
	unsigned int experience;
	unsigned int expTillNextLvl;

	//TODO inventory, backpack

public:
	Player();
	void levelUp();
	void showStats();
	void attack(Creature& target);
	
};

