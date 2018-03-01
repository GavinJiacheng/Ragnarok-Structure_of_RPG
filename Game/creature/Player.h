#ifndef PLAYER_H
#define PLAYER_H

#include "Human.h"
#include "..\inventory\Carrier.h"


class Player : public Human, public Carrier
{
private:
	int level;
	int exp;
	string getSpecies();

public:
	Player();
	Player(string newName, int newStrength, int newHit);
	void expincrease(int n);
	int getexp();
	int getlevel();
	void checklevel();
	void levelup();
};

#endif
