<<<<<<< HEAD
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

=======
#ifndef CYBERDEMON_H
#define CYBERDEMON_H

#include "Demon.h"


>>>>>>> add the Inventory, equipment, battle and enemies list;
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

<<<<<<< HEAD
>>>>>>> a55dd91f28694f95712daacba48be33daa0b3276
=======
>>>>>>> add the Inventory, equipment, battle and enemies list;
#endif