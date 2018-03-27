#ifndef DWARF_H
#define DWARF_H

#include "Creature.h"

class Dwarf : public Creature
{
private:
  string getSpecies();
public:
  Dwarf();
  Dwarf(string newName, int newStrength, int newHit, int reexp);
  int getDamage();
};

#endif