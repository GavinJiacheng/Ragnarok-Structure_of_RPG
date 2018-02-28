<<<<<<< HEAD
#include<iostream>
#include <stdio.h>
#include <ctime> 
#include "Cyberdemon.h"
using std::string;

string Cyberdemon::getSpecies()
{
return "Cyberdemon";
}

Cyberdemon::Cyberdemon( ):Demon()
{}

Cyberdemon::Cyberdemon(string newName, int newStrength, int newHit, int reexp):Demon(newName, newStrength, newHit, reexp)
{}

int Cyberdemon::getDamage( )
{
	int damage;
	damage = Demon::getDamage();
	return damage;
}
=======
#include<iostream>
#include <stdio.h>
#include <ctime> 
#include "Cyberdemon.h"
using std::string;

string Cyberdemon::getSpecies()
{
return "Cyberdemon";
}

Cyberdemon::Cyberdemon( ):Demon()
{}

Cyberdemon::Cyberdemon(string newName, int newStrength, int newHit, int reexp):Demon(newName, newStrength, newHit, reexp)
{}

int Cyberdemon::getDamage( )
{
	int damage;
	damage = Demon::getDamage();
	return damage;
}
>>>>>>> a55dd91f28694f95712daacba48be33daa0b3276
