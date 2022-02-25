#pragma once
#include "Creature.h"
#include "Enemy.h"
#include "Loot.h"
#include <array>


class Player : public Creature
{
private:
	std::string name;	
	unsigned int skill_points;
	unsigned int experience;
	unsigned int expTillNextLvl;
	std::vector<Loot> equipment;
	std::vector<Loot> backpack;


public:
	Player();
	void levelUp();
	void showStats();
	void attack(Creature& target);
	int getXp();
	int getXpTillNextLvl();
	void setXp(int exp);
	void openInventory();
	void updateStats();
	void reciveLoot(const unsigned int& a);
};

