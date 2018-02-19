#include<iostream>
#include <stdio.h>
#include <ctime> 
#include "Human.h"
using namespace std;

string Human::getSpecies()
{
return "Human";
}

Human::Human( ):Creature()
{}

Human::Human(string newName, int newStrength, int newHit):Creature(newName , newStrength , newHit)
{}

int Creature::getDamage( )
{
	int damage;
	damage = Creature.getDamage();
	cout << getSpecies( ) << " attacks for " << damage << "points!" << endl;
	return damage;
}
