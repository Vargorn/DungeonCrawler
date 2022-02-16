#include<iostream>
#include"Game.h"
#include"Player.h"
#include <stdlib.h>


//enemy stats dependent from name
//vector w/ rooms + add monster randomizer and boss randomizer
// backpack
//items
//equipment
//loot


int main() {
	srand(static_cast<unsigned int>(time(0)));
	auto game = Game();
	while (true)
	{
		game.next();
	}
}