#include "Demon.h"
#ifndef BALROG_H
#define BALROG_H

class Balrog : public Demon
{
private: 
	string getSpecies(); 
public :
	Balrog();
	Balrog(string newName, int newStrength, int newHit);
	int getDamage();
};

#endif