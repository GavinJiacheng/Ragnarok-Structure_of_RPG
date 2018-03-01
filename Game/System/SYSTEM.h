<<<<<<< HEAD
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
=======
>>>>>>> add the Inventory, equipment, battle and enemies list;

#ifndef SYSTEM_H
#define SYSTEM_H

#include <iostream>
#include <string>
#include <stdio.h>
<<<<<<< HEAD
#include "../battle/battle.cpp"
=======
#include "../battle/battle.h"
#include "../List/Linkedlist.h"
>>>>>>> add the Inventory, equipment, battle and enemies list;


using std::string;

class SYSTEM
{
private:
<<<<<<< HEAD
	string location;
	Player *pler;
	//Creature list;


public:
	SYSTEM();
	SYSTEM(Player *pl);
	//void UI();
	void menu();
=======
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
>>>>>>> add the Inventory, equipment, battle and enemies list;
	void selectmaps();
	void personalmenu();
};

<<<<<<< HEAD
>>>>>>> a55dd91f28694f95712daacba48be33daa0b3276
#endif
=======
#endif
>>>>>>> add the Inventory, equipment, battle and enemies list;
