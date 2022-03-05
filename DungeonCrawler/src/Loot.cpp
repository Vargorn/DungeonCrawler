#include"pch.h"
#include "Loot.h"

Loot::Loot(){
	this->type = ITEMS::NONE;
}

Loot::Loot(int level) {
	this->initItem();
	this->type = rand() % (ITEMS::ITEMS_SIZE - 1) + 1;
	this->material = this->materials[rand() % this->materials.size()];
	if (this->material == "Leather") {
		this->bonuses.push_back(LootBonus("Agility", 1));
		this->bonuses.push_back(LootBonus("Endurance", 1));
	}
	else if (this->material == "Foil" ) {
		this->bonuses.push_back(LootBonus("Luck", 2));
	}
	else if (this->material == "Silk" ) {
		this->bonuses.push_back(LootBonus("Intelligence", 2));
		this->bonuses.push_back(LootBonus("Agility", 1));
	}
	else if (this->material == "Wooden" ) {
		this->bonuses.push_back(LootBonus("Strength", 1));
		this->bonuses.push_back(LootBonus("Agility", -2));
	}
	else if (this->material == "Glass" ) {
		this->bonuses.push_back(LootBonus("Intelligence", 1));
		this->bonuses.push_back(LootBonus("Endurance", -1));
	}
	else if (this->material == "Steel" ) {
		this->bonuses.push_back(LootBonus("Strength", 2));
		this->bonuses.push_back(LootBonus("Endurance", 1));
		this->bonuses.push_back(LootBonus("Agility", -1));
	}
	else if (this->material == "Ebony" ) {
		this->bonuses.push_back(LootBonus("Strength", 1));
		this->bonuses.push_back(LootBonus("Endurance", 3));
		this->bonuses.push_back(LootBonus("Agility", -2));
	}
	else if (this->material == "Bronze" ) {
		this->bonuses.push_back(LootBonus("Endurance", 1));
		this->bonuses.push_back(LootBonus("Luck", 1));
	}
	else if (this->material == "Fur" ) {
		this->bonuses.push_back(LootBonus("Agility", 1));
		this->bonuses.push_back(LootBonus("Endurance", 2));
	}
	switch (this->type)
	{
		case ITEMS::HEAD: {
			this->name = this->helms[rand() % this->helms.size()];
			if (this->name == "Mask") {
				this->bonuses.push_back(LootBonus("Agility", 1));
				this->bonuses.push_back(LootBonus("Intelligence", 1));
			}
			else if (this->name == "Hat") {
				this->bonuses.push_back(LootBonus("Intelligence", 1));
				this->bonuses.push_back(LootBonus("Luck", 1));
			}
			else if (this->name == "Hood") {
				this->bonuses.push_back(LootBonus("Agility", 2));
			}
			else if (this->name == "Cap") {
				this->bonuses.push_back(LootBonus("Endurance", 1));
				this->bonuses.push_back(LootBonus("Luck", 1));
			}
			else if (this->name == "Cape") {
				this->bonuses.push_back(LootBonus("Agility", 1));
				this->bonuses.push_back(LootBonus("Intelligence", -1));
				this->bonuses.push_back(LootBonus("Luck", 1));
			}
			break;
		}
		case ITEMS::BODY: {
			this->name = this->armor[rand() % this->armor.size()];
			if (this->name == "Chainmail") {
				this->bonuses.push_back(LootBonus("Endurance", 2));
				this->bonuses.push_back(LootBonus("Strength", 1));
			}
			else if (this->name == "Plaitmail") {
				this->bonuses.push_back(LootBonus("Strength", 2));
				this->bonuses.push_back(LootBonus("Endurance", 1));
				this->bonuses.push_back(LootBonus("Agility", -1));
			}
			else if (this->name == "Cuirass") {
				this->bonuses.push_back(LootBonus("Strength", 3));
			}
			else if (this->name == "Robe") {
				this->bonuses.push_back(LootBonus("Luck", 1));
				this->bonuses.push_back(LootBonus("Intelligence", 2));
			}
			else if (this->name == "Coat") {
				this->bonuses.push_back(LootBonus("Agility", 2));
				this->bonuses.push_back(LootBonus("Intelligence", 1));
			}
			break;
		}
		case ITEMS::HAND: {
			this->name = this->gloves[rand() % this->gloves.size()];
			break;
		}
		case ITEMS::SHOULDERS: {
			this->name = this->shoulders[rand() % this->shoulders.size()];
			break;
		}
		case ITEMS::LEGS: {
			this->name = this->trousers[rand() % this->trousers.size()];
			break;
		}
		case ITEMS::FEET: {
			this->name = this->boots[rand() % this->boots.size()];
			break;
		}
		case ITEMS::FINGER: {
			this->name = this->rings[rand() % this->rings.size()];
			break;
		}
		case ITEMS::WEAPON: {
			this->name = this->weapons[rand() % this->weapons.size()];
			break;
		}
	}
	std::cout << "You have recived " << this->material << " " << this->name << std::endl;
	std::cout << "--------------------------" << std::endl;
}
	
void Loot::initItem() {
	this->materials = { "Leather", "Foil", "Silk", "Wooden", "Glass", "Steel", "Ebony", "Bronze", "Fur" };
	this->armor = { "Chainmail", "Plaitmail" , "Cuirass" , "Robe" , "Coat" };
	this->boots = { "Sandals", "Socks", "Greaves", "Boots" };
	this->helms = { "Mask", "Hat", "Hood", "Cap", "Cape" };
	this->rings = { "Signet", "Arcane Ring", "Essence Ring", "Ring of Khajiit", "Ring of Disrobing" , "Ring of the Iron Fist" , "Ring of Burden", "Ring of Protection", "Ring of Regen" };
	this->trousers = { "Raekor’s Breeches", "Hammer Jammers", "Pox Faulds", "Hexing Pants of Mr. Yan", "Swamp Land Waders", "Depth Diggers" };
	this->shoulders = { "Vile Ward", "Pauldrons of the Skeleton King", "Spaulders of Zakara", " Asheara's Custodian" };
	this->weapons = { "Mace", "Sword", "Warhammer", "Knife", "Bow", "Crossbow", "Staff", "Wand", "Axe", "Stick" };
	this->gloves = { "Jester's Gloves", "Mystic Tuning Gloves", "Mythic Dawn Gloves", "Prisoner's Cuffs", "Psiijic Gloves", "Ulfric's Bracers", "Shrouded Hand Wraps" };
}

void Loot::getInfo()
{
	std::cout << this->material << " " << this->name << ": ";
	for (auto i : this->bonuses) {
		std::cout << i.getName() << " " << (i.getValue() > 0 ? "+" : "") << i.getValue() << " ";
	}
	std::cout << std::endl;
	std::cout << "--------------------------" << std::endl;
}

int Loot::getType()
{
	return this->type;
}

std::vector<LootBonus> Loot::getBonuses()
{
	return this->bonuses;
}
