#ifndef EQUIPMENT_H
#define EQUIPMENT_H
#include "items.h"

class equipment : public items
{
private:
	int att;
	int arm;
	bool weap;
	bool equiped;
	string getSpecies();
	bool canbeequip();
public:
	equipment();
	equipment(int id, string nam, int pri, int at, int ar);
	equipment(int id, string nam, int pri, int at, int ar, int isaromm);
	bool isequiped();
	void equip();
	void unequip();
	bool isweapon();
	int getattack();
	int getarm();
	void showinfo();
	void* use();
	void* use(Creature* sth);
};



#endif


/*
10, ShortSword, 20, 2, 0;
11, Longsword, 115, 7, 1;
12, Rapier, 70, 6, 0;
13, Sabre, 70, 5, 1;

17, Quake, 500, *2, 0;
18, Tyrfing, 300, 18,0; Life steal;
19, Lavateinn, 1000, 70, -10;
*/

/*
20, Leather Armor, 20, 0, 1, 1;
21, Chain Mail, 45, 0, 2,1;
22, Plate, 80, 0, 4, 1;
*/