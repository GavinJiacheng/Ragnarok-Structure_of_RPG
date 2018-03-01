#include<iostream>
#include <stdio.h>
#include <ctime> 
#include "Cyberdemon.h"

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
