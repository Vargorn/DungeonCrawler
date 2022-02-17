#pragma once
#include "Enemy.h"
#include <iostream>
#include <vector>

class Room
{
private:
	Room* previousRoom {};
	std::vector<Room*> next_rooms {};
	unsigned int encounter {};

public:
	Room(Room* previousRoom);
	Room();
	unsigned int getEncounter();
	void addRooms();

	Room* getNextRoom();
};


