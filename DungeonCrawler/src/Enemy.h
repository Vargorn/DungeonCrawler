#pragma once
#include "Creature.h"





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
};


