<<<<<<< HEAD
#ifndef CREATURE_H
#define CREATURE_H
#include<iostream>
#include<string>

using std::string;

class Creature
{
private: 
	string name;
	int strength;
	int hitpoints; 
	int returnexp;
	int	defense;
	int maxHP;
public :
	Creature();
	Creature::Creature(string newName, int newStrength, int newHit, int getexp, int def);
	Creature(string newName, int newStrength, int newHit, int getexp);
	Creature(string newName, int newStrength, int newHit);
	virtual int getDamage() = 0;
	virtual string getSpecies() = 0;
	void hitpointschanger(int damage);
	int getstrength();
	int getMaxHP();
	int gethitpoints();
	string getName();
	int getreturnexp();
	void maxHPadd(int num);
	void resethp(int newhp);
	void resethp();
	void addstrength(int news);
	void heel(int addhp);
	int getdefense();
	//void equip();
	//void unequip();
};

=======
#ifndef CREATURE_H
#define CREATURE_H
#include<iostream>
#include<string>

using std::string;

class Creature
{
private: 
	string name;
	int strength;
	int hitpoints; 
	int returnexp;
	int	defense;
	int maxHP;
public :
	Creature();
	Creature::Creature(string newName, int newStrength, int newHit, int getexp, int def);
	Creature(string newName, int newStrength, int newHit, int getexp);
	Creature(string newName, int newStrength, int newHit);
	virtual int getDamage() = 0;
	virtual string getSpecies() = 0;
	void hitpointschanger(int damage);
	int getstrength();
	int getMaxHP();
	int gethitpoints();
	string getName();
	int getreturnexp();
	void maxHPadd(int num);
	void resethp(int newhp);
	void resethp();
	void addstrength(int news);
	void heel(int addhp);
	int getdefense();
	//void equip();
	//void unequip();
};

>>>>>>> a55dd91f28694f95712daacba48be33daa0b3276
#endif