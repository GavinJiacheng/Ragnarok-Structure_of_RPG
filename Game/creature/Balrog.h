<<<<<<< HEAD
<<<<<<< HEAD
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

=======
#include "Demon.h"
#ifndef BALROG_H
#define BALROG_H

=======
#ifndef BALROG_H
#define BALROG_H

#include "Demon.h"


>>>>>>> add the Inventory, equipment, battle and enemies list;
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

<<<<<<< HEAD
>>>>>>> a55dd91f28694f95712daacba48be33daa0b3276
=======
>>>>>>> add the Inventory, equipment, battle and enemies list;
#endif