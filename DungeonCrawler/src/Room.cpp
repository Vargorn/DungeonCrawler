#include "Room.h"

Room::Room(Room* previousRoom) {
	this->previousRoom = previousRoom;
	this->encounter = rand() % 5;
	
}

Room::Room()
{
}

unsigned int Room::getEncounter() {
	return this->encounter;
}

void Room::addRooms()
{
	for (size_t i = 0; i < rand() % 4 + 1; i++)
	{
		this->next_rooms.push_back(new Room(this));
	}	
}

Room* Room::getNextRoom() {
	std::cout << "Choose your path: " << std::endl;
	std::cout << "--------------------------" << std::endl;
	for (size_t i = 0; i < next_rooms.size(); i++)
	{
		std::cout << i << std::endl;
	}
	std::cout << "--------------------------" << std::endl;
	int i = -1;
	while (i >= next_rooms.size() || i < 0)
	{
		std::cin >> i;
		if (i >= next_rooms.size() || i < 0) {
			std::cout << "WrOnG iNpUt " << std::endl;
		}
		//todo typecheck
	};
	std::cout << "--------------------------" << std::endl;
	return this->next_rooms[i];
}



