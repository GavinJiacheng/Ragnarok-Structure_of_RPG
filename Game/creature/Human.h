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

>>>>>>> a55dd91f28694f95712daacba48be33daa0b3276
#endif