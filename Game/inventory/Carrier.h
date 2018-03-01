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
//  ~Carrier();
	int showmethemoney();
//  void printallitems();
    void showmyequipment();
	void earnmoney(int n);
	void losemoney(int n);
    void additem(items* it);
    void dropitem(int i);
	int getweaponpower();
	int getarmorshield();
};





#endif
