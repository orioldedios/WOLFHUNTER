#ifndef _GAME_H_
#define _GAME_H_

#include "Character.h"

int numplayers;
Character player[15];

enum COUNTERS {
	villagercounter,
	wolfcounter,
	devinercounter,
	girlcounter,
	huntercounter,
	MAX_COUNTERS
};

int counters[MAX_COUNTERS];

void play();

enum ROL putarol();
void tellNumPlayers();
void assignRoles();
void countRoles();

#endif // !_GAME_H_

