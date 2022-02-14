#include "Room.h"
Room::Room(Room* previousRoom) {
	this->previousRoom = previousRoom;
	this->encounter = 1;
}

Room::Room()
{
}

unsigned int Room::getEncounter() {
	return this->encounter;
}

void Room::addRooms()
{
	this->next_rooms.push_back(new Room(this));
	std::cout << this->next_rooms[0]->getEncounter();
}




