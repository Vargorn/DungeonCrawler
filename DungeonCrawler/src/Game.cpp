#include "Game.h"
Game::Game() {
	this->room = Room(nullptr);
	this->initMonsterNames();

	//this->enemy = Enemy(getRandomName(false), 1);
}
Game::~Game()
{
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
	this->enemy = Enemy(getRandomName(false), this->player.getLevel());
	char a;
	while (this->player.getHp() > 0 && this->enemy.getHp() > 0) {

		std::cout << "--------------------------" << std::endl;
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
				break;
			}
			case '4': {
				break;
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
		std::cout << "You've recieved " << this->enemy.getXp() << " experience" << std::endl;
		if (rand() % 100 + 1 <= 10) {
			this->player.reciveLoot(this->enemy.getLevel());
		}
		if (this->player.getXp() >= this->player.getXpTillNextLvl()) {
			this->player.levelUp();
		}
	}
}
void Game::next() {
	this->room.addRooms();
	this->room = this->room.getNextRoom();
	if (this->room.getEncounter() > 0 && this->room.getEncounter() <= 50) {
		this->battle();
	}
	if (this->room.getEncounter() > 50 && this->room.getEncounter() <= 55) {
		//NPC_ENCOUNTER
		std::cout << "Sorry NPSs are yet to be done OTL" << std::endl;
	}
	if (this->room.getEncounter() > 55 && this->room.getEncounter() <= 80) {
		std::cout << "EMPTY ROOM" << std::endl;
	}
	if (this->room.getEncounter() > 80 && this->room.getEncounter() <= 90) {
		this->trap = Trap(this->player);
	}
	if (this->room.getEncounter() > 90 && this->room.getEncounter() <= 100) {
		std::cout << "Loot is not implemented yet (^w^)" << std::endl;
		//treasure
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
