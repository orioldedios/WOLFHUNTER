#ifndef _GAME_H_
#define _GAME_H_

#include "Character.h"

#define MAX_PLAYERS 15
#define CLEAR system("cls");
#define STOP system("pause");

int numplayers;
bool wolfseen = false;
bool girlbusted = false;
Character player[MAX_PLAYERS];
int namesputted[MAX_NAMES];
int counterarraynames = 0;

char* yourname = new char[100];


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

//FUNCIONES PREVIAS
char* setNameBot();
void tellNumPlayers();
void countRoles();
void resetCounters();
void yournameis();
enum ROL putarol();
void assignRoles();
void resetAll();
void printRol(ROL rol);
bool comparethisstrings(char* si, char* s2);

//FUNCIONES DE NOCHE
void girl();
void girlbot();
void girlPlayer();
void deviner();
void devinerbot();
void devinerplayer();
void night();


#endif // !_GAME_H_

