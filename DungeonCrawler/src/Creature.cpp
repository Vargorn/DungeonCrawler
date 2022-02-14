#include "Creature.h"

void Creature::updateStats() {
	this->max_mana = this->level * 10 + this->intelligence * 5;
	this->mana = this->max_mana;
	this->max_stamina = this->level * 10 + this->strength * 5;
	this->stamina = this->max_stamina;
	this->max_health = this->level * 10 + this->endurance * 5;
	this->health = this->max_health;
	this->dodgeChance = this->agility * 2;
	this->critHit = this->luck;
}

