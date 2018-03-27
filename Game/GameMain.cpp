#include<iostream>
#include <stdio.h>
#include <ctime>
#include "System\SYSTEM.h"
#include "List\Linkedlist.h"


using namespace std;



int main()
{
	Player Hero("Hero", 10 , 45);
	Player* hero = &Hero;
	SYSTEM newgame(hero);
	newgame.reset();
	newgame.menu();
	//battle battlefunc;
}
