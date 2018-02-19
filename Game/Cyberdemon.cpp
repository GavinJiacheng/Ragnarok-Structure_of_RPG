#include<iostream>
#include <stdio.h>
#include <ctime> 
#include "Cyberdemon.h"
using namespace std;

string Cyberdemon::getSpecies()
{
return "Cyberdemon";
}

Cyberdemon::Cyberdemon( ):Demon()
{}

Cyberdemon::Cyberdemon(string newName, int newStrength, int newHit):Demon(newName, newStrength, newHit)
{}

int Cyberdemon::getDamage( )
{
	int damage;
	damage = Demon.getDamage();
	return damage;
}
