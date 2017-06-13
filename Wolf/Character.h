#ifndef _CHARACTER_H_
#define _CHARACTER_H_

#include <time.h>
#include <stdlib.h>


enum ROL
{
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
	char* name = "Player";
	int numplayer;
	enum ROL rol;
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


