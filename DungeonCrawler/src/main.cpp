#include<iostream>
#include"Game.h"
#include"Player.h"
#include <stdlib.h>
#include <array>


//enemy stats dependent from name
//vector w/ rooms + add monster randomizer and boss randomizer
// backpack
//items
//equipment
//loot


int main() {
	srand(static_cast<unsigned int>(time(0)));
	auto game = Game();
	char a;
	while (game.getPlayerHp() > 0)
	{
		std::cout << "Choose your action: " << std::endl;
		std::cout << "n - next room \n" << "i - inventory \n";
		std::cin >> a;
		switch (a)
		{
			case 'n': {
				game.next();
				break;
			}
			case 'i': {
				game.inventory();
				break;
			}
			default : {
				std::cout << "Wrong Input" << std::endl;
			}
		}
	}
	std::cout << "Game Over" << std::endl;
}