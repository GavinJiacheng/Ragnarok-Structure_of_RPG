<<<<<<< HEAD
#include<iostream>
#include <stdio.h>
#include <ctime> 
#include "System\SYSTEM.h"
<<<<<<< HEAD
#include "List\Linkedlist.h"
=======
>>>>>>> a55dd91f28694f95712daacba48be33daa0b3276


using namespace std;



int main()
{
<<<<<<< HEAD
	//Player Hero("Hero", 15 , 40);
	//Player* hero = &Hero;
	SYSTEM newgame(hero);
	newgame.menu();
	//battle battlefunc;
	system("pause");
=======
	Player Hero("Hero", 15 , 40);
	Player* hero = &Hero;
	SYSTEM newgame(hero);
	newgame.menu();
	battle battlefunc;
>>>>>>> a55dd91f28694f95712daacba48be33daa0b3276
} 
=======
#include<iostream>
#include <stdio.h>
#include <ctime>
#include "System\SYSTEM.h"
#include "List\Linkedlist.h"


using namespace std;



int main()
{
	Player Hero("Hero", 12 , 40);
	Player* hero = &Hero;
	SYSTEM newgame(hero);
	newgame.reset();
	newgame.menu();
	//battle battlefunc;
}
>>>>>>> add the Inventory, equipment, battle and enemies list;
