<<<<<<< HEAD
#include<iostream>
#include <stdio.h>
#include <ctime>
#include "Human.h"

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
	cout << getName( ) << " attacks for " << damage << "points!" << endl;
	return damage;
}
=======
#include<iostream>
#include <stdio.h>
#include <ctime>
#include "Human.h"

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
	cout << getName( ) << " attacks for " << damage << "points!" << endl;
	return damage;
}
>>>>>>> e116e9fe4796fb1aea981cb2fe3440a6c514b4d9
