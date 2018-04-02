<<<<<<< HEAD
#ifndef HUMAN_H
#define HUMAN_H

#include "Creature.h"



class Human : public Creature
{
	private: 
		string getSpecies(); 
	public :
		Human( );
		Human(string newName, int newStrength, int newHit, int reexp);
		Human(string newName, int newStrength, int newHit);
		virtual int getDamage();
};

=======
#ifndef HUMAN_H
#define HUMAN_H

#include "Creature.h"



class Human : public Creature
{
	private: 
		string getSpecies(); 
	public :
		Human( );
		Human(string newName, int newStrength, int newHit, int reexp);
		Human(string newName, int newStrength, int newHit);
		virtual int getDamage();
};

>>>>>>> e116e9fe4796fb1aea981cb2fe3440a6c514b4d9
#endif