#pragma once
#include "Creature.h"
#include "Player.h"

class Enemy : public Creature
{
private:
	std::string monster_nickName;
	std::string monster_name;
	std::string monster_class;
public:
	Enemy(std::string name, const int & playerLvl);	
	Enemy();
	void setStats();
	void showStats();
	void attack(Creature& target);
	void takeAction(Creature& target);
	int getXp();
};


