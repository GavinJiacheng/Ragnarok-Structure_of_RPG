#include<iostream>
#include <stdio.h>
#include <ctime> 
#include "Creature.h"
using namespace std;

//string Creature::getSpecies()
//{
//switch (type)
//{
//case 0: return "Human";
//case 1: return "Cyberdemon";
//case 2: return "Balrog";
//case 3: return "Elf";
//}
//return "Unknown";
//}

Creature::Creature( ): name("no one") , strength(10) , hitpoints(10)
{}

Creature::Creature(string newName, int newStrength, int newHit): name(newName) , strength(newStrength) , hitpoints(newHit)
{}

int Creature::getDamage( )
{
	int damage;
	damage = (rand( ) % strength) + 1;
	return damage;
	//cout << getSpecies( ) << " attacks for " << damage << "points!" << endl;
}

void Creature::hitpointschanger(int damage)
{
	hitpoints -= damage;
}
	
int Creature::gethitpoints()
{
	return hitpoints
}

string Creature::getName()
{
	return name;
}