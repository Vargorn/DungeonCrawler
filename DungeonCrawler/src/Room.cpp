#include "Room.h"
#define I(i) (static_cast<size_t>(i -'0'))

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
	for (size_t i = 0; i < static_cast<size_t>(rand() % 4) + 1; i++)
	{
		this->next_rooms.push_back(new Room(this));
	}	
}

Room* Room::getNextRoom() {
	std::cout << "--------------------------" << std::endl;
	std::cout << "Choose your path: " << std::endl;
	std::cout << "--------------------------" << std::endl;
	for (size_t i = 0; i < next_rooms.size(); i++)
	{
		std::cout << i + 1 << std::endl;
	}
	std::cout << "--------------------------" << std::endl;
	char i = 0;
	while ( I(i) > next_rooms.size() || I(i) < 1)
	{
		std::cin >> i;
		std::cout << "--------------------------" << std::endl;
		if (I(i) > next_rooms.size() || I(i) < 0) {
			std::cout << "Wrong Input" << std::endl;
		}
	};
	std::cout << "--------------------------" << std::endl;
	return this->next_rooms[I(i) - 1];
}



