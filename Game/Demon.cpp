#include<iostream>
#include <stdio.h>
#include <ctime> 
#include "Demon.h"
using namespace std;

string Demon::getSpecies()
{
return "Demon";
}

Demon::Demon( ):Creature()
{}

Demon::Demon(string newName, int newStrength, int newHit):Creature(newName, newStrength, newHit)
{}

int Demon::getDamage( )
{
	int damage;
	damage = Creature.getDamage();
	cout << getSpecies( ) << " attacks for " << damage << "points!" << endl;
	if ((rand( ) % 100) < 5)
	{
		damage = damage + 50;
		cout << "Demonic attack inflicts 50 "<< "additional damage points!" << endl;
	}
	return damage;
}