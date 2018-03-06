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

#endif