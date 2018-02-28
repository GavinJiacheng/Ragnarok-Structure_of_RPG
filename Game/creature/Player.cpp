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
