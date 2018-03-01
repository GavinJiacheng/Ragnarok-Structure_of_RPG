#include "Vampire.h"
#ifndef VAMPIRE_H
#define VAMPIRE_H

class Vampire : public Creature
{
private:
  string getSpecies();
public:
  Vampire();
  Vampire(string newName, int newStrength, int newHit, int reexp);
  int getDamage();
};

#endif
