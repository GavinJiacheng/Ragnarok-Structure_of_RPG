<<<<<<< HEAD
<<<<<<< HEAD
#include "Human.h"
#ifndef PLAYER_H
#define PLAYER_H

class Player : public Human
{
private:
	int level;
	int exp;
	string getSpecies();

public:
	Player();
	Player(string newName, int newStrength, int newHit);
	int getexp();
	int getlevel();
	void checklevel();
	void levelup();
};

#endif
=======
#include "Human.h"
#ifndef PLAYER_H
#define PLAYER_H

class Player : public Human
=======
#ifndef PLAYER_H
#define PLAYER_H

#include "Human.h"
#include "..\inventory\Carrier.h"


class Player : public Human, public Carrier
>>>>>>> add the Inventory, equipment, battle and enemies list;
{
private:
	int level;
	int exp;
	string getSpecies();

public:
	Player();
	Player(string newName, int newStrength, int newHit);
<<<<<<< HEAD
=======
	void expincrease(int n);
>>>>>>> add the Inventory, equipment, battle and enemies list;
	int getexp();
	int getlevel();
	void checklevel();
	void levelup();
};

#endif
<<<<<<< HEAD
>>>>>>> a55dd91f28694f95712daacba48be33daa0b3276
=======
>>>>>>> add the Inventory, equipment, battle and enemies list;
