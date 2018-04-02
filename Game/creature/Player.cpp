#include "Player.h"

using std::cout;

Player::Player() : Human(), Carrier()
{}

Player::Player(string newName, int newStrength, int newHit) :Human(newName, newStrength, newHit), exp(0), level(1)
{}

string Player::getSpecies()
{
	return "Player";
}

void Player::expincrease(int n)
{
	exp += n;
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
		exp -= (int)(level * 8 + pow(level, 1.2));
		level++;
		maxHPadd(6);
		resethp();
		addstrength(1);
		cout << "Level up! \n";
	}
	else
		cout << "Your exp is not enough!!! You need at least " << (int)(level * 11 + pow(level, 1.2)) << " EXP! But you only have " << exp <<" EXP! \n";
}

void Player::equip(equipment* Equipment)
{
		int power = Equipment->getattack();
		int def = Equipment->getarm();
		this->addstrength(power);
		this->adddefense(def);
		this->Carrier::equip(Equipment);
}

void Player::unequip(equipment* Equipment)
{
	int power = Equipment->getattack();
	int def = Equipment->getarm();
	this->losestrength(power);
	this->losedefense(def);
	this->Carrier::unequip(Equipment);
}

void Player::switchequip(equipment* Equipment)
{
	int power = Equipment->getattack();
	int def = Equipment->getarm();
	int nowpower, nowdef;
	if (Equipment->isweapon())
	{
		nowpower = getWeapon()->getattack();
		nowdef = getWeapon()->getarm();
	}
	else
	{
		nowpower = getAromor()->getattack();
		nowdef = getAromor()->getarm();
	}
	this->losestrength(nowpower);
	this->losedefense(nowdef);
	this->addstrength(power);
	this->adddefense(def);
	this->Carrier::switchequip(Equipment);
}

void Player::Doequip(equipment* Equipment)
{
	if (Equipment->isweapon())
	{
		if (getWeapon() == NULL)
			equip(Equipment);
		else
			switchequip(Equipment);
	}
	else
	{
		if (getAromor() == NULL)
			equip(Equipment);
		else
			switchequip(Equipment);
	}
}

int Player::getDamage()
{
	if (getWeapon() == NULL || getWeapon()->getspecial() == 0)
		return Human::getDamage();
	else
		return getWeapon()->getdamage(this);
}
