
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

#endif