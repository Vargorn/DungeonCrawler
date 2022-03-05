#pragma once
#include "Creature.h"
#include "Enemy.h"
#include "Loot.h"


class Player : public Creature
{
private:
	std::string name;	
	int bonus_strength;
	int bonus_endurance;
	int bonus_agility;
	int bonus_intelligence;
	int bonus_luck;
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
	void updateStats() override;
	void reciveLoot(const unsigned int& a);
	int getLuck() override;
};