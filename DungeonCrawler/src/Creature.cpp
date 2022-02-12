#include "Creature.h"

void Creature::updateStats() {
	this->mana = this->level * 10 + this->intelligence * 5;
	this->stamina = this->level * 10 + this->strength * 5;
	this->health = this->level * 10 + this->endurance * 5;
	this->dodgeChance = this->agility * 2;
	this->critHit = this->luck;
}

