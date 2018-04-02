<<<<<<< HEAD
#ifndef DEMON_H
#define DEMON_H
#include "Creature.h"


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
#ifndef DEMON_H
#define DEMON_H
#include "Creature.h"


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

>>>>>>> e116e9fe4796fb1aea981cb2fe3440a6c514b4d9
#endif