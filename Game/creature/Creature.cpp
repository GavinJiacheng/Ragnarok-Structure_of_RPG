#include<iostream>
#include <stdio.h>
#include <ctime> 
#include "Creature.h"
using std::string; 

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

Creature::Creature( ): name("no one") , strength(10) , hitpoints(10), maxHP(10), defense(0), returnexp(0)
{}

Creature::Creature(string newName, int newStrength, int newHit, int getexp, int def) : name(newName), strength(newStrength), hitpoints(newHit), maxHP(newHit), returnexp(getexp), defense(def)
{}

Creature::Creature(string newName, int newStrength, int newHit, int getexp): name(newName) , strength(newStrength) , hitpoints(newHit), maxHP(newHit),returnexp(getexp), defense(0)
{}

Creature::Creature(string newName, int newStrength, int newHit) : name(newName), strength(newStrength), hitpoints(newHit), maxHP(newHit), returnexp(0), defense(0)
{}

int Creature::getDamage( )
{
	int damage;
	damage = (rand( ) % strength) + 1;
	return damage;
	//cout << getSpecies( ) << " attacks for " << damage << "points!" << endl;
}

int Creature::getMaxHP()
{
	return maxHP;
}

void Creature::hitpointschanger(int attackdamage)
{
	hitpoints -= attackdamage;
}

void Creature::resethp()
{
	hitpoints = maxHP;
}

int Creature::getstrength()
{
	return strength;
}

void Creature::resethp(int newhp)
{
	hitpoints = newhp;
}

void Creature::maxHPadd(int num)
{
	maxHP += num;
}

void Creature::heel(int addhp)
{
	hitpoints += addhp;
	if (hitpoints > maxHP)
		hitpoints = maxHP;
}

int Creature::getdefense()
{
	return defense;
}
	
int Creature::gethitpoints()
{
	return hitpoints;
}

void Creature::addstrength(int news)
{
	strength += news;
}

string Creature::getName()
{
	return name;
}

int Creature::getreturnexp()
{
	return returnexp;
}