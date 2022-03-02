#include "Maze.h"
Maze::Maze(unsigned int length) {
	this->length = length;
	this->drawPath();
}
Maze::Maze()
{
	this->length = 4;
	this->drawPath();
}
Maze::~Maze() {
	for (auto& i : maze)
	{
		for (auto* j : i)
		{
			delete j;
		}
	}
}
void Maze::link(std::string direction) {
	if (direction == "Left") {
		//this->currentRoom->setValue('<');
		this->currentRoom->setIsVisited(true);
		this->currentRoom->setNextRoom(this->maze[this->currentRoom->getY()][this->currentRoom->getX() - 1], 0);
		this->currentRoom = this->maze[this->currentRoom->getY()][this->currentRoom->getX() - 1];
		this->currentRoom->setPreviousRoom(maze[this->currentRoom->getY()][this->currentRoom->getX() + 1]);
		return;
	}
	if (direction == "Right") {
		//this->currentRoom->setValue('>');
		this->currentRoom->setIsVisited(true);
		this->currentRoom->setNextRoom(this->maze[this->currentRoom->getY()][this->currentRoom->getX() + 1], 1);
		this->currentRoom = maze[this->currentRoom->getY()][this->currentRoom->getX() + 1];
		this->currentRoom->setPreviousRoom(maze[this->currentRoom->getY()][this->currentRoom->getX() - 1]);
		return;
	}
	if (direction == "Up") {
		//this->currentRoom->setValue('^');
		this->currentRoom->setIsVisited(true);
		this->currentRoom->setNextRoom(this->maze[this->currentRoom->getY() - 1][this->currentRoom->getX()], 2);
		this->currentRoom = maze[this->currentRoom->getY() - 1][this->currentRoom->getX()];
		this->currentRoom->setPreviousRoom(maze[this->currentRoom->getY() + 1][this->currentRoom->getX()]);
		return;
	}
	if (direction == "Down") {
		//this->currentRoom->setValue('|');
		this->currentRoom->setIsVisited(true);
		this->currentRoom->setNextRoom(this->maze[this->currentRoom->getY() + 1][this->currentRoom->getX()], 3);
		this->currentRoom = maze[this->currentRoom->getY() + 1][this->currentRoom->getX()];
		this->currentRoom->setPreviousRoom(maze[this->currentRoom->getY() - 1][this->currentRoom->getX()]);
		return;
	}
	if (direction == "Back") {
		//this->currentRoom->setValue('*');
		this->currentRoom->setIsVisited(true);
		this->currentRoom = this->currentRoom->getPreviousRoom();
		return;
	}
}
void Maze::drawPath() {
	for (size_t i = 0; i < this->length; i++)
	{
		std::vector<Room*> row;
		for (size_t j = 0; j < this->length; j++) {
			row.push_back(new Room(j, i));
		}
		maze.push_back(row);
	}
	this->currentRoom = this->maze[0][0];
	for (size_t i = 0; i < this->length * this->length - 1;)
	{
		std::vector<std::string> options = { "Left", "Right", "Up", "Down" };
		if (this->currentRoom->getX() == 0) {
			//left
			options.erase(options.begin());
		}
		else if (maze[this->currentRoom->getY()][this->currentRoom->getX() - 1]->getIsVisited()) {
			//left
			options.erase(options.begin());
		}
		if (this->currentRoom->getX() == this->length - 1) {
			//right
			if (options.size() == 4) {
				options.erase(options.begin() + 1);
			}
			else {
				options.erase(options.begin());
			}
		}
		else if (maze[this->currentRoom->getY()][this->currentRoom->getX() + 1]->getIsVisited()) {
			//right
			if (options.size() == 4) {
				options.erase(options.begin() + 1);
			}
			else {
				options.erase(options.begin());
			}
		}
		if (this->currentRoom->getY() == 0) {
			//up
			if (options.size() == 4) {
				options.erase(options.begin() + 2);
			}
			else if (options.size() == 3) {
				options.erase(options.begin() + 1);
			}
			else {
				options.erase(options.begin());
			}
		}
		else if (maze[this->currentRoom->getY() - 1][this->currentRoom->getX()]->getIsVisited()) {
			//up
			if (options.size() == 4) {
				options.erase(options.begin() + 2);
			}
			else if (options.size() == 3) {
				options.erase(options.begin() + 1);
			}
			else {
				options.erase(options.begin());
			}
		}
		if (this->currentRoom->getY() == this->length - 1) {
			//down
			if (options.size() == 4) {
				options.erase(options.begin() + 3);
			}
			else if (options.size() == 3) {
				options.erase(options.begin() + 2);
			}
			else if (options.size() == 2) {
				options.erase(options.begin() + 1);
			}
			else {
				options.erase(options.begin());
			}
		}
		else if (maze[this->currentRoom->getY() + 1][this->currentRoom->getX()]->getIsVisited()) {
			//down
			if (options.size() == 4) {
				options.erase(options.begin() + 3);
			}
			else if (options.size() == 3) {
				options.erase(options.begin() + 2);
			}
			else if (options.size() == 2) {
				options.erase(options.begin() + 1);
			}
			else {
				options.erase(options.begin());
			}
		}

		if (options.size() == 0) {
			link("Back");
		}
		else
		{
			link(options[rand() % options.size()]);
			++i;
		}
	}
	this->currentRoom->setIsExit();
	this->currentRoom = this->maze[0][0];
}
void Maze::drawMap() {
	for (size_t i = 0; i < this->length; i++)
	{
		for (size_t j = 0; j < this->length; j++) {
			std::cout << this->maze[i][j]->getValue() << " ";
		}
		std::cout << std::endl;
	}
}
void Maze::move() {
	this->currentRoom->setValue('x');
	this->currentRoom->showPaths();
	this->drawMap();
	std::cout << "--------------------------" << std::endl;
	this->currentRoom = this->currentRoom->next();
}
unsigned int Maze::getCurrentEncounter() {
	return this->currentRoom->getEncounter();
}

bool Maze::isExit()
{
	return this->currentRoom->getIsExit();
}
