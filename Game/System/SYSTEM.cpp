#include "SYSTEM.h"
#include <conio.h>


using std::cout;
using std::endl;
using std::cin;

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
	MIDGARD->append(new Human("Gavin (Don't attack this)", 99999, 99999, 0));
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
			cout << "(" << i+1 << ") " << point->getName() << "; Species: " << point->getSpecies() << "  ";
			if ((i+1) % 3 == 0)
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
				checkequip();
				exe = false;
				break;
			case '3':
				showinventory();
				exe = false;
				break;
			case '4':
				selectmaps();
				exe = false;
				break;
			case '5':
				attackenemies();
				exe = false;
				break;
			case '6':
				visitNPC();
				exe = false;
				break;
			case '7':
				cout << "haven't done! \n";
				system("pause");
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
			case 's':
				save();
				exe = false;
				break;
			case 'S':
				save();
				exe = false;
				break;
			case 'l':
				load();
				exe = false;
				break;
			case 'L':
				load();
				exe = false;
				break;
			}
		}
	}
}

void SYSTEM::save()
{
	Serialization saver(pler);
	StringBuffer buffer;
	Writer<StringBuffer> writer(buffer);
	saver.document.Accept(writer);
	const char* output = buffer.GetString();
	ofstream outfile;
	outfile.open("save.dat", ios::trunc);
	outfile << output;
	outfile.close();
	cout << "Save successfully!" << endl;
	system("pause");
}

void SYSTEM::load()
{
	ifstream File("save.dat");
	if (!File)
	{
		cerr << "No save data." << endl;
		system("pause");
		return;
	}
	else
	{
		char data[8192];
		File >> data;
		Deserialization loader(this->pler, data);
		cerr << "Load successfully!" << endl;
		system("pause");
		return;
	}
}

void SYSTEM::checkequip()
{
	system("cls");
	cout << "Your Equipment:" << endl;
	cout << "-------------------------------------------------" << endl;
	pler->showmyequipment();
	system("pause");
}

void SYSTEM::buyfromFri()
{
	while (true)
	{
		system("cls");
		cout << "#########################################################################" << endl;
		cout << "You can buy potions from Freyr! " << endl;
		cout << "Which of these do you want to buy?? (Your money: " << pler->showmethemoney() << " )" << endl;
		cout << " (1) Minor Healing Potion ($8) \t (2) Healing Potion ($22)\n (3) Greater Healing Potion ($50)\t (4) Super Healing Potion (Sold out)" << endl;
		cout << " Press 'C' to back " << endl;
		char newch = 'h';
		while (true)
		{
			newch = _getch();
			if (newch == '1')
			{
				if (!(pler->showmethemoney() < 8))
				{
					pler->additem(new potion(1, "Minor Healing Potion", 1, 8, 10));
					cout << "You bought the Minor Healing Potion!" << endl;
					pler->losemoney(8);
					system("pause");
					break;
				}
				else
				{
					cout << "Your money is not enough!" << endl;
					system("pause");
					break;
				}
			}
			else if (newch == '2')
			{
				if (!(pler->showmethemoney() < 22))
				{
					pler->additem(new potion(2, "Healing Potion", 1, 22, 20));
					cout << "You bought the Healing Potion!" << endl;
					pler->losemoney(22);
					system("pause");
					break;
				}
				else
				{
					cout << "Your money is not enough!" << endl;
					system("pause");
					break;
				}
			}
			else if (newch == '3')
			{
				if (!(pler->showmethemoney() < 50))
				{
					pler->additem(new potion(3, "Greater Healing Potion", 1, 50, 40));
					cout << "You bought the Healing Potion!" << endl;
					pler->losemoney(50);
					system("pause");
					break;
				}
				else
				{
					cout << "Your money is not enough!" << endl;
					system("pause");
					break;
				}
			}
			else if (newch == '4')
			{
				cout << "All Super Healing Potion are drunk by Gavin!! No more!!!" << endl;
				system("pause");
				break;
			}
			else if (newch == 'C' || newch == 'c')
			{
				return;
			}
			else {}
		}
	}
}

