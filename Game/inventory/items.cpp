#include "items.h"


items::items()
{
	ID = 0;
	name = "Nothing";
	maxamount = 1;
	amount = 1;
	price = 1;
	usable = false;
}

items::items(string nam)
{
	ID = 0;
	name = "nam";
	maxamount = 1;
	amount = 1;
	price = 1;
	usable = false;
}

items::items(int id, string nam, int amo, int maxam, int pri, int us)
{
	ID = id;
	name = "nam";
	amount = amo;
	maxamount = maxam;
	price = pri;
	usable = (bool)us;
}

string items::getname()
{
	return name;
}

int items::getID()
{
	return ID;
}

int items::getmax()
{
	return maxamount;
}

int items::getam()
{
	return amount;
}

int items::getpri()
{
	return price;
}

int items::amountadd()
{
	amount++;
}

int items::amountadd(int n)
{
	amount += n;
}

int items::amountsub(int n)
{
	amount - +n;
}

int items::amountsub()
{
	amount--;
}