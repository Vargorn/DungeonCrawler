#include "Creature.h"

void Creature::updateStats() {
	this->max_mana = this->level * 5 + this->intelligence * 5;
	this->max_stamina = this->level * 5 + this->strength * 5;
	this->max_health = this->level * 5 + this->endurance * 5;
	this->dodgeChance = this->agility * 2;
	this->critHit = this->luck;
	this->healthRegen = this->level / 5;
	this->staminaRegen = this->endurance / 2 + 1;
	this->manaRegen = this->intelligence / 2 + 1;
}
void Creature::wait() {
	this->regen();
	this->regen();
}
void Creature::setmsh() {
	this->mana = this->max_mana;
	this->stamina = this->max_stamina;
	this->health = this->max_health;
}
void Creature::regen()
{
	this->health += this->healthRegen;
	this->mana += this->manaRegen;
	this->stamina += this->staminaRegen;
	if (this->health > this->max_health) {
		this->health = this->max_health;
	}
	if (this->mana > this->max_mana) {
		this->mana = this->max_mana;
	}
	if (this->stamina > this->max_stamina) {
		this->stamina = this->max_stamina;
	}
}
void Creature::setHp(int health) {
	this->health = health;
}
void Creature::setStamina(int stamina)
{
	this->stamina = stamina;
}
void Creature::setMana(int mana)
{
	this->mana = mana;
}
int Creature::getDodgeChance() {
	return this->dodgeChance;
}
int Creature::getHp() {
	return this->health;
}
int Creature::getStamina()
{
	return this->stamina;
}
int Creature::getMana()
{
	return this->mana;
}
unsigned int Creature::getLevel()
{
	return this->level;
}
