#include "Loot.h"
Loot::Loot() {
	this->initItem();
	this->slot = rand() % ITEMS::ITEMS_SIZE;
	this->material = this->materials[rand() % this->materials.size()];
	if (this->material == "Leather") {
		this->bonuses.push_back(LootBonus("Strength", 1));
	}
	else if (this->material == "Foil" ) {
	
	}
	else if (this->material == "Silk" ) {

	}
	else if (this->material == "Wooden" ) {

	}
	else if (this->material == "Glass" ) {

	}
	else if (this->material == "Steel" ) {

	}
	else if (this->material == "Ebony" ) {

	}
	else if (this->material == "Bronze" ) {

	}
	else if (this->material == "Fur" ) {

	}
	switch (this->slot)
	{
		case ITEMS::HEAD: {
			this->name = this->helms[rand() % this->helms.size()];
			break;
		}
		case ITEMS::BODY: {
			this->name = this->armor[rand() % this->armor.size()];
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
	}
	
void Loot::initItem() {
	this->materials = { "Leather", "Foil", "Silk", "Wooden", "Glass", "Steel", "Ebony", "Bronze", "Fur" };
	this->armor = { "Chainmail", "Plaitmail" , "Cuirasses" , "Robe" , "Coat" };
	this->boots = { "Sandals", "Socks", "Greaves", "Boots" };
	this->helms = { "Mask", "Hat", "Hood", "Cap", "Cape" };
	this->rings = { "Signet", "Arcane Ring", "Essence Ring", "Ring of Khajiit", "Ring of Disrobing" , "Ring of the Iron Fist" , "Ring of Burden", "Ring of Protection", "Ring of Regen" };
	this->trousers = { "Raekor’s Breeches", "Hammer Jammers", "Pox Faulds", "Hexing Pants of Mr. Yan", "Swamp Land Waders", "Depth Diggers" };
	this->shoulders = { "Vile Ward", "Pauldrons of the Skeleton King", "Spaulders of Zakara", " Asheara's Custodian" };
	this->weapons = { "Mace", "Sword", "Warhammer", "Knife", "Bow", "Crossbow", "Staff", "Wand", "Axe", "Stick" };
	this->gloves = { "Jester's Gloves", "Mystic Tuning Gloves", "Mythic Dawn Gloves", "Prisoner's Cuffs", "Psiijic Gloves", "Ulfric's Bracers", "Shrouded Hand Wraps" };
}