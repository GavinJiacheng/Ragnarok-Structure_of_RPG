#include "Human.h"
#ifndef PLAYER_H
#define PLAYER_H

class Player : public Human
{
private:
	int level;
	int exp;
	string getSpecies();

public:
	Player();
	Player(string newName, int newStrength, int newHit);
	int getexp();
	int getlevel();
	void checklevel();
	void levelup();
};

#endif
