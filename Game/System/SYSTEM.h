
#ifndef SYSTEM_H
#define SYSTEM_H

#include <iostream>
#include <string>
#include <stdio.h>
#include "../battle/battle.h"
#include "../List/Linkedlist.h"


using std::string;

class SYSTEM
{
private:
	bool domenu;
	string location;
	Player *pler;
	linkedlist<Creature> * ALFHEIM;
	linkedlist<Creature> * SVAR;
	linkedlist<Creature> * MIDGARD;
	linkedlist<Creature> * MUSP;
	linkedlist<Creature> * HEEL;

public:
	SYSTEM();
	//~SYSTEM();
	SYSTEM(Player *pl);
	void printall(linkedlist<Creature>* list);
	void reset();
	void sleep();
	//void UI();
	void menu();
	void attackenemies();
	void selectmaps();
	void showinventory();
	void personalmenu();
	void checkequip();
	void visitNPC();
	void buyfromFri();
	void buyfromDwarf();
};

#endif
