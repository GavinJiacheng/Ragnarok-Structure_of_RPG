<<<<<<< HEAD
<<<<<<< HEAD
#include "Creature.h"
#ifndef ELF_H
#define ELF_H


class Elf : public Creature
{
private: 
	string getSpecies(); 
public :
	Elf();
	Elf(string newName, int newStrength, int newHit, int reexp);
	int getDamage();
};

=======
#include "Creature.h"
#ifndef ELF_H
#define ELF_H
=======
#ifndef ELF_H
#define ELF_H
#include "Creature.h"

>>>>>>> add the Inventory, equipment, battle and enemies list;


class Elf : public Creature
{
<<<<<<< HEAD
private: 
	string getSpecies(); 
public :
=======
private:
	string getSpecies();
public:
>>>>>>> add the Inventory, equipment, battle and enemies list;
	Elf();
	Elf(string newName, int newStrength, int newHit, int reexp);
	int getDamage();
};

<<<<<<< HEAD
>>>>>>> a55dd91f28694f95712daacba48be33daa0b3276
#endif
=======
#endif
>>>>>>> add the Inventory, equipment, battle and enemies list;
