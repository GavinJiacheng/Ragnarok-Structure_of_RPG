#ifndef CYBERDEMON_H
#define CYBERDEMON_H

#include "Demon.h"


class Cyberdemon : public Demon
{
private: 
	string getSpecies(); 
public :
	int returnexp = 20;
	Cyberdemon();
	Cyberdemon(string newName, int newStrength, int newHit, int reexp);
	int getDamage();
};

#endif