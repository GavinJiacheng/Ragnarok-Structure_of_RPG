#include "Potion.h"

potion::potion() :items (2, "Healing Potion", 1, 10, 22, 1) , healamount(20)
{}

potion::potion (int id, string nam, int amo, int pri, int hea): items (id, nam, amo, 10, pri, 1), healamount(hea)
{}

void* potion::use()
{}

void* potion::use(Creature* character)
{
	character->heal(healamount);
	items::amountsub();
	return NULL;
}

void potion::showinfo()
{
	cout << items::getname() << ": " << endl;
	cout << "Species: Potion" << endl;
	cout << "This item's id is: " << items::getID() << endl;
	cout << "Amount: " << items::getam() << endl;
	cout << "Heal Effect: " << healamount << endl;
	cout << "Press any key to back...." << endl;
	system("pause");
}

string potion::getSpecies()
{
	return "potion";
}

/*
Potion list:
1, "Minor Healing Potion", 1, 10, 8, 1; 10;
2, "Healing Potion", 1, 10, 22, 1; 20;
3, "Greater Healing Potion", 1, 10, 50, 1; 40;
4, "Super Healing Potion", 1, 10, 120, 1;  Full;
*/