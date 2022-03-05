#include"pch.h"
#include "Game.h"

Game::Game() {
	this->initMonsterNames();
	this->maze = new Maze(rand() % 4 + 3);
}
Game::~Game()
{
	delete maze;
}

void Game::initMonsterNames() {
	this->monsterNames = {"Goblin", "Ogre", "Orc", "Troll", "Banshee", "Chimera", "Vampire", "Shoggoth", "Fishman", "Centaur", "Cerberus", "Harpy" };
	this->monsterNicknames = { "Sneeky", "Crazy", "Big", "Fat", "Annoying", "Terrifying", "Smart", "Drunk", "Stinky", "Sticky", "Lame", "Cocky" };
	this->monsterClasses = {"Skirmisher", "Mage", "Ambusher", "Reaper", "Leader", "Dispoiler", "Arsonist", "Lunatic", "Nightlord"};
	this->bossNames = {"Yogsothoth", "Dagon", "Nyarlathotep", "Cthulhu", "Alduin", "Nazgul", "Griffith" };
}
std::string Game::getRandomName(bool isBoss) {
	if (isBoss == false) {
		return std::format(
			this->monsterNicknames[rand() % this->monsterNicknames.size()] + " " +
			this->monsterNames[rand() % this->monsterNames.size()] + " " +
			this->monsterClasses[rand() % this->monsterClasses.size()]
		);
	}
	return std::format(
		this->monsterNicknames[rand() % this->monsterNicknames.size()] + " " +
		this->bossNames[rand() % this->bossNames.size()]
	);
	// isBoss == true ? std::cout << "Boss" : std::cout << "Monster"
 }
void Game::battle() {
	std::cout << "You have encoutered an enemy" << std::endl;
	std::cout << "--------------------------" << std::endl;
	this->enemy = Enemy(getRandomName(false), this->player.getLevel());
	char a;
	while (this->player.getHp() > 0 && this->enemy.getHp() > 0) {

		std::cout << "Make your move, faster " << std::endl;
		std::cout << "1 - Attack " << std::endl;
		std::cout << "2 - Wait " << std::endl;
		std::cout << "3 - Cast spell " << std::endl;
		std::cout << "4 - Use consumamble " << std::endl;
		std::cout << "5 - Show stats " << std::endl;
		std::cout << "--------------------------" << std::endl;
		std::cin >> a;
		std::cout << "--------------------------" << std::endl;
		switch (a)
		{
			case '1': {
				this->player.attack(this->enemy);
				break;
			}
			case '2': {
				this->player.wait();
				std::cout << "Player waits" << std::endl;
				std::cout << "--------------------------" << std::endl;
				break;
			}
			case '3': {
				std::cout << "There Is No Magic In This World Yet... " << std::endl;
				std::cout << "--------------------------" << std::endl;
				continue;
			}
			case '4': {
				std::cout << "Well Consumambles Are Not Yet Ready" << std::endl;
				std::cout << "--------------------------" << std::endl;
				continue;
				}
			case '5': {
				this->player.showStats();
				this->enemy.showStats();
				continue;
			}
			default: {
				std::cout << "Wrong input" << std::endl;
				std::cout << "--------------------------" << std::endl;
				continue;
			}
		}
		this->enemy.takeAction(this->player);
	}
	if (this->enemy.getHp()<= 0) {
		this->player.setXp(this->player.getXp() + this->enemy.getXp());
		std::cout << "Enemy Killed!" << std::endl;
		std::cout << "You've recieved " << this->enemy.getXp() << " experience" << std::endl;
		std::cout << "--------------------------" << std::endl;
		if (rand() % 100 + 1 <= 9 + this->player.getLuck() / 5) {
			this->player.reciveLoot(this->enemy.getLevel());
		}
		if (this->player.getXp() >= this->player.getXpTillNextLvl()) {
			this->player.levelUp();
		}
	}
}
void Game::next() {
	this->maze->move();
	if (this->maze->getCurrentEncounter() > 0 && this->maze->getCurrentEncounter() <= 50) {
		this->battle();
		if (this->player.getHp() <= 0) {
			return;
		}
	}
	if (this->maze->getCurrentEncounter() > 50 && this->maze->getCurrentEncounter() <= 55) {
		//NPC_ENCOUNTER
		std::cout << "Sorry NPSs are yet to be done OTL" << std::endl;
		std::cout << "--------------------------" << std::endl;
	}
	if (this->maze->getCurrentEncounter() > 55 && this->maze->getCurrentEncounter() <= 80) {
		std::cout << "This room is completely empty" << std::endl;
		std::cout << "--------------------------" << std::endl;
	}
	if (this->maze->getCurrentEncounter() > 80 && this->maze->getCurrentEncounter() <= 90) {
		this->trap = Trap(this->player);
		std::cout << "--------------------------" << std::endl;
	}
	if (this->maze->getCurrentEncounter() > 90 && this->maze->getCurrentEncounter() <= 100) {
		this->player.reciveLoot(1);
		std::cout << "--------------------------" << std::endl;
		//std::cout << "Loot is not implemented yet (^w^)" << std::endl;
		//treasure
	}
	if (this->maze->isExit()) {
		char choise;
		std::cout << "You found a ladder leading to the next floor. Do you want to go upstairs?\ny - yes\nn - no"<< std::endl;
		std::cout << "--------------------------" << std::endl;
		while (true)
		{
			std::cin >> choise;
			if (choise == 'y') {
				this->maze = new Maze(rand() % 4 + 3);
				std::cout << "--------------------------" << std::endl;
				return;
			}
			else if (choise == 'n') {
				std::cout << "--------------------------" << std::endl;
				return;
			}
			else {
				std::cout << "Wrong Input" << std::endl;
				std::cout << "--------------------------" << std::endl;
				continue;
			}
		}
		
	}
}
int Game::getPlayerHp() {
	return this->player.getHp();
}
void Game::inventory()
{
	this->player.openInventory();
}
void Game::stats()
{
	this->player.showStats();
}
