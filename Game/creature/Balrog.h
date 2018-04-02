<<<<<<< HEAD
#ifndef BALROG_H
#define BALROG_H

#include "Demon.h"


class Balrog : public Demon
{
private: 
	string getSpecies(); 
public :
	int returnexp = 10;
	Balrog();
	Balrog(string newName, int newStrength, int newHit, int reexp);
	int getDamage();
};

=======
#ifndef BALROG_H
#define BALROG_H

#include "Demon.h"


class Balrog : public Demon
{
private: 
	string getSpecies(); 
public :
	int returnexp = 10;
	Balrog();
	Balrog(string newName, int newStrength, int newHit, int reexp);
	int getDamage();
};

>>>>>>> e116e9fe4796fb1aea981cb2fe3440a6c514b4d9
#endif