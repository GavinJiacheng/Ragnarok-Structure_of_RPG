#include "SYSTEM.h"
#include <conio.h>



SYSTEM::SYSTEM()
{
	location = "MidGard";
	pler = NULL;
}


SYSTEM::SYSTEM(Player *pl)
{
	location = "MidGard";
	pler = pl;
}


void SYSTEM::menu()
{
	bool domenu = true;
	while(domenu)
	{ 
		char ch;
		bool exe = true;
		cout << "_____________________________________________________________________________________ \n";
		cout << "   You are in " << location << " now.\n" << " Please select what you want to do. \n";
		cout << "(1) Check personal status " << "    (2) Check equipments " << "    (3) Open inventory \n" << "(4) Select maps " << "    (5) Attack enemies " <<"    (6) Visit NPCs \n"<< "(7) Check team " << "    (8) Sleep "<<"    (9) Exit\n";
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
				cout << "haven't done! \n";
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
				cout << "haven't done! \n";
				exe = false;
				break;
			case '9':
				cout << "Exit! \n";
				exe = false;
				domenu = false;
				break;
			}
		}
	}
}

void SYSTEM::personalmenu()
{
	bool domenu = true;
	while (domenu)
	{
		cout << "Your Hp is " << pler->gethitpoints() << " / " << pler->getMaxHP() << endl;
		cout << "Your Strength is " << pler->getstrength() << "    Defense is " << pler->getdefense() << endl;
		cout << "Your level is " << pler->getlevel() << endl;
		cout << "(1) Check your exp    " << "(2) Level up    " << "(3) Go back to main menu " << endl;
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
	cout << "(1)Asgard    (2)Vanaheim    (3)Alfheim    (4)Svartalfheim    (5)Midgard    (6)Muspelheim " << endl;
	char ch;
	bool exe = true;
	while (exe)
	{
		ch = _getch();
		switch (ch)
		{
		case '1':
			location = "Asgard";
			exe = false;
			break;
		case '2':
			location = "Vanaheim";
			exe = false;
			break;
		case '3':
			location = "Alfheim";
			exe = false;
			break;
		case '4':
			location = "Svartalfheim";
			exe = false;
			break;
		case '5':
			location = "Midgard";
			exe = false;
			break;
		case '6':
			location = "Muspelheim";
			exe = false;
			break;
		}
	}
}