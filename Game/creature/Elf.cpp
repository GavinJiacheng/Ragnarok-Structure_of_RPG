#include<iostream>
#include <stdio.h>
#include <ctime> 
#include "Elf.h"
using std::string;
using std::cout;
using std::endl;

string Elf::getSpecies()
{
return "Elf";
}

Elf::Elf( ):Creature()
{}

Elf::Elf(string newName, int newStrength, int newHit, int reexp):Creature(newName, newStrength, newHit, reexp)
{}

int Elf::getDamage( )
{
	int damage;
	damage = Creature::getDamage();
	cout << getSpecies( ) << " attacks for " << damage << "points!" << endl;
	if ((rand( ) % 10)==0)
	{
		cout << "Magical attack inflicts " << damage <<"additional damage points!" << endl;
		damage = damage * 2;
	}
		return damage;
}
