#include "Enemy.h"


Enemy::Enemy(std::string name, const int& playerLvl) {
	this->level = playerLvl;

	unsigned int first = name.find_first_of(' ');
	unsigned int last = name.find_last_of(' ');
	this->monster_nickName = name.substr(0, first);
	this->monster_name = name.substr(first + 1, last - first - 1);
	this->monster_class = name.substr(last + 1, name.size() - 1);
	this->setStats();
}

Enemy::Enemy()
{
}

void Enemy::setStats()
{
	if (this->monster_name == "Goblin")
	{
		this->strength = 1 * this->level + 2;
		this->endurance = 1 * this->level + 2;
		this->agility = 3 * this->level + 2;
		this->intelligence = 2 * this->level + 2;
		this->luck = 3 * this->level + 2;
	}
	else if (this->monster_name == "Ogre")
	{
		this->strength = 3 * this->level + 2;
		this->endurance = 2 * this->level + 1;
		this->agility = 1 * this->level + 1;
		this->intelligence = 1 * this->level + 1;
		this->luck = 1 * this->level + 1;
	}
	else if (this->monster_name == "Orc")
	{
		this->strength = 2 * this->level + 2;
		this->endurance = 2 * this->level + 1;
		this->agility = 1 * this->level + 1;
		this->intelligence = 2 * this->level + 1;
		this->luck = 1 * this->level + 2;
	}
	else if (this->monster_name == "Troll")
	{
		this->strength = 3 * this->level + 2;
		this->endurance = 2 * this->level;
		this->agility = 1 * this->level + 1;
		this->intelligence = 1 * this->level + 1;
		this->luck = 1 * this->level + 1;
	}
	else if (this->monster_name == "Banshee")
	{
		this->strength = 1 * this->level + 1;
		this->endurance = 1 * this->level + 1;
		this->agility = 2 * this->level + 2;
		this->intelligence = 3 * this->level + 2;
		this->luck = 2 * this->level + 1;
	}
	else if (this->monster_name == "Chimera")
	{
		this->strength = 2 * this->level + 3;
		this->endurance = 2 * this->level + 3;
		this->agility = 2 * this->level + 2;
		this->intelligence = 1 * this->level + 2;
		this->luck = 2 * this->level + 1;
	}
	else if (this->monster_name == "Vampire")
	{
		this->strength = 2 * this->level + 2;
		this->endurance = 1 * this->level + 2;
		this->agility = 2 * this->level + 2;
		this->intelligence = 3 * this->level + 2;
		this->luck = 2 * this->level + 2;
	}
	else if (this->monster_name == "Shoggoth")
	{
		this->strength = 1 * this->level + 2;
		this->endurance = 3 * this->level + 1;
		this->agility = 1 * this->level + 1;
		this->intelligence = 1 * this->level + 1;
		this->luck = 1 * this->level + 1;
	}
	else if (this->monster_name == "Fishman")
	{
		this->strength = 1 * this->level + 2;
		this->endurance = 1 * this->level + 1;
		this->agility = 3 * this->level + 1;
		this->intelligence = 1 * this->level + 1;
		this->luck = 3 * this->level + 1;
	}
	else if (this->monster_name == "Centaur")
	{
		this->strength = 2 * this->level + 2;
		this->endurance = 2 * this->level + 2;
		this->agility = 2 * this->level + 1;
		this->intelligence = 1 * this->level + 1;
		this->luck = 2 * this->level + 1;
	}
	else if (this->monster_name == "Cerberus")
	{
		this->strength = 2 * this->level + 2;
		this->endurance = 2 * this->level + 2;
		this->agility = 2 * this->level + 2;
		this->intelligence = 1 * this->level + 1;
		this->luck = 2 * this->level + 1;
	}
	else if (this->monster_name == "Harpy")
	{
		this->strength = 2 * this->level + 2;
		this->endurance = 2 * this->level + 2;
		this->agility = 2 * this->level + 2;
		this->intelligence = 2 * this->level + 2;
		this->luck = 2 * this->level + 2;
	}
	
	if (this->monster_nickName == "Sneeky") {
		this->agility += 2;
	}
	else if (this->monster_nickName == "Crazy") {
		this->agility -= 1;
		this->intelligence += 3;
	}
	else if (this->monster_nickName == "Big") {
		this->agility -= 2;
		this->endurance += 2;
		this->strength += 2;
	}
	else if (this->monster_nickName == "Fat") {
		this->agility -= 3;
		this->endurance += 5;
	}
	else if (this->monster_nickName == "Annoying") {
		this->agility += 1;
		this->intelligence += 1;
	}
	else if (this->monster_nickName == "Terrifying") {
		this->strength += 2;
		this->intelligence += 2;
	}
	else if (this->monster_nickName == "Smart") {
		this->intelligence += 3;
	}
	else if (this->monster_nickName == "Drunk") {
		this->intelligence -= 2;
		this->agility -= 2;
		this->strength += 4;
	}
	else if (this->monster_nickName == "Stinky") {
		this->intelligence -= 2;
		this->endurance += 4;
	}
	else if (this->monster_nickName == "Stinky") {
		this->agility += 2;
	}
	else if (this->monster_nickName == "Lame") {
		this->agility -= 1;
		this->endurance -= 1;
		this->intelligence -= 1;
		this->luck -= 1;
		this->strength -= 1;
	}
	else if (this->monster_nickName == "Cocky") {
		this->endurance += 1;
		this->intelligence -= 1;
		this->luck += 1;
		this->strength += 1;
	}

	if (this->monster_class == "Skirmisher") {
		this->agility += 2;
	}
	else if (this->monster_class == "Mage") {
		this->intelligence += 2;
	}
	else if (this->monster_class == "Ambusher") {
		this->agility += 1;
		this->luck += 1;
	}
	else if (this->monster_class == "Reaper") {
		this->strength += 1;
		this->endurance += 1;
	}
	else if (this->monster_class == "Leader") {
		this->strength += 1;
		this->endurance += 1;
		this->luck += 1;
		this->agility += 1;
		this->intelligence += 1;
	}
	else if (this->monster_class == "Dispoiler") {
		this->strength += 2;
		this->endurance += 1;
		this->agility -= 2;
		this->intelligence += 1;
	}
	else if (this->monster_class == "Arsonist") {
		this->endurance += 1;
		this->luck += 2;
		this->agility += 2;
		this->strength -= 2;
	}
	else if (this->monster_class == "Lunatic") {
		this->strength -= 1;
		this->endurance -= 1;
		this->agility -= 1;
		this->intelligence -= 1;
	}
	else if (this->monster_class == "Nightlord") {
		this->strength += 2;
		this->endurance += 1;
		this->agility += 2;
		this->intelligence += 1;
	}


	this->updateStats();
	this->showStats();

}
void Enemy::showStats() {
	std::cout << "--------------------------" << std::endl;
	std::cout << "Name: " << this->monster_nickName << ' ' << this->monster_name << ' ' << this->monster_class << std::endl;
	std::cout << "Mana: " << this->mana << '/' << this->max_mana << std::endl;
	std::cout << "Health: " << this->health << '/' << this->max_health << std::endl;
	std::cout << "Stamina: " << this->stamina << '/' << this->max_stamina << std::endl;
	std::cout << "Strength: " << this->strength << std::endl;
	std::cout << "Endurance: " << this->endurance << std::endl;
	std::cout << "Agility: " << this->agility << std::endl;
	std::cout << "Intelligence: " << this->intelligence << std::endl;
	std::cout << "Luck: " << this->luck << std::endl;
	std::cout << "Dodge chance: " << this->dodgeChance << '%' << std::endl;
	std::cout << "Crit chance: " << this->critHit << '%' << std::endl;
}
void Enemy::attack(Creature& target) {
	this->stamina -= this->strength + 2;
	this->regen();
	if (rand() % 100 + 1 <= target.getDodgeChance()) {
		std::cout << "Player has dodged" << std::endl;
		std::cout << "--------------------------" << std::endl;
		return;
	}
	int damage = rand() % this->strength + 1;
	if (static_cast<unsigned int>(rand() % 100 + 1) <= this->luck) {
		damage = (rand() % this->strength + 1) * 2;
	}
	target.setHp(target.getHp() - damage);
	std::cout << "Player recieved: " << damage << " damage" << std::endl;
	std::cout << "--------------------------" << std::endl;
}

void Enemy::takeAction()
{
	//this->attack()
}
int Enemy::getXp()
{
	return this->strength + this->endurance + this->agility + this->intelligence + this->luck;
}		  