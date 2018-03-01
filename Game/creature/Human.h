<<<<<<< HEAD
<<<<<<< HEAD
#include "Creature.h"
#ifndef HUMAN_H
#define HUMAN_H


class Human : public Creature
{
	private: 
		string getSpecies(); 
	public :
		Human( );
		Human(string newName, int newStrength, int newHit, int reexp);
		Human(string newName, int newStrength, int newHit);
		int getDamage();
};

=======
#include "Creature.h"
#ifndef HUMAN_H
#define HUMAN_H

=======
#ifndef HUMAN_H
#define HUMAN_H

#include "Creature.h"


>>>>>>> add the Inventory, equipment, battle and enemies list;

class Human : public Creature
{
	private: 
		string getSpecies(); 
	public :
		Human( );
		Human(string newName, int newStrength, int newHit, int reexp);
		Human(string newName, int newStrength, int newHit);
		int getDamage();
};

<<<<<<< HEAD
>>>>>>> a55dd91f28694f95712daacba48be33daa0b3276
=======
>>>>>>> add the Inventory, equipment, battle and enemies list;
#endif