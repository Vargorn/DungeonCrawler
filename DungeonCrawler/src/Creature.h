#pragma once
#include <iostream>


class Creature
{
protected:
	unsigned int level;
	unsigned int strength;
	unsigned int endurance;
	unsigned int agility;
	unsigned int intelligence;
	unsigned int luck;
	int health;
	int max_health;
	int healthRegen;
	int mana;
	int max_mana;
	int manaRegen;
	int stamina;
	int max_stamina;
	int staminaRegen;
	int dodgeChance;
	int critHit;

public: 
	void updateStats();
};


