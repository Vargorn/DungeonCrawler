#pragma once
#include "Enemy.h"
#include <iostream>
#include <vector>
#include <array>

class Room
{
private:
	int x;
	int y;
	unsigned int encounter;
	char value;
	bool isVisited;
	bool isExit;
	Room* previousRoom;
	std::array<Room*, 4> nextRooms;
public:
	Room(int x, int y);
	~Room();
	int getX();
	int getY();
	unsigned int getEncounter();
	char getValue();
	void setValue(char value);
	bool getIsVisited();
	void setIsVisited(bool isVisited);
	bool getIsExit();
	void setIsExit();
	Room* getPreviousRoom();
	void setPreviousRoom(Room* room);
	void setNextRoom(Room* room, unsigned int position);
	void showPaths();
	Room* next();
};


