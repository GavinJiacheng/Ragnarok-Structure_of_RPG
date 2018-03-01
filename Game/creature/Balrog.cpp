<<<<<<< HEAD
<<<<<<< HEAD
#include<iostream>
#include <stdio.h>
#include <ctime> 
#include "Balrog.h"
using std::string;
using std::cout;
using std::endl;

string Balrog::getSpecies()
{
return "Balrog";
}

Balrog::Balrog( ):Demon()
{}

Balrog::Balrog(string newName, int newStrength, int newHit, int reexp):Demon(newName, newStrength, newHit, reexp)
{}

int Balrog::getDamage( )
{
	int damage;
	damage = Demon::getDamage();
	int damage2 = Creature::getDamage();
	cout << "Balrog speed attack inflicts " << damage2 <<" additional damage points!" << endl;
	damage = damage + damage2;
	return damage;
}
=======
#include<iostream>
#include <stdio.h>
#include <ctime> 
#include "Balrog.h"
using std::string;
=======
#include<iostream>
#include <stdio.h>
#include <ctime>
#include "Balrog.h"

>>>>>>> add the Inventory, equipment, battle and enemies list;
using std::cout;
using std::endl;

string Balrog::getSpecies()
{
return "Balrog";
}

Balrog::Balrog( ):Demon()
{}

Balrog::Balrog(string newName, int newStrength, int newHit, int reexp):Demon(newName, newStrength, newHit, reexp)
{}

int Balrog::getDamage( )
{
	int damage;
	damage = Demon::getDamage();
	int damage2 = Creature::getDamage();
	cout << "Balrog speed attack inflicts " << damage2 <<" additional damage points!" << endl;
	damage = damage + damage2;
	return damage;
}
<<<<<<< HEAD
>>>>>>> a55dd91f28694f95712daacba48be33daa0b3276
=======
>>>>>>> add the Inventory, equipment, battle and enemies list;
