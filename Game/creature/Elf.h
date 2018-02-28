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


class Elf : public Creature
{
private: 
	string getSpecies(); 
public :
	Elf();
	Elf(string newName, int newStrength, int newHit, int reexp);
	int getDamage();
};

>>>>>>> a55dd91f28694f95712daacba48be33daa0b3276
#endif