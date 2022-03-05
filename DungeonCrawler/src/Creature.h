#pragma once
#define FATIGUE this->strength + 2
class Creature
{
protected:
	unsigned int level;
	int strength;
	int endurance;
	int agility;
	int intelligence;
	int luck;
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


