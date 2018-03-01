#ifndef POTION_H
#define POTION_H
#include "items.h"

class potion : public items
{
private:
	int healamount;
	string getSpecies();
public:
	potion();
	potion(int id, string nam, int amo, int pri, int hea);
	void* use(Creature* character);
	void* use();
	void showinfo();
};

#endif

/*
Potion list:
1, "Minor Healing Potion", 1, 10, 8, 1; 10;
2, "Healing Potion", 1, 10, 22, 1; 20;
3, "Greater Healing Potion", 1, 10, 50, 1; 40;
4, "Super Healing Potion", 1, 10, 120, 1;  Full;
*/
