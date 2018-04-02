#include "equipment.h"

<<<<<<< HEAD
//equipment::equipment() :items(), att(1), arm(0), weap(true), equiped(false), specaildamage(NULL)
//{}
//
//equipment::equipment(int id, string nam, int pri, int at, int ar) :items(id, nam, 1, 1, pri, 0), att(at), arm(ar), weap(true), equiped(false), specaildamage(NULL)
//{}
//
//equipment::equipment(int id, string nam, int pri, int at, int ar, int isaromm) : items(id, nam, 1, 1, pri, 0), att(at), arm(ar), weap(false), equiped(false), specaildamage(NULL)
//{}
//
//equipment::equipment(int id, string nam, int pri, int at, int ar, int isaromm, int (*damagefunc)(Player* p)) : items(id, nam, 1, 1, pri, 0), att(at), arm(ar), weap(false), equiped(false), specaildamage((*damagefunc))
//{}

equipment::equipment() :items(), att(1), arm(0), weap(true), equiped(false), special(0)
{}

equipment::equipment(int id, string nam, int pri, int at, int ar) : items(id, nam, 1, 1, pri, 0), att(at), arm(ar), weap(true), equiped(false), special(0)
{}

equipment::equipment(int id, string nam, int pri, int at, int ar, int isaromm) : items(id, nam, 1, 1, pri, 0), att(at), arm(ar), weap(false), equiped(false), special(0)
{}

equipment::equipment(int id, string nam, int pri, int at, int ar, int isaromm, int specialID) : items(id, nam, 1, 1, pri, 0), att(at), arm(ar), weap(false), equiped(false), special(specialID)
=======
equipment::equipment() :items(), att(1), arm(0), weap(true), equiped(false), specaildamage(NULL)
{}

equipment::equipment(int id, string nam, int pri, int at, int ar) :items(id, nam, 1, 1, pri, 0), att(at), arm(ar), weap(true), equiped(false), specaildamage(NULL)
{}

equipment::equipment(int id, string nam, int pri, int at, int ar, int isaromm) : items(id, nam, 1, 1, pri, 0), att(at), arm(ar), weap(false), equiped(false), specaildamage(NULL)
{}

equipment::equipment(int id, string nam, int pri, int at, int ar, int isaromm, int (*damagefunc)(Player* p)) : items(id, nam, 1, 1, pri, 0), att(at), arm(ar), weap(false), equiped(false), specaildamage((*damagefunc))
>>>>>>> e116e9fe4796fb1aea981cb2fe3440a6c514b4d9
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

<<<<<<< HEAD
int equipment::getspecial()
{
	return special;
}

=======
>>>>>>> e116e9fe4796fb1aea981cb2fe3440a6c514b4d9
int equipment::getattack()
{
	return att;
}
<<<<<<< HEAD

int equipment::getdamage(Player* p)
{
	if (special != 0)
		return choosefunc(p);
	else
		return 0;
}

//int equipment::getdamage(Player* p)
//{
//	if (specaildamage != NULL)
//		return (*specaildamage)(p);
//	else
//		return 0;
//}
=======
int equipment::getdamage(Player* p)
{
	if (specaildamage != NULL)
		return (*specaildamage)(p);
	else
		return 0;
}
>>>>>>> e116e9fe4796fb1aea981cb2fe3440a6c514b4d9
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
	system("pause");
}

<<<<<<< HEAD
int equipment::choosefunc(Player * p)
{
	return 0;
}

=======
>>>>>>> e116e9fe4796fb1aea981cb2fe3440a6c514b4d9
string equipment::getSpecies()
{
	if (weap)
		return "Equipment-Weapon";
	else
		return "Equipment-Armor";
}

bool equipment::canbeequip()
{
	return true;
}

void* equipment::use() { return NULL; }
void* equipment::use(Creature* sth) { return NULL; }