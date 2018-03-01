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
public:
	equipment();
	equipment(int id, string nam, int pri, int at, int ar);
	equipment(int id, string nam, int pri, int at, int ar, int aromm);
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