void SYSTEM::buyfromDwarf() {
	while (true)
	{
		bool exe = true;
		system("cls");
		cout << "#########################################################################" << endl;
		cout << "You can buy equipments from Thorin Oakenshield! " << endl;
		cout << "Which of these do you want to buy?? (Your money: " << pler->showmethemoney() << " )" << endl;
		cout << "(1) ShortSword ($20) | (2) LongSword ($115) | (3) Rapier ($70) | (4) Sabre (%70) " << endl;
		cout << "(5) Leather Armor ($20) | (6) Chain Mail ($45) | (7) Plate ($80) " << endl;
		cout << " Press 'C' to back " << endl;
		char newch = 'h';
		while (exe)
		{
			newch = _getch();
			if (newch == '1')
			{
				if (!(pler->showmethemoney() < 20))
				{
					pler->additem(new equipment(10, "ShortSword", 20, 2, 0));
					cout << "You bought the ShortSword!" << endl;
					pler->losemoney(20);
					system("pause");
					exe = false;
				}
				else
				{
					cout << "Your money is not enough!" << endl;
					system("pause");
					exe = false;
				}
			}
			else if (newch == '2')
			{
				if (!(pler->showmethemoney() < 115))
				{
					pler->additem(new equipment(11, "LongSword", 115, 7, 1));
					cout << "You bought the LongSword!" << endl;
					pler->losemoney(115);
					system("pause");
					exe = false;
				}
				else
				{
					cout << "Your money is not enough!" << endl;
					system("pause");
					exe = false;
				}
			}
			else if (newch == '3')
			{
				if (!(pler->showmethemoney() < 70))
				{
					pler->additem(new equipment(12, "Rapier", 70, 6, 0));
					cout << "You bought the Rapier!" << endl;
					pler->losemoney(70);
					system("pause");
					exe = false;
				}
				else
				{
					cout << "Your money is not enough!" << endl;
					system("pause");
					exe = false;
				}
			}
			else if (newch == '4')
			{
				if (!(pler->showmethemoney() < 70))
				{
					pler->additem(new equipment(13, "Sabre", 70, 5, 1));
					cout << "You bought the Sabre!" << endl;
					pler->losemoney(70);
					system("pause");
					exe = false;
				}
				else
				{
					cout << "Your money is not enough!" << endl;
					system("pause");
					exe = false;
				}
			}
			else if (newch == '5')
			{
				if (!(pler->showmethemoney() < 20))
				{
					pler->additem(new equipment(20, "Leather Armor", 20, 0, 1, 1));
					cout << "You bought the Leather Armor!" << endl;
					pler->losemoney(20);
					system("pause");
					exe = false;
				}
				else
				{
					cout << "Your money is not enough!" << endl;
					system("pause");
					exe = false;
				}
			}
			else if (newch == '6')
			{
				if (!(pler->showmethemoney() < 45))
				{
					pler->additem(new equipment(21, "Chain Mail", 45, 0, 2, 1));
					cout << "You bought the Chain Mail!" << endl;
					pler->losemoney(45);
					system("pause");
					exe = false;
				}
				else
				{
					cout << "Your money is not enough!" << endl;
					system("pause");
					exe = false;
				}
			}
			else if (newch == '7')
			{
				if (!(pler->showmethemoney() <80))
				{
					pler->additem(new equipment(22, "Plate Armour", 80, 0, 4, 1));
					cout << "You bought the Plate Armour!" << endl;
					pler->losemoney(80);
					system("pause");
					exe = false;
				}
				else
				{
					cout << "Your money is not enough!" << endl;
					system("pause");
					exe = false;
				}
			}
			else if (newch == 'C'||newch == 'c')
			{
				return;
			}
		}
	}
}

void SYSTEM::visitNPC()
{
	char ch;
	while (true)
	{
		system("cls");
		if (location == "AsGard")
		{
			bool exe = true;
			cout << "-----------------------------------------------------------------" << endl;
			cout << "The NPCs in AsGard: " << endl;
			cout << "(1) Odin     (2) Thor     (3) Tyr      (4) Freyr" << endl;
			cout << "Please select the NPC you want to visit! (Press '0 to back!)" << endl;
			while (exe)
			{
				ch = _getch();
				if(ch =='0')
					return;
				else if (ch == '1')
				{
					cout << "Odin is boring , he has nothing to do." << endl;
					system("pause");
					exe = false;
				}
				else if (ch == '2')
				{
					cout << "Thor can train your HP, but you need pay 40 money." << endl;
					cout << "Are you sure to pay? Y/N" << endl;
					while (ch != 'Y' && ch != 'y' && ch != 'n' && ch != 'N')
					{
						ch = _getch();
					}
					if (ch == 'y' || ch == 'Y')
					{
						if (pler->showmethemoney() < 40)
						{
							cout << "Your money is not enough!!" << endl;
							cout << "You need 40 money, but you only have " << pler->showmethemoney() << "money" << endl;
							system("pause");
							exe = false;
						}
						else
						{
							pler->losemoney(40);
							pler->maxHPadd(5);
							cout << "Thor trained you! Now your Max HP is " << pler->getMaxHP() << endl;
							system("pause");
							exe = false;
						}
					}
					else
						exe = false;
				}
				else if (ch == '3')
				{
					cout << "You can hire Valkyrie from Tyr, but he is not here now!" << endl;
					system("pause");
					exe = false;
				}
				else if (ch == '4')
				{
					//bool Buy = true; // if you want to declare somehing in case you nedd {}
					buyfromFri();
					exe = false;
				}
			}
		}
		else if (location == "Svartalfheim")
		{
			bool exe = true;
			cout << "-----------------------------------------------------------------" << endl;
			cout << "The NPCs in AsGard: " << endl;
			cout << "(1) Thorin Oakenshield" << endl;
			cout << "Please select the NPC you want to visit! (Press '0' to back!)" << endl;
			while (exe)
			{
				ch = _getch();
				if (ch == '1')
				{
					buyfromDwarf();
					exe = false;
				}
				else if (ch == '0')
				{
					return;
				}
			}
		}
		else
		{
			cout << "This area has no NPCs!!" << endl;
			system("pause");
			return;
		}
	}
}

