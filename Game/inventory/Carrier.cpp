#include "Carrier.h"

Carrier::Carrier()
{
  money = 15;
  Inventory = new linkedlist<items>(new potion(1, "Minor Healing Potion", 1, 8, 10));
  maxamount = 30;
  Weapon = NULL;
  Armor = NULL;
}

int Carrier::showmethemoney()
{
  return money;
}

void Carrier::earnmoney(int n)
{
  money += n;
}

void Carrier::losemoney(int n)
{
  money -= n;
  if (money < 0)
    money = 0;
}

void Carrier::showmyequipment()
{
	cout << "Weapon: ";
	if (Weapon == NULL)
		cout << "No Weapon" << endl;
	else
		cout << Weapon->getname() << "Power: " << Weapon->getattack() << endl;
	cout << "Armor: ";
	if (Armor == NULL)
		cout << "No Armor" << endl;
	else
		cout << Armor->getname() << "Shield: " << Armor->getarm() << endl;
}

void Carrier::additem(items* it)
{
	if (!(Inventory->listsize() < maxamount))
	{
		cout << "Inventory full! " << endl;
		return;
	}
	Inventory->append(it);
}

void Carrier::dropitem(int i)
{
	if (i > Inventory->listsize() || i < 1)
	{
		cout << "Illegal input!" << endl;
		return;
	}
	Inventory->remove(i);
}

int Carrier::getweaponpower()
{
	return Weapon->getattack();
}
int Carrier::getarmorshield()
{
	return Armor->getarm();
}

