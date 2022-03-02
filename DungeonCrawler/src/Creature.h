#pragma once
#include <iostream>
#define FATIGUE this->strength + 2
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
	virtual void updateStats();
	void regen();
	void wait();
	//void castSpell();
	//void useConsumable();
	void setmsh();
	void setHp(int health);
	void setStamina(int stamina);
	void setMana(int mana);
	int getDodgeChance();
	int getHp();
	int getStamina();
	int getMana();
	unsigned int getLevel();
	

};


