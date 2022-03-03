#pragma once
#include "Player.h"
#include "Trap.h"
#include "Enemy.h"
#include "Maze.h"

class Game
{
private:
	Player player;
	Enemy enemy;
	Maze* maze;
	Trap trap;
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
	void battle();
	void next();
	int getPlayerHp();
	void inventory();
	void stats();
};

