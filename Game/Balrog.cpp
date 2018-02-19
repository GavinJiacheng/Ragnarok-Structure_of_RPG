#include<iostream>
#include <stdio.h>
#include <ctime> 
#include "Balrog.h"
using namespace std;

string Balrog::getSpecies()
{
return "Balrog";
}

Balrog::Balrog( ):Demon()
{}

Balrog::Balrog(string newName, int newStrength, int newHit):Demon(newName, newStrength, newHit)
{}

int Balrog::getDamage( )
{
	int damage;
	damage = Demon.getDamage();
	int damage2 = Creature.getDamage();
	cout << "Balrog speed attack inflicts " << damage2 <<"additional damage points!" << endl;
	damage = damage + damage2;
	return damage;
}
