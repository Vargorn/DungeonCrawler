#include"pch.h"
#include "LootBonus.h"

LootBonus::LootBonus(std::string name, int value) {
	this->name = name;
	this->value = value;
}
std::string LootBonus::getName(){
	return this->name;
}
int LootBonus::getValue(){
	return this->value;
}