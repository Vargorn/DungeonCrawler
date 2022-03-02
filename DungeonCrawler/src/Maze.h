#pragma once
#include<iostream>
#include <iostream>
#include <vector>
#include <array>
#include "Room.h"
class Maze
{
private:
	unsigned int length;
	std::vector<std::vector<Room*>> maze;
	Room* currentRoom;
public:
	Maze(unsigned int length);
	Maze();
	~Maze();
	void link(std::string direction);
	void drawPath();
	void drawMap();
	void move();
	unsigned int getCurrentEncounter();
	bool isExit();
};