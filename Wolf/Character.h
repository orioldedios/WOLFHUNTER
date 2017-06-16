#ifndef _CHARACTER_H_
#define _CHARACTER_H_

#include <time.h>
#include <stdlib.h>

enum NAMES {
	DEFAULT_NAME,
	TOM,
	MAX,
	ALICE,
	JOHN,
	TED,
	SAM,
	SOPHIE,
	ADAM,
	MIA,
	ANNIE,
	MARIA,
	TERESA,
	SARAH,
	FERNANDO,
	CARLOS,
	MAX_NAMES
};

enum ROL
{
	DEFAULT_ROL,
	VILLAGER,
	WOLF,
	DEVINER,
	GIRL,
	HUNTER,
	MAX_ROLE
};




class  Character
{
public:
	bool alive = true;
	char* name = "DEFAULT NAME";
	int numplayer;
	enum ROL rol;
	bool characterdiscoveredbydeviner = false;

	 Character();
	~ Character();
	bool isAlive();
	char* getName();
	int getNumPlayer();
	enum ROL getRol();

};

int getRandome(int maxrandome) {
	return (rand() % maxrandome) + 1;//meter semilla en main
}



#endif // !_CHARACTER_H


