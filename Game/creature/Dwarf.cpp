#include <iostream>
#include <stdio.h>
#include "Dwarf.h"

using std::cout;
using std::endl;

string Dwarf::getSpecies()
{
  return "Dwarf";
}

Dwarf::Dwarf() :Creature()
{}

Dwarf::Dwarf(string newName, int newStrength, int newHit, int reexp):Creature(newName, newStrength, newHit, reexp, 2)
{}

int Dwarf::getDamage()
{
  int damage;
  damage = Creature::getDamage();
  cout << getName( ) << " attacks for " << damage << "points!" << endl;
  return damage;
}
