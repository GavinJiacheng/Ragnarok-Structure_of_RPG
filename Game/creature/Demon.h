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

#endif