#include "Game.h"
#include "Character.h"

using namespace std;

#include <iostream>

//COMPARA DOS STRINGS
bool comparethisstrings(char* s1, char* s2) {
	return strcmp(s1, s2) == 0;
}

//RETORNA NOMBRES ALEATORIOS A LOS BOTS
char* setNameBot() {
	bool ithasappeared;
	int numrand;
	do{
		ithasappeared = false;
		numrand = getRandome(MAX_NAMES - 1);
		for (int i = 1; i < MAX_NAMES; i++)
		{
			if (namesputted[i] == numrand) {
				ithasappeared = true;
			}
		}
	} while (ithasappeared);
	switch (numrand)
	{
	case 1:
		namesputted[counterarraynames] = 1;
		counterarraynames++;
		return "TOM";
		break;
	case 2:
		namesputted[counterarraynames] = 2;
		counterarraynames++;
		return "MAX";
		break;
	case 3:
		namesputted[counterarraynames] = 3;
		counterarraynames++;
		return "ALICE";
		break;
	case 4:
		namesputted[counterarraynames] = 4;
		counterarraynames++;
		return "JOHN";
		break;
	case 5:
		namesputted[counterarraynames] = 5;
		counterarraynames++;
		return "TED";
		break;
	case 6:
		namesputted[counterarraynames] = 6;
		counterarraynames++;
		return "SAM";
		break;
	case 7:
		namesputted[counterarraynames] = 7;
		counterarraynames++;
		return "SOPHIE";
		break;
	case 8:
		namesputted[counterarraynames] = 8;
		counterarraynames++;
		return "ADAM";
		break;
	case 9:
		namesputted[counterarraynames] = 9;
		counterarraynames++;
		return "MIA";
		break;
	case 10:
		namesputted[counterarraynames] = 10;
		counterarraynames++;
		return "ANNIE";
		break;
	case 11:
		namesputted[counterarraynames] = 11;
		counterarraynames++;
		return "MARIA";
		break;
	case 12:
		namesputted[counterarraynames] = 12;
		counterarraynames++;
		return "TERESA";
		break;
	case 13:
		namesputted[counterarraynames] = 13;
		counterarraynames++;
		return "SARAH";
		break;
	case 14:
		namesputted[counterarraynames] = 14;
		counterarraynames++;
		return "FERNANDO";
		break;
	case 15:
		namesputted[counterarraynames] = 15;
		counterarraynames++;
		return "CARLOS";
		break;
	default:
		break;
	}
}
//INDICA MAXIMO DE PLAYERS
void tellNumPlayers(){
	do {
		cout << "How many players do you want? ";
		cin >> numplayers;
		CLEAR;
		if (numplayers > 15) {
			cout << "Sorry, 15 are max players" << endl;
			STOP;
			CLEAR;
		}
		else if (numplayers < 5) {
			cout << "Sorry, 5 are min players" << endl;
			STOP;
			CLEAR;
		}
	} while (numplayers > 15|| numplayers < 5);
}
//CUENTA LA CANTIDAD DE CADA TIPO DE ROL QUE HAY PARA ASIGNARLOS BIEN
void countRoles() {
	for (int i = 0; i < numplayers; i++)
	{
		if (player[i].rol == VILLAGER) {
			counters[villagercounter] += 1;
		}
		else if (player[i].rol == WOLF) {
			counters[wolfcounter] += 1;
		}
		else if (player[i].rol == DEVINER) {
			counters[devinercounter] += 1;
		}
		else if (player[i].rol == GIRL) {
			counters[girlcounter] += 1;
		}
		else if (player[i].rol == HUNTER) {
			counters[huntercounter] += 1;
		}
	}
}
//RESETEA LOS CONTADORES DE ROLES
void resetCounters() { //AL TANTO QUE ESTO LO USARAS ALGUN DIA
	for (int i = 0; i < MAX_COUNTERS; i++)
	{
		counters[i] = 0;
	}
}
//RETORNA UN ROL DISTINTO A CADA PERSONAJE SIN PASARSE
enum ROL putarol(){
	countRoles();
	switch (getRandome(3))
	{

	case 1://WOLF
		if (counters[wolfcounter] <= (numplayers / 3)) {
			return WOLF;
		}
		else if (counters[devinercounter] == 0) {
			return DEVINER;
		}
		else if (counters[girlcounter] == 0) {
			return GIRL;
		}
		else if (counters[huntercounter] == 0) {
			return HUNTER;
		}
		else {
			return VILLAGER;
		}
		break;

	case 2://SPECIAL
		if (counters[devinercounter] == 0) {
			return DEVINER;
		}
		else if (counters[girlcounter] == 0) {
			return GIRL;
		}
		else if (counters[huntercounter] == 0) {
			return HUNTER;
		}
		else if (counters[wolfcounter] <= (numplayers / 3)) {
			return WOLF;
		}
		else {
			return VILLAGER;
		}
		break;

	case 3://VILLAGER
		if (counters[villagercounter] <= ((numplayers / 4) * 3)) {
			return VILLAGER;
		}else if (counters[wolfcounter] <= (numplayers / 3)) {
			return WOLF;
		}
		else if (counters[devinercounter] == 0) {
			return DEVINER;
		}
		else if (counters[girlcounter] == 0) {
			return GIRL;
		}
		else if (counters[huntercounter] == 0) {
			return HUNTER;
		}
		else {
			return VILLAGER;
		}
		break;
	default:
		break;
	}
	resetCounters();
}
//ASIGNA UN ROL A CADA PERSONAJE, UN NOMBRE, UN NUMERO Y SI ESTÁ VIVO
void assignRoles() {
	for (int i = 0; i < numplayers; i++)
	{
		player[i].rol = DEFAULT_ROL;
		player[i].name = "DEFAULT_NAME";
	}
	for (int i = 0; i < numplayers; i++)
	{
		player[i].name = setNameBot();
		player[i].alive = true;
		player[i].numplayer = i;
		player[i].rol = putarol();
	}
}
//TE ASSIGNAN TU NOMBRE AL PLAYER 0
void yournameis() {
	cout << "WHAT'S YOUR NAME? ";
	cin >> yourname;
	player[0].name = yourname;
	CLEAR;
}
//RESETEA TODO PARA QUE SE PUEDA VOLVER A JUGAR
void resetAll(){
	resetCounters();
	delete[] yourname;
}
//IMPRIME EL ROL PARA COMPROVACIONES MÁS CLARAS
void printRol(ROL rol) {
	switch (rol)
	{
	case 1:
		cout << "VILLAGER";
		break;
	case 2:
		cout << "WOLF";
		break;
	case 3:
		cout << "DEVINER";
		break;
	case 4:
		cout << "GIRL";
		break;
	case 5:
		cout << "HUNTER";
		break;
	default:
		cout << "THIS ROL DOESN'T EIST YET";
		break;
	}
}

