<<<<<<< HEAD
#include<iostream>
#include <stdio.h>
#include <ctime> 
#include "Demon.h"
using std::string;
using std::cout;
using std::endl;

string Demon::getSpecies()
{
return "Demon";
}

Demon::Demon( ):Creature()
{}

Demon::Demon(string newName, int newStrength, int newHit, int exp):Creature(newName, newStrength, newHit, exp)
{}

Demon::Demon(string newName, int newStrength, int newHit) : Creature(newName, newStrength, newHit, 7)
{}

int Demon::getDamage( )
{
	int damage;
	damage = Creature::getDamage();
	cout << getSpecies( ) << " attacks for " << damage << "points!" << endl;
	if ((rand( ) % 100) < 5)
	{
		damage = damage + 50;
		cout << "Demonic attack inflicts 50 "<< "additional damage points!" << endl;
	}
	return damage;
=======
#include<iostream>
#include <stdio.h>
#include <ctime> 
#include "Demon.h"
using std::string;
using std::cout;
using std::endl;

string Demon::getSpecies()
{
return "Demon";
}

Demon::Demon( ):Creature()
{}

Demon::Demon(string newName, int newStrength, int newHit, int exp):Creature(newName, newStrength, newHit, exp)
{}

Demon::Demon(string newName, int newStrength, int newHit) : Creature(newName, newStrength, newHit, 7)
{}

int Demon::getDamage( )
{
	int damage;
	damage = Creature::getDamage();
	cout << getSpecies( ) << " attacks for " << damage << "points!" << endl;
	if ((rand( ) % 100) < 5)
	{
		damage = damage + 50;
		cout << "Demonic attack inflicts 50 "<< "additional damage points!" << endl;
	}
	return damage;
>>>>>>> a55dd91f28694f95712daacba48be33daa0b3276
}