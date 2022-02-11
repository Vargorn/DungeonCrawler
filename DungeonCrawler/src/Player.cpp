#include "Player.h"
//to do dialog, story, intoduction.
Player::Player()
{
	this->level = 0;
	this->expirience = 50;
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
	this->expirience -= this->expTillNextLvl;
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
		this->showStats();
	}
}
void Player::showStats() {
	std::cout << "Name: " << this->name << std::endl;
	std::cout << "Level: " << this->level << std::endl;
	std::cout << "Expirience: " << this->expirience << '/' << this->expTillNextLvl << std::endl;
	std::cout << "Strength: " << this->strength << std::endl;
	std::cout << "Endurance: " << this->endurance << std::endl;
	std::cout << "Agility: " << this->agility << std::endl;
	std::cout << "Intrlligence: " << this->intelligence << std::endl;
	std::cout << "Luck: " << this->luck << std::endl;
}