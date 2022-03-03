#pragma once
#include "Enums.h"
#include "Player.h"

class Trap
{
private:
	int type;

public:
	Trap(Player& player);
	Trap();
};

