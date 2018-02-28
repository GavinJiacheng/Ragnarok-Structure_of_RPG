<<<<<<< HEAD

#ifndef SYSTEM_H
#define SYSTEM_H

#include <iostream>
#include <string>
#include <stdio.h>
#include "../battle/battle.cpp"
#include "../List/Linkedlist.h"


using std::string;

class SYSTEM
{
private:
	string location;
	Player *pler;
	//Creature list;


public:
	SYSTEM();
	SYSTEM(Player *pl);
	//void UI();
	void menu();
	void selectmaps();
	void personalmenu();
};

=======

#ifndef SYSTEM_H
#define SYSTEM_H

#include <iostream>
#include <string>
#include <stdio.h>
#include "../battle/battle.cpp"


using std::string;

class SYSTEM
{
private:
	string location;
	Player *pler;
	//Creature list;


public:
	SYSTEM();
	SYSTEM(Player *pl);
	//void UI();
	void menu();
	void selectmaps();
	void personalmenu();
};

>>>>>>> a55dd91f28694f95712daacba48be33daa0b3276
#endif