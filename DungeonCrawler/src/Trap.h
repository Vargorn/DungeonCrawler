#pragma once
#include <iostream>
#include "Enums.h"
#include "Player.h"

class Trap
{
private:
	std::string name;
	int type;

public:
	Trap(Player& player);
};

