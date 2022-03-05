#include"pch.h"
#include "Player.h"
#define I(i) (static_cast<size_t>(i -'0'))
//TODO Dialog, Story, Intoduction.

Player::Player()
{
	this->level = 0;
	this->expTillNextLvl = 25;
	this->experience = this->expTillNextLvl;
	this->skill_points = 3;
	this->strength = 5;
	this->endurance = 5;
	this->agility = 5;
	this->intelligence = 5;
	this->luck = 5;	

	this->bonus_strength = 0;
	this->bonus_endurance = 0;
	this->bonus_agility = 0;
	this->bonus_intelligence = 0;
	this->bonus_luck = 0;
	//this->reciveLoot(1);


	std::cout << "Stand up. There you go. You were dreaming. What's your name?" << std::endl;
	std::cout << "Enter your name: " << std::endl;
	std::cin >> this->name;
	std::cout << "So your name is " << this->name << ", correct?" << std::endl;
	std::cout << "--------------------------" << std::endl;
	this->levelUp();

}

void Player::levelUp() {
	this->level++;
	this->skill_points += 2;
	this->experience -= this->expTillNextLvl;
	this->expTillNextLvl = this->expTillNextLvl * 1.5f;
	std::cout << "Level Up!" << std::endl;
	std::cout << "--------------------------" << std::endl;
	while (this->skill_points > 0) {
		char atribute;
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
			std::cout << "Wrong Input"<< std::endl;
			std::cout << "--------------------------" << std::endl;
		}
		}
		this->updateStats();
		this->setmsh();
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
	if (this->bonus_strength >= 0) {
		std::cout << "Strength: " << this->strength << " + " << this->bonus_strength << " " << std::endl;
	}
	else {
		std::cout << "Strength: " << this->strength << " - " << -this->bonus_strength << std::endl;
	}
	if (this->bonus_endurance >= 0) {
		std::cout << "Endurance: " << this->endurance << " + " << this->bonus_endurance << std::endl;
	}
	else {
		std::cout << "Endurance: " << this->endurance << " - " << -this->bonus_endurance << std::endl;
	}
	if (this->bonus_agility >= 0) {
		std::cout << "Agility: " << this->agility << " + " << this->bonus_agility << std::endl;
	}
	else {
		std::cout << "Agility: " << this->agility << " - " << -this->bonus_agility << std::endl;
	}
	if (this->bonus_intelligence >= 0) {
		std::cout << "Intelligence: " << this->intelligence << " + " << this->bonus_intelligence << std::endl;
	}
	else {
		std::cout << "Intelligence: " << this->intelligence << " - " << -this->bonus_intelligence << std::endl;
	}
	if (this->bonus_luck >= 0) {
		std::cout << "Luck: " << this->luck << " + " << this->bonus_luck << std::endl;
	}
	else {
		std::cout << "Luck: " << this->luck << " - " << -this->bonus_luck << std::endl;
	}
	std::cout << "Dodge chance: " << this->dodgeChance << '%' << std::endl;
	std::cout << "Crit chance: " << this->critHit << '%' << std::endl;
	std::cout << "--------------------------" << std::endl;
}
void Player::attack(Creature& target) {
	this->stamina -= (FATIGUE + this->bonus_strength);
	this->regen();
	if (target.getDodgeChance() > 0 && target.getStamina() >= this->agility + this->bonus_agility && rand() % 100 + 1 <= target.getDodgeChance()) {
		target.setStamina(target.getStamina() - (this->agility + this->bonus_agility));
		std::cout << "Enemy has dodged" << std::endl;
		std::cout << "--------------------------" << std::endl;
		return;
	}
	int damage = rand() % (this->strength + this->bonus_strength) + 1;
	if (this->stamina <= 0) {
		damage /= 2;
		std::cout << "Player has run out of stamina" << std::endl;
	}
	if (static_cast<unsigned int>(rand() % 100 + 1) <= this->luck) {
		damage *= 2;
	}
	target.setHp(target.getHp() - damage);
	std::cout << "Enemy recieved: " << damage << " damage" << std::endl;
	std::cout << "--------------------------" << std::endl;
}
int Player::getXp() { 
	return this->experience;
}
int Player::getXpTillNextLvl()
{
	return this->expTillNextLvl;
}
void Player::setXp(int exp) {
	this->experience = exp;
}
void Player::openInventory()
{
	if (this->backpack.size() == 0) {
		std::cout << "It's empty" << std::endl;
		std::cout << "--------------------------" << std::endl;
		return;
	}
	int counter = 1;
	for (auto i : this->backpack) {
		std::cout << counter << " - ";
		i.getInfo();
		counter++;
	}
	while (true) {
		char a;
		std::cout << "--------------------------" << std::endl;
		std::cout << "Enter item index to equip it or enter 0 to continue " << std::endl;
		std::cout << "--------------------------" << std::endl;
		std::cin >> a;
		std::cout << "--------------------------" << std::endl;
		if (I(a) <= this->backpack.size() && I(a) > 0) {
			this->equipment.push_back(this->backpack[I(a) - 1]);
			std::cout << "You equiped ";
			this->backpack[I(a) - 1].getInfo();
			this->backpack.erase(this->backpack.begin() + I(a) - 1);
			this->updateStats();
			return;
		}
		else if (I(a) == 0) {
			return;
		}
		else {
			std::cout << "Wrong Input" << std::endl;
			std::cout << "--------------------------" << std::endl;
		}
		
	}
}
void Player::updateStats() 
{
	this->bonus_strength = 0;
	this->bonus_endurance = 0;
	this->bonus_agility = 0;
	this->bonus_intelligence = 0;
	this->bonus_luck = 0;

	for (auto& item : this->equipment)
	{
		if (item.getType() < 9 && item.getType() > 0) {
			for (auto& bonus : item.getBonuses())
			{
				if (bonus.getName() == "Strength") {
					this->bonus_strength += bonus.getValue();
				}
				if (bonus.getName() == "Intelligence") {
					this->bonus_intelligence += bonus.getValue();
				}
				if (bonus.getName() == "Endurance") {
					this->bonus_endurance += bonus.getValue();
				}
				if (bonus.getName() == "Agility") {
					this->bonus_agility += bonus.getValue();
				}
				if (bonus.getName() == "Luck") {
					this->bonus_luck += bonus.getValue();
				}
			}
		}
	}
	this->max_mana = this->level * 5 + (this->intelligence + this->bonus_intelligence)  * 5;
	this->max_stamina = this->level * 5 + (this->strength + this->bonus_strength) * 5;
	this->max_health = this->level * 5 + (this->endurance + this->bonus_endurance) * 5;
	this->dodgeChance = (this->agility + this->bonus_agility) * 2;
	this->critHit = (this->luck + this->bonus_luck);
	this->healthRegen = this->level / 5;
	this->staminaRegen = (this->endurance + this->bonus_endurance) / 2 + 1;
	this->manaRegen = (this->intelligence + this->bonus_intelligence) / 2 + 1;
}
void Player::reciveLoot(const unsigned int& level)
{
	this->backpack.push_back(Loot(level));
}