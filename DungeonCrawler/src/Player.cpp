#include "Player.h"
//to do dialog, story, intoduction.

Player::Player()
{
	this->level = 0;
	this->experience = 50;
	this->expTillNextLvl = 50;
	this->skill_points = 3;
	this->strength = 5;
	this->endurance = 5;
	this->agility = 5;
	this->intelligence = 5;
	this->luck = 5;	


	
	std::cout << "Enter your name: " << std::endl;
	std::cin >> this->name;
	std::cout << "Hello, " << this->name << std::endl;
	this->levelUp();

}

void Player::levelUp() {
	this->level++;
	this->skill_points += 2;
	this->experience -= this->expTillNextLvl;
	this->expTillNextLvl = this->expTillNextLvl * 2;
	while (this->skill_points > 0) {
		char atribute;
		std::cout << "--------------------------" << std::endl;
		std::cout << "You have " << this->skill_points << " skill points" << std::endl;
		std::cout << "Choose where to spend: \n s - strength \n e - endurance \n a - agility \n i - intelligence \n l - luck \n";
		std::cout << "--------------------------" << std::endl;
		std::cin >> atribute;
		std::cout << "--------------------------" << std::endl;
		switch (atribute) {
		case 's': this->strength++; this->skill_points--; break;
		case 'e': this->endurance++; this->skill_points--; break;
		case 'a': this->agility++; this->skill_points--; break;
		case 'i': this->intelligence++; this->skill_points--; break;
		case 'l': this->luck++; this->skill_points--; break;
		default: {
			std::cout << "Wrong input, fella "<< std::endl;
			std::cout << "--------------------------" << std::endl;
		}
		}
		this->updateStats();
		this->showStats();
	}
}
void Player::showStats() {
	std::cout << "Name: " << this->name << std::endl;
	std::cout << "Level: " << this->level << std::endl;
	std::cout << "Experience: " << this->experience << '/' << this->expTillNextLvl << std::endl;
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
void Player::attack(Creature& target) {

	this->stamina -= this->strength + 2;
	this->regen();
	if (rand() % 100 + 1 <= target.getDodgeChance()) {
		std::cout << "Enemy has dodged" << std::endl;
		std::cout << "--------------------------" << std::endl;
		return;
	}
	int damage = rand() % this->strength + 1;
	if (static_cast<unsigned int>(rand() % 100 + 1) <= this->luck) {
		damage = (rand() % this->strength + 1) * 2;
	}
	target.setHp(target.getHp() - damage);
	std::cout << "Enemy recieved: " << damage << " damage" << std::endl;
	std::cout << "--------------------------" << std::endl;
}
