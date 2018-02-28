<<<<<<< HEAD
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

=======
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

>>>>>>> a55dd91f28694f95712daacba48be33daa0b3276
#endif