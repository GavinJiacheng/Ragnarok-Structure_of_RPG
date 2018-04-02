<<<<<<< HEAD
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

=======
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

>>>>>>> e116e9fe4796fb1aea981cb2fe3440a6c514b4d9
#endif