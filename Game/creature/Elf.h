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
