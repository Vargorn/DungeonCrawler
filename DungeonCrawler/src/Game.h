#pragma once
#include "Player.h"
#include "Enemy.h"
#include "Room.h"
#include <vector>
class Game
{
private:
	//Player player;
	//Enemy enemy;
	Room room;
	std::string name;
	std::vector<std::string> monsterNames;
	std::vector<std::string> monsterNicknames;
	std::vector<std::string> bossNames;
	std::vector<std::string> monsterClasses;
public:
	Game();
	~Game();
	void initMonsterNames();
	std::string getRandomName(bool isBoss);
};

