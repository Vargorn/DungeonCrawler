#pragma once
#include <iostream>
#include <vector>
#include "Enums.h"
#include "LootBonus.h"

class Loot
{
private:
	std::string name;
	std::string material;
	int slot;
	std::vector<LootBonus> bonuses;

	std::vector<std::string> materials;
	std::vector<std::string> helms;
	std::vector<std::string> weapons;
	std::vector<std::string> shoulders;
	std::vector<std::string> gloves;
	std::vector<std::string> armor;
	std::vector<std::string> rings;
	std::vector<std::string> boots;
	std::vector<std::string> trousers;
public:
	Loot();
	Loot(int slot);
	void initItem();
	void getInfo();
	int getSlot();
	std::vector<LootBonus> getBonuses();
};