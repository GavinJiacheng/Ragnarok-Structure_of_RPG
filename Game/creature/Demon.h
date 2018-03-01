<<<<<<< HEAD
<<<<<<< HEAD
#include "Creature.h"
#ifndef DEMON_H
#define DEMON_H


class Demon : public Creature
{
private: 
	string getSpecies(); 
public :
	Demon();
	Demon(string newName, int newStrength, int newHit, int exp);
	Demon(string newName, int newStrength, int newHit);
	virtual int getDamage();
};

=======
#include "Creature.h"
#ifndef DEMON_H
#define DEMON_H
=======
#ifndef DEMON_H
#define DEMON_H
#include "Creature.h"
>>>>>>> add the Inventory, equipment, battle and enemies list;


class Demon : public Creature
{
private: 
	string getSpecies(); 
public :
	Demon();
	Demon(string newName, int newStrength, int newHit, int exp);
	Demon(string newName, int newStrength, int newHit);
	virtual int getDamage();
};

<<<<<<< HEAD
>>>>>>> a55dd91f28694f95712daacba48be33daa0b3276
=======
>>>>>>> add the Inventory, equipment, battle and enemies list;
#endif