void SYSTEM::sleep()
{
	reset();
	pler->resethp();
	cout << "All enemies are refreshed and Your hp has been full!" << endl;
	system("pause");
}

void SYSTEM::attackenemies()
{
	bool doattack = true;
	while (doattack)
	{
		system("cls");
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
					system("pause");
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
		cout << pler->getName() << endl;
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

void SYSTEM::showinventory()
{
	while (true)
	{
		system("cls");
		cout << "Your inventory ( " << pler->getnumofitems() << " / 30 ) :" << endl;
		cout << "___________________________________________________________________________________________" << endl;
		pler->printallitems();
		cout << "___________________________________________________________________________________________" << endl;
		cout << "What do you want to do?" << endl;
		cout << "(Q) Check items     (W) Use items     (E) Equip equipment     (R) Drop items     (T) Back to main menu" << endl;
		bool exe = true;
		char ch;
		while (exe)
		{
			ch = _getch();
			int cinumber;
			if (ch == 'q' || ch == 'Q')
			{
				cout << "Please type the index of the item you want to check (Type '0' to cancel): " << endl;
				cin >> cinumber;
				while (cinumber > pler->getnumofitems() || cinumber < 0 || cin.fail())
				{
					cout << "Please type the right index (0 < and <= " << pler->getnumofitems() << "):" << endl;
					if (cin.fail())
					{
						cin.clear();
						cin.ignore();
					}
					cin >> cinumber;
				}
				if (cinumber == 0)
					break;
				pler->showiteminfo(cinumber);
				exe = false;
			}
			else if (ch == 'W' || ch == 'w')
			{
				cout << "Please type the index of the item you want to use  (Type '0' to cancel): " << endl;
				cin >> cinumber;
				while (cinumber > pler->getnumofitems() || cinumber < 0 || cin.fail())
				{
					cout << "Please type the right index (0 < and <= " << pler->getnumofitems() << "):" << endl;
					if (cin.fail())
					{
						cin.clear();
						cin.ignore();
					}
					cin >> cinumber;
				}
				if (cinumber == 0)
					break;
				if (!(pler->getitemindexof(cinumber)->canbeused()))
				{
					cout << "This Item CANNOT be used!" << endl;
					system("pause");
					break;
				}
				pler->useindex(cinumber, pler);
				system("pause");
				exe = false;
			}
			else if (ch == 'E' || ch == 'e')
			{
				cout << "Please type the index of the item you want to equip  (Type '0' to cancel): " << endl;
				cin >> cinumber;
				while (cinumber > pler->getnumofitems() || cinumber < 0 || cin.fail())
				{
					cout << "Please type the right index (0 < and <= " << pler->getnumofitems() << "):" << endl;
					if (cin.fail())
					{
						cin.clear();
						cin.ignore();
					}
					cin >> cinumber;
				}
				if (cinumber == 0)
					break;
				if (!(pler->getitemindexof(cinumber)->canbeequip()))
				{
					cout << "This Item CANNOT be equiped!" << endl;
					system("pause");
					break;
				}
				equipment *Equipment = dynamic_cast<equipment *>(pler->getitemindexof(cinumber));
				if (Equipment != NULL)
				{
					pler->Doequip(Equipment);
					cout << "Equip successfully!!" << endl;
				}
				else
					cout << "Fail to equip!!" << endl;
				system("pause");
				exe = false;
			}
			if (ch == 'R' || ch == 'r')
			{
				cout << "Please type the index of the item you want to check  (Type '0' to cancel): " << endl;
				cin >> cinumber;
				while (cinumber > pler->getnumofitems() || cinumber < 0 || cin.fail())
				{
					cout << "Please type the right index (0 < and <= " << pler->getnumofitems() << "):" << endl;
					if (cin.fail())
					{
						cin.clear();
						cin.ignore();
					}
					cin >> cinumber;
				}
				if (cinumber == 0)
					break;
				items * IT = pler->getitemindexof(cinumber);
				if (IT->canbeequip())
				{
					equipment *Equipment = dynamic_cast<equipment *>(IT);
					if (Equipment != NULL)
					{
						if(Equipment->isequiped())
						{
							cout << "You cannot drop a equipment which is equiped!!" << endl;
							system("pause");
							break;
						}
					}
					else
					{
						cout << "bugs here." << endl;
						system("pause");
						break;
					}
				}
				pler->dropitem(cinumber);
				cout << "Drop it!" << endl;
				system("pause");
				exe = false;
			}
			if (ch == 't' || ch == 'T')
			{
				return;
			}
		}
	}
}
