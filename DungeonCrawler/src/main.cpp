#include<iostream>
#include"Game.h"
#include"Player.h"
#include <stdlib.h>
#include <array>


//TODO
//Magic, Traps, Bosses, Loot, NPC, Treasure, Balance


int main() {
	srand(static_cast<unsigned int>(time(0)));
	auto game = Game();
	char a;
	while (game.getPlayerHp() > 0)
	{
		std::cout << "--------------------------" << std::endl;
		std::cout << "Choose your action: " << std::endl;
		std::cout << "n - next room \n" << "i - inventory \n" << "s - stats \n";
		std::cout << "--------------------------" << std::endl;
		std::cin >> a;
		std::cout << "--------------------------" << std::endl;
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
			case 's': {
				game.stats();
				break;
			}
			default : {
				std::cout << "Wrong Input" << std::endl;
				break;
			}
		}
	}
	std::cout << "Game Over" << std::endl;
}