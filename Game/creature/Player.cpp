<<<<<<< HEAD
<<<<<<< HEAD
#include "Player.h"

using std::string;
using std::cout;

Player::Player() : Human()
{}

Player::Player(string newName, int newStrength, int newHit) :Human(newName, newStrength, newHit), exp(0), level(1)
{}

string Player::getSpecies()
{
	return "Player";
}

int Player::getexp()
{
	return exp;
}

int Player::getlevel()
{
	return level;
}

void Player::checklevel()
{
	cout << "You need " << (int)(level * 11 + pow(level, 1.2)) << "exp to level up! \nNow your exp is " << exp << ".\n";
}

void Player::levelup()
{
	if (exp > (int)(level * 11 + pow(level, 1.2)) || exp == (int)(level * 11 + pow(level, 1.2)))
	{
		exp -= (int)(level * 11 + pow(level, 1.2));
		level++;
		maxHPadd(6);
		resethp();
		addstrength(2);
		cout << "Level up! \n";
	}
	else
		cout << "Your exp is not enough!!! You need at least " << (int)(level * 11 + pow(level, 1.2)) << " EXP! But you only have " << exp <<" EXP! \n";
}
=======
#include "Player.h"

using std::string;
using std::cout;

Player::Player() : Human()
=======
#include "Player.h"

using std::cout;

Player::Player() : Human(), Carrier()
>>>>>>> add the Inventory, equipment, battle and enemies list;
{}

Player::Player(string newName, int newStrength, int newHit) :Human(newName, newStrength, newHit), exp(0), level(1)
{}

string Player::getSpecies()
{
	return "Player";
}

<<<<<<< HEAD
=======
void Player::expincrease(int n)
{
	exp += n;
}

>>>>>>> add the Inventory, equipment, battle and enemies list;
int Player::getexp()
{
	return exp;
}

int Player::getlevel()
{
	return level;
}

void Player::checklevel()
{
	cout << "You need " << (int)(level * 11 + pow(level, 1.2)) << "exp to level up! \nNow your exp is " << exp << ".\n";
}

void Player::levelup()
{
	if (exp > (int)(level * 11 + pow(level, 1.2)) || exp == (int)(level * 11 + pow(level, 1.2)))
	{
<<<<<<< HEAD
		exp -= (int)(level * 11 + pow(level, 1.2));
		level++;
		maxHPadd(6);
		resethp();
		addstrength(2);
=======
		exp -= (int)(level * 8 + pow(level, 1.2));
		level++;
		maxHPadd(6);
		resethp();
		addstrength(1);
>>>>>>> add the Inventory, equipment, battle and enemies list;
		cout << "Level up! \n";
	}
	else
		cout << "Your exp is not enough!!! You need at least " << (int)(level * 11 + pow(level, 1.2)) << " EXP! But you only have " << exp <<" EXP! \n";
}
<<<<<<< HEAD
>>>>>>> a55dd91f28694f95712daacba48be33daa0b3276
=======
>>>>>>> add the Inventory, equipment, battle and enemies list;