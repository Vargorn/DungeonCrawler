#include "Game.h"
#include<format>
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

}

void Game::next() {
	this->room.addRooms();
	this->room = this->room.getNextRoom();
	switch (this->room.getEncounter()) {
	case EVENTS::EMPTY_ROOM: {

		break;
	}
	case EVENTS::MONSTER_ENCOUNTER: {
		this->enemy = Enemy(getRandomName(false), 1);
		break;
	}
	case EVENTS::NPC_ENCOUNTER: {

		break;
	}
	case EVENTS::TRAP: {

		break;
	}
	case EVENTS::TREASURE: {

		break;
	}
	}
}

