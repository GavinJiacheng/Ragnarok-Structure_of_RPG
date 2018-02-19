#ifndef CREATURE_H
#define CREATURE_H
#include<iostream>
#include<string>
using namespace std;

class Creature
{
private: 
	string name;
	int strength;
	int hitpoints; 
	string getSpecies(); 
public :
	Creature();
	Creature(string newName, int newStrength, int newHit);
	int getDamage();
	void hitpointschanger(int damage);
	int gethitpoints();
	string getName();
};

#endif