//FUNCIÓN DE NIÑA (BOT)
void girlbot(){
	if (getRandome(3) == 3) {
		wolfseen = true;
	}
	if (wolfseen && !girlbusted && getRandome(6) == 6) {
		girlbusted = true;
	}
}
//FUNCIÓN DE NIÑA(PLAYER)
void girlPlayer() {
	char* answer = new char[30];
	bool cancontinue = false;
	do {
		//PREGUNTAS SI QUIERE ESPIAR
		cout << "\nDo you want to spy the wolfs? you can be catched... ";
		cin >> answer;
		CLEAR;
		//SI DICE QUE SI
		if (comparethisstrings(answer, "yes") || comparethisstrings(answer, "YES") || comparethisstrings(answer, "Y") || comparethisstrings(answer, "y") || comparethisstrings(answer, "OK") || comparethisstrings(answer, "ok")) {
			wolfseen = true;
			cout << "YOU HAVE SEEN THE WOLFS!\n\nTHEY ARE:" << endl;
			for (int i = 0; i < numplayers; i++)
			{
				if (player[i].rol == WOLF) {
					cout << player[i].name << endl;
				}
			}
			//SI LOS LOBOS TE PILLAN
			if (getRandome(4) == 2) {
				cout << "BUT THEY BUSTED YOU!" << endl;
				girlbusted = true;
			}
			if (!girlbusted)
			{
				cout << "AND THEY DIDN'T BUSTED YOU" << endl;
			}
			cancontinue = true;
			STOP;
			CLEAR;
		}
		//SI DICE QUE NO
		if (comparethisstrings(answer, "no") || comparethisstrings(answer, "NO") || comparethisstrings(answer, "N") || comparethisstrings(answer, "n") || comparethisstrings(answer, "NOPE") || comparethisstrings(answer, "nope")) {
			cout << "OK, NO PROBLEM" << endl;
			cancontinue = true;
			STOP;
			CLEAR;
		}
		if (!cancontinue) {
			cout << "PLEASE, GIVE ME AN UNINVENTED WORD\n";
			STOP;
			CLEAR;
		}
	} while (!cancontinue);
	delete[] answer;
}
//FUNCION DE NIÑA COMPLETA
void girl(){
	//ITERACIÓN HASTA LA NIÑA
	int rolIterator = 0;
	while (player[rolIterator].rol != GIRL)
	{
		rolIterator++;
	}
	//SI LA NIÑA ES UN BOT...
	if (player[rolIterator].numplayer != 0)
	{
		girlbot();
	}
	//SI LA NIÑA ES EL PLAYER...
	if (player[rolIterator].numplayer == 0)
	{
		girlPlayer();
	}
}


//FUNCIÓN DE PITONISA (BOT)
void devinerbot(){
	bool cancontinue=false;
	while (!cancontinue){
		int randnumplayer = getRandome(numplayers)-1;
		if (!player[randnumplayer].characterdiscoveredbydeviner) {
			player[randnumplayer].characterdiscoveredbydeviner = true;
			cancontinue = true;
		}
	}
}
//FUNCIÓN DE PITONISA (PLAYER)
void devinerplayer(){
	char* mantodiscover = new char[10];
	bool cancontinue = false;
	do {
		cout << "WHAT PLAYER DO YOU WANT TO DISCOVER?\n\n";
		for (int i = 1; i < numplayers; i++)
		{
			if (!player[i].characterdiscoveredbydeviner) {
				cout << player[i].name << "\t";
			}
		}
		cout << "\nREMEMBER WHRITE WHITH MAJUS ACTIVATED ";
		cin >> mantodiscover;
		CLEAR;

		for (int i = 1; i < numplayers; i++)
		{
			if (comparethisstrings(mantodiscover, player[i].name)) {
				cancontinue = true;
				cout << player[i].name << " IS A ";
				printRol(player[i].rol);
				cout << " !\n";
				STOP;
				CLEAR;
			}
		}
		if (!cancontinue)
		{
			cout << "MMM... THIS NAME DOESN'T SOUND FAMILIAR TO ME... TRY AGAIN" << endl;
			STOP;
			CLEAR;
		}
	} while (!cancontinue);

}
//FUNCION DE PITONISA COMPLETA
void deviner() {
	//ITERACIÓN HASTA LA PITONISA
	int rolIterator = 0;
	while (player[rolIterator].rol != DEVINER)
	{
		rolIterator++;
	}
	//SI LA NIÑA ES UN BOT...
	if (player[rolIterator].numplayer != 0)
	{
		devinerbot();
	}
	//SI LA NIÑA ES EL PLAYER...
	if (player[rolIterator].numplayer == 0)
	{
		devinerplayer();
	}
}



//FUNCIÓN DE NOCHE (NIÑA Y PITONISA BOTS Y PLAYER)
void night(){
	//COMPROVACIÓN DE SI HAY ADIVINA
	for (int i = 0; i < numplayers; i++)
	{
		if (player[i].rol == DEVINER) {
			deviner();
		}
	}

	//COMPROVACIÓN DE SI HAY ADIVINA
	for (int i = 0; i < numplayers; i++)
	{
		if (player[i].rol == GIRL) {
			girl();
		}
	}
	

}

//SE JUEGA
void play() {

	srand(time(NULL));

	tellNumPlayers();
	assignRoles();

	//COMPROVACION ROL
	//player[0].rol = GIRL;


	yournameis();

	//COMPROVACIÓN DE ROLES ALEATORIOS
	for (int i = 0; i < numplayers; i++)
	{
		cout << player[i].name << ":";
		printRol(player[i].rol);
		cout << "\n";
	}


	cout << "YOUR ROL IS: ";
	printRol(player[0].rol);
	cout << "\n";
	STOP;
	CLEAR;

	//TU ERES EL PLAYER 0


	night();

	resetAll();//AL FINAL DE TODO RESETEAS TODO PA QUE NO DE ERROR Y PUEDAS VOLVER A JUGAR
}
