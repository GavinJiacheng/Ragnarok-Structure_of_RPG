#include "Creature.h"
#ifndef HUMAN_H
#define HUMAN_H


class Human : public Creature
{
private: 
	string getSpecies(); 
public :
	Human( );
	Human(string newName, int newStrength, int newHit);
	int getDamage();
};

#endif