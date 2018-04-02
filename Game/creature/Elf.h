<<<<<<< HEAD
#ifndef ELF_H
#define ELF_H
#include "Creature.h"



class Elf : public Creature
{
private:
	string getSpecies();
public:
	Elf();
	Elf(string newName, int newStrength, int newHit, int reexp);
	int getDamage();
};

#endif
=======
#ifndef ELF_H
#define ELF_H
#include "Creature.h"



class Elf : public Creature
{
private:
	string getSpecies();
public:
	Elf();
	Elf(string newName, int newStrength, int newHit, int reexp);
	int getDamage();
};

#endif
>>>>>>> e116e9fe4796fb1aea981cb2fe3440a6c514b4d9
