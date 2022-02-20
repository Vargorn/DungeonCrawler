#include "Loot.h"

Loot::Loot() {
	this->initItem();
	switch (this->slot)
	{
	case ITEMS::HEAD: {
		break;
	}
	case ITEMS::BODY: {
		break;
	}
	case ITEMS::HAND: {
		break;
	}
	case ITEMS::SHOULDERS: {
		break;
	}
	case ITEMS::LEGS: {
		break;
	}
	case ITEMS::FEET: {
		break;
	}
	case ITEMS::FINGER: {
		break;
	}
	case ITEMS::WEAPON: {
		break;
	}
	}
}

void Loot::initItem() {
	this->material = { "Leather", "Foil", "Silk", "Wooden", "Glass", "Steel", "Ebony", "Bronze", "Uranus" };




}