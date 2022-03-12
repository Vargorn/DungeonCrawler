#include"pch.h"
#include"Game.h"


//TODO
//Magic, Traps, Loot, NPC, Treasure, Balance
//Boss in the end of the Maze 


int main() {
	srand(static_cast<unsigned int>(time(0)));
	auto game = Game();
	char a;
	while (game.getPlayerHp() > 0)
	{
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
				std::cout << "Wrong Input!" << std::endl;
				std::cout << "--------------------------" << std::endl;
				break;
			}
		}
	}
	std::cout << "You Died!" << std::endl;
	std::cout << "--------------------------" << std::endl;
	std::cout << "Game Over" << std::endl;
}