#include "Demon.h"
#ifndef CYBERDEMON_H
#define CYBERDEMON_H

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