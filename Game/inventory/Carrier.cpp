#include "Carrier.h"

Carrier::Carrier()
{
  money = 15;
  Inventory = new linkedlist<items>(new potion(1, "Minor Healing Potion", 1, 8, 10));
  maxamount = 30;
  Weapon = NULL;
  Armor = NULL;
}

Carrier::~Carrier()
{
	delete Inventory;
}

void Carrier::inventoryadd(items* it)
{
	Inventory->append(it);
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
		cout << Weapon->getname() << "     Power: " << Weapon->getattack() << endl;
	cout << "Armor: ";
	if (Armor == NULL)
		cout << "No Armor" << endl;
	else
		cout << Armor->getname() << "     Shield: " << Armor->getarm() << endl;
}

void Carrier::additem(items* it)
{
	if (it->getmax()>1)
	{
		int size = Inventory->listsize();
		for (int i = 0; i < size; i++)
		{
			items* thisitem = Inventory->getindex(i + 1);
			if (it->getID() == thisitem->getID() && thisitem->getam() < thisitem->getmax())
			{
				thisitem->amountadd();
				return;
			}
		}
	}
	if (!(Inventory->listsize() < maxamount))
	{
		cout << "Inventory full! " << endl;
		return;
	}
	else
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

items * Carrier::getitemindexof(int i)
{
	if (i > 0 && !(i > Inventory->listsize()))
		return Inventory->getindex(i);
	else
	{
		cout << "Illegal input i!" << endl;
		return NULL;
	}
}

int Carrier::getweaponpower()
{
	return Weapon->getattack();
}
int Carrier::getarmorshield()
{
	return Armor->getarm();
}

void Carrier::printallitems()
{
	int size = Inventory->listsize();
	for (int i = 0; i < size; i++)
	{
		items* thisitem = Inventory->getindex(i + 1);
		cout << "(" << i + 1 << ") " << thisitem->getname() << "- Species: " << thisitem->getSpecies() << "- Amount: " << thisitem->getam();
		if ((i + 1) % 2 == 0 || (i+1) == size)
			cout << endl;
		else
			cout << " | ";
	}
}

int Carrier::getnumofitems()
{
	return Inventory->listsize();
}

void Carrier::equip(equipment* Equipment)
{
	if (Equipment->isweapon())
	{
		Weapon = Equipment;
		Weapon->equip();
	}
	else
	{
		Armor = Equipment;
		Armor->equip();
	}
}

void Carrier::unequip(equipment* Equipment)
{
	if (Equipment->isweapon())
	{
		Weapon->unequip();
		Weapon = NULL;
	}
	else
	{
		Armor->unequip();
		Armor = NULL;
	}
}

void Carrier::switchequip(equipment* Equipment)
{
	if (Equipment->isweapon())
	{
		Weapon->unequip();
		Weapon = Equipment;
		Weapon->equip();
	}
	else
	{
		Armor->unequip();
		Armor = Equipment;
		Armor->equip();
	}
}

equipment* Carrier::getWeapon()
{
	return Weapon;
}
equipment* Carrier::getAromor()
{
	return Armor;
}

void Carrier::showiteminfo(int i)
{
	if (i > 0 && !(i > Inventory->listsize()))
		Inventory->getindex(i)->showinfo();
	else
		cout << "Illegal input i!" << endl;
}

void Carrier::useindex(int i, Creature* character)
{
	if (i > 0 && !(i > Inventory->listsize()))
	{
		items* useitem = Inventory->getindex(i);
		if (!(useitem->canbeused()))
		{
			cout << "This Item CANNOT be used!" << endl;
			return;
		}
		if (useitem->use(character) != NULL)
			dropitem(i);
	}
	else
		cout << "Illegal input i!" << endl;
}

void Carrier::useindex(int i)
{
	return;
}

