#ifndef INVENTORY_H
#define INVENTORY_H
#include "Potion.h"
#include "equipment.h"
#include "..\List\Linkedlist.h"


class Carrier{
private:
	int money;
	linkedlist<items> * Inventory;
	int maxamount;
	equipment* Weapon;
	equipment* Armor;
public:
Carrier();
	~Carrier();
	void inventoryadd(items* it);
	int showmethemoney();
    void printallitems();
	int getnumofitems();
    void showmyequipment();
	void earnmoney(int n);
	void losemoney(int n);
    void additem(items* it);
    void dropitem(int i);
	items* getitemindexof(int i);
	int getweaponpower();
	int getarmorshield();
	equipment* getWeapon();
	equipment* getAromor();
	void showiteminfo(int i);
	void useindex(int i, Creature * character);
	void useindex(int i);
	virtual void equip(equipment* equip);
	virtual void unequip(equipment* equip);
	virtual void switchequip(equipment* equip);
};





#endif
