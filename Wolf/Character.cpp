#include "Character.h"

Character::Character(){}

Character::~Character(){}

bool Character::isAlive() {
	if (alive)
	{
		return true;
	}
	else {
		return false;
	}
}

char* Character::getName() { return name; }
int Character::getNumPlayer() { return numplayer; }
enum ROL Character::getRol() { return rol; }
