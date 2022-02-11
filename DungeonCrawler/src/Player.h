#pragma once
#include "Creature.h"

class Player : public Creature
{
private:
	std::string name;
	unsigned int level;
	unsigned int skill_points;
	unsigned int expirience;
	unsigned int expTillNextLvl;


public:
	Player();

	void levelUp();
	void showStats();
};

