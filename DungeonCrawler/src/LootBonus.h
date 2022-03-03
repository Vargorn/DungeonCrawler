#pragma once

class LootBonus
{
private:
	std::string name;
	int value;
public:
	LootBonus(std::string name, int value);
	std::string getName();
	int getValue();
};

