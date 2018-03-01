#include "SYSTEM.h"
#include <conio.h>


using std::cout;
using std::endl;

SYSTEM::SYSTEM()
{
	domenu = true;
	location = "MidGard";
	pler = NULL;
	ALFHEIM = NULL;
	SVAR = NULL;
	MIDGARD = NULL;
	MUSP = NULL;
	HEEL = NULL;
}


SYSTEM::SYSTEM(Player *pl)
{
	domenu = true;
	location = "MidGard";
	pler = pl;
	ALFHEIM = NULL;
	SVAR = NULL;
	MIDGARD = NULL;
	MUSP = NULL;
	HEEL = NULL;
}

void SYSTEM::reset()
{
	delete ALFHEIM;
	delete SVAR;
	delete MIDGARD;
	delete MUSP;
	delete HEEL;
	ALFHEIM = NULL;
	SVAR = NULL;
	MIDGARD = NULL;
	MUSP = NULL;
	HEEL = NULL;
	ALFHEIM = new linkedlist<Creature>(new Elf("Dark Elf", 9, 25, 11));
	for (int i = 0; i < 5; i++)
		ALFHEIM->append(new Elf("Dark Elf", 8, 25, 11));
	SVAR = new linkedlist<Creature>(new Dwarf("Chaos Dwarf", 10, 28, 12));
	for (int i = 0; i < 3; i++)
		SVAR->append(new Dwarf("Chaos Dwarf", 10, 28, 12));
	SVAR->append(new Balrog("Balrog", 12, 40, 35));
	MIDGARD = new linkedlist<Creature>(new Human("Robber", 3, 15, 3));
	for (int i = 0; i < 4; i++)
		MIDGARD->append(new Human("Robber", 3, 15, 3));
	for (int i = 0; i < 3; i++)
		MIDGARD->append(new Human("Dark Ranger", 6, 18, 5));
	MIDGARD->append(new Human("Gavin (Don't attack this)", 999999, 9999999, 0));
	MUSP = new linkedlist<Creature>(new Cyberdemon("Cyberdemon", 9, 30, 21));
	MUSP->append(new Cyberdemon("Cyberdemon", 9, 30, 21));
	for (int i = 0; i < 3; i++)
		MUSP->append(new Cyberdemon("Little Demon", 5, 20, 10));
	MUSP->append(new Balrog("Balrog", 12, 40, 35));
	MUSP->append(new Balrog("Balrog", 12, 40, 35));
}

void SYSTEM::printall(linkedlist<Creature>* list)
{
	if (list == NULL)
	{
		cout << "This map has no enemies!" << endl;
		cout <<  "Press any key to back to main menu!" <<endl;
	}
	else if (list->isEmpty())
	{
		cout << "All enemies were killed!  Please sleep to reset enemies or change map!" << endl;
	}
	else
	{
		int i = 0;
		for (; i < list->listsize(); i++)
		{
			Creature* point = list->getindex(i + 1);
			cout << "(" << i+1 << ") " << point->getName() << " Species: " << point->getSpecies() << "  ";
			if ((i+1) % 5 == 0)
				cout << endl;
		}
		if ( i % 5 != 0 )
			cout << endl;
	}
}

void SYSTEM::menu()
{
	while(domenu)
	{
		system("cls");
		char ch;
		bool exe = true;
		cout << "_____________________________________________________________________________________ " << endl;
		cout << "   You are in " << location << " now.\n" << " Please select what you want to do. "<<endl;
		cout << "(1) Check personal status " << "    (2) Check equipments " << "    (3) Show inventory " <<endl;
		cout << "(4) Select maps " << "              (5) Attack enemies " << "      (6) Visit NPCs" << endl;
		cout << "(7) Check team " << "               (8) Sleep \n";
		cout << "(S) Save                      (L) Load                 (E) Exit " << endl;
		while (exe)
		{
			ch = _getch();
			switch (ch)
			{
			case '1':
				personalmenu();
				exe = false;
				break;
			case '2':
				cout << "haven't done! \n";
				exe = false;
				break;
				//equipments();
			case '3':
				cout << "haven't done! \n";
				exe = false;
				break;
				//equipments();
			case '4':
				selectmaps();
				exe = false;
				break;
				//equipments();
			case '5':
				attackenemies();
				exe = false;
				break;
			case '6':
				cout << "haven't done! \n";
				exe = false;
				break;
			case '7':
				cout << "haven't done! \n";
				exe = false;
				break;
			case '8':
				sleep();
				exe = false;
				break;
			case 'E':
				cout << "Exit! \n";
				exe = false;
				domenu = false;
				break;
			case 'e':
				cout << "Exit! \n";
				exe = false;
				domenu = false;
				break;
			}
		}
	}
}

