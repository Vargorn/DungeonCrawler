#include "Enemy.h"


Enemy::Enemy(std::string name, const int& playerLvl) {
	unsigned int first = name.find_first_of(' ');
	unsigned int last = name.find_last_of(' ');
	this->monster_nickName = name.substr(0, first);
	this->monster_name = name.substr(first + 1, last - first - 1);
	this->monster_class = name.substr(last + 1, name.size() - 1);
}

Enemy::Enemy()
{
}
