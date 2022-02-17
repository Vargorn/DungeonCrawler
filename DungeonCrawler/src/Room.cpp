#include "Room.h"

Room::Room(Room* previousRoom) {
	this->previousRoom = previousRoom;
	this->encounter = rand() % 100 + 1;
	
}

Room::Room()
{
}

unsigned int Room::getEncounter() {
	return this->encounter;
}

void Room::addRooms()
{
	for (size_t i = 0; i < static_cast<unsigned int>(rand() % 4 + 1); i++)
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
	unsigned int i = 0;
	while (i > next_rooms.size() || i < 1)
	{
		std::cin >> i;
		if (i >= next_rooms.size() || i < 0) {
			std::cout << "WrOnG iNpUt " << std::endl;
		}
		//todo typecheck
	};
	std::cout << "--------------------------" << std::endl;
	return this->next_rooms[i - 1];
}



