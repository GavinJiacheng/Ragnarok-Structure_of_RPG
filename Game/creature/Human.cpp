<<<<<<< HEAD
#include<iostream>
#include <stdio.h>
#include <ctime> 
#include "Human.h"
using std::string;
using std::cout;
using std::endl;

string Human::getSpecies()
{
return "Human";
}

Human::Human( ):Creature()
{}

Human::Human(string newName, int newStrength, int newHit, int reexp) : Creature(newName, newStrength, newHit, reexp)
{}

Human::Human(string newName, int newStrength, int newHit):Creature(newName , newStrength , newHit, 0)
{}

int Human::getDamage( )
{
	int damage;
	damage = Creature::getDamage();
	cout << getSpecies( ) << " attacks for " << damage << "points!" << endl;
	return damage;
}
=======
#include<iostream>
#include <stdio.h>
#include <ctime> 
#include "Human.h"
using std::string;
using std::cout;
using std::endl;

string Human::getSpecies()
{
return "Human";
}

Human::Human( ):Creature()
{}

Human::Human(string newName, int newStrength, int newHit, int reexp) : Creature(newName, newStrength, newHit, reexp)
{}

Human::Human(string newName, int newStrength, int newHit):Creature(newName , newStrength , newHit, 0)
{}

int Human::getDamage( )
{
	int damage;
	damage = Creature::getDamage();
	cout << getSpecies( ) << " attacks for " << damage << "points!" << endl;
	return damage;
}
>>>>>>> a55dd91f28694f95712daacba48be33daa0b3276
