#include "equipment.h"

equipment::equipment() :items(), att(1), arm(0), weap(true), equiped(false)
{}

equipment::equipment(int id, string nam, int pri, int at, int ar) :items(id, nam, 1, 1, pri, 0), att(at), arm(ar), weap(true), equiped(false)
{}

equipment::equipment(int id, string nam, int pri, int at, int ar, int aromm) : items(id, nam, 1, 1, pri, 0), att(at), arm(ar), weap(false), equiped(false)
{}

void equipment::equip()
{
	equiped = true;
}

void equipment::unequip()
{
	equiped = false;
}

bool equipment::isweapon()
{
	return weap;
}

bool equipment::isequiped()
{
	return equiped;
}

int equipment::getattack()
{
	return att;
}
int equipment::getarm()
{
	return arm;
}
void equipment::showinfo()
{
	cout << items::getname() << ": " << endl;
	cout << "Species: ";
	if (weap)
	{
		cout << "Weapon" << endl;
		cout << "Power: " << att << endl;
	}
	else
	{
		cout << "Armor" << endl;
		cout << "Shield: " << arm << endl;
	}
	if (equiped)
	{
		cout << "Status: Equiped " << endl;
	}
	cout << "This item's id is: " << items::getID() << endl;
	cout << "Press any key to back...." << endl;
	system("pause");
}

string equipment::getSpecies()
{
	return "equipment";
}

void* equipment::use(){}
void* equipment::use(Creature* sth){}