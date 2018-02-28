#include "Demon.h"
#ifndef BALROG_H
#define BALROG_H

class Balrog : public Demon
{
private: 
	string getSpecies(); 
public :
	int returnexp = 10;
	Balrog();
	Balrog(string newName, int newStrength, int newHit, int reexp);
	int getDamage();
};

#endif