#include"pch.h"
#include "Room.h"

Room::Room(int x, int y) {
	this->x = x;
	this->y = y;
	this->encounter = rand() % 100 + 1;
	this->value = '#';
	this->isVisited = false;
	this->isExit = false;
	this->previousRoom = nullptr;
	this->nextRooms.fill(nullptr);
}
Room::~Room() {

}
int Room::getX() {
	return this->x;
}
int Room::getY() {
	return this->y;
}
unsigned int Room::getEncounter() {
	return this->encounter;
}
char Room::getValue() {
	return this->value;
}
void Room::setValue(char value) {
	this->value = value;
}
bool Room::getIsVisited() {
	return this->isVisited;
}
void Room::setIsVisited(bool isVisited) {
	this->isVisited = isVisited;
}
bool Room::getIsExit() {
	return this->isExit;
}
void Room::setIsExit() {
	this->isExit = true;
}
Room*Room::getPreviousRoom() {
	return this->previousRoom;
}
void Room::setPreviousRoom(Room* room) {
	this->previousRoom = room;
}
void Room::setNextRoom(Room* room, unsigned int position) {
	this->nextRooms[position] = room;
}
void Room::showPaths() {
	for (size_t i = 0; i < this->nextRooms.size(); i++)
	{
		if (this->nextRooms[i] != nullptr && this->nextRooms[i]->getValue() == '#') {
			this->nextRooms[i]->setValue('?');
		}
	}
}
Room* Room::next() {
	std::cout << "Coose direction: \nl - left \nr - right \nu - up \nd - down \nb - back" << std::endl;
	std::cout << "--------------------------" << std::endl;
	char a;
	std::cin >> a;
	std::cout << "--------------------------" << std::endl;
	if (a == 'l' && this->nextRooms[0] != nullptr) {
		this->value = '<';
		this->encounter = 80;
		return this->nextRooms[0];
	}
	else if (a == 'r' && this->nextRooms[1] != nullptr) {
		this->value = '>';
		this->encounter = 80;
		return this->nextRooms[1];
	}
	else if (a == 'u' && this->nextRooms[2] != nullptr) {
		this->value = '^';
		this->encounter = 80;
		return this->nextRooms[2];
	}
	else if (a == 'd' && this->nextRooms[3] != nullptr) {
		this->value = '|';
		this->encounter = 80;
		return this->nextRooms[3];
	}
	else if (a == 'b' && this->previousRoom != nullptr) {
		this->value = '*';
		this->encounter = 80;

		return this->previousRoom;
	}
	else {
		std::cout << "Wrong Input!" << std::endl;
		std::cout << "--------------------------" << std::endl;
		this->next();
	}
}