void SYSTEM::sleep()
{
	reset();
	pler->resethp();
	cout << "All enemies are refreshed and Your hp has been full!" << endl;
	cout << "Press any key to continue...." << endl;
	system("pause");
}

void SYSTEM::attackenemies()
{
	bool doattack = true;
	while (doattack)
	{
		cout << "***************************************************************" << endl;
		cout << "List of Enemies: " << endl;
		char ch = NULL;
		linkedlist<Creature>* THISMAP = NULL;
		if (location == "AsGard")
		{
			THISMAP = NULL;
		}
		if (location == "Alfheim")
		{
			THISMAP = ALFHEIM;
		}
		if (location == "Svartalfheim")
		{
			THISMAP = SVAR;
		}
		if (location == "MidGard")
		{
			THISMAP = MIDGARD;
		}	
		if (location == "Muspelheim")
		{
			THISMAP = MUSP;
		}
		if (location == "Hel")
		{
			THISMAP = HEEL;
		}
		printall (THISMAP);
		while (THISMAP == NULL)
		{
			ch = _getch();
			if (ch != NULL)
				return;
		}
		cout << "Please choose the number you want to attack! (Press 'E' to back to the main menu)"<<endl;
		bool exe = true;
		while (exe)
		{
			ch = _getch();
			int index = (int)(ch -'0');
			if ( index > 0 && index < 1 + THISMAP->listsize())
			{
					Creature* Enemy = THISMAP->getindex(index);;
					Creature* plerpoint = pler;
					//battle battlefunc;
					SOLO (plerpoint, Enemy);
					if (!(pler->gethitpoints() > 0) )
					{
						cout << "Game over." <<endl;
						domenu = false;
						system("pause");
						return;
					}
					if (!(Enemy->gethitpoints() > 0))
					{
						int exp = Enemy->getreturnexp();
						cout << "You win the battle and get "<< exp <<" exp!"<<endl;
						pler->expincrease(exp);
						cout << "You get the amount of " << ((exp / 10)*7 + 1) << " money!" << endl;
						pler->earnmoney((exp / 10) * 7 + 1);
						THISMAP->remove(index);
					} 
					exe = false;
			}
			else if (ch == 'E' || ch == 'e')
			{
					return;
			}
		}
	}
}

void SYSTEM::personalmenu()
{
	bool domenu = true;
	system("cls");
	while (domenu)
	{
		cout << "Your Hp is " << pler->gethitpoints() << " / " << pler->getMaxHP() << endl;
		cout << "Your Strength is " << pler->getstrength() << "    Defense is " << pler->getdefense() << endl;
		cout << "Your level is " << pler->getlevel() << endl;
		cout << "Your money is " << pler->showmethemoney() << endl;
		cout << "(1) Check your exp    " << "(2) Level up    " << "(3) Back to the main menu " << endl;
		char ch;
		bool exe = true;
		while (exe)
		{
			ch = _getch();
			switch (ch)
			{
			case '1':
				pler->checklevel();
				exe = false;
				break;
			case '2':
				pler->levelup();
				exe = false;
				break;
			case '3':
				cout << "Go back.... \n";
				exe = false;
				domenu = false;
				break;
			}
		}
	}
}

void SYSTEM::selectmaps()
{
	cout << "Where do you want to go? " << endl;
	cout << "(1)AsGard    (2)Alfheim    (3)Svartalfheim    (4)MidGard    (5)Muspelheim    (6)Hel " << endl;
	char ch;
	bool exe = true;
	while (exe)
	{
		ch = _getch();
		switch (ch)
		{
		case '1':
			location = "AsGard";
			exe = false;
			break;
		case '2':
			location = "Alfheim";
			exe = false;
			break;
		case '3':
			location = "Svartalfheim";
			exe = false;
			break;
		case '4':
			location = "MidGard";
			exe = false;
			break;
		case '5':
			location = "Muspelheim";
			exe = false;
			break;
		case '6':
			location = "Hel";
			exe = false;
			break;
		}
	}
}
