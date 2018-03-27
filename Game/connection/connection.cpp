#include "connection.h"
#include <iostream>
#include <conio.h>
#include <windows.h>

using std::cout;
using std::endl;
using std::cin;


connection::connection()
{
	playername = "";
	pler = NULL;
	ishost = false;
	for (int i = 0; i < 10; i++)
	{
		hosts[i].hostid = 0;
		hosts[i].hostname = "";
		hosts[i].realid = 0;
	}
}

connection::connection(string name, Player *localpler)
{
	playername = name;
	pler = localpler;
	ishost = false;
	for (int i = 0; i < 10; i++)
	{
		hosts[i].hostid = 0;
		hosts[i].hostname = "";
	}
}

void connection::init()
{
	start();
}

void connection::serveradd(string ipaddress, int portnumber)
{
	addrSrv.sin_family = AF_INET;
	addrSrv.sin_port = htons(portnumber);
	addrSrv.sin_addr.S_un.S_addr = inet_addr(ipaddress.c_str());
	sockClient = socket(AF_INET, SOCK_STREAM, 0);
	if (SOCKET_ERROR == sockClient) 
	{
		cout << "Socket() error: " << WSAGetLastError() << endl;
		system("pause");
		return;
	}
}

void connection::start()
{
	char buff[1024];
	int num;
	memset(buff, 0, sizeof(buff));
	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
	{
		cout << "Fail to initalize the Winsock" << endl;
		system("pause");
		return;
	}
	serveradd("127.0.0.1", 9000);
	if (connect(sockClient, (SOCKADDR*)&addrSrv, sizeof(addrSrv)) == INVALID_SOCKET)
	{
		cout << "Fail to connect to the server" << endl;
		system("pause");
		return;
	}
	else
	{
		num = recv(sockClient, buff, sizeof(buff), 0);
	}
	if (num == SOCKET_ERROR || num == 0)
	{
		cout << " Cannot connect to the server!" << endl;
		system("pause");
	}
	else
	{
		cout << buff << endl;
		system("pause");
	}
}

void connection::showallhosts()
{
	char show[1] = { 'S' };
	char buff[2048];
	int num;
	memset(buff, 0, sizeof(buff));
	send(sockClient, show, 1, 0);
	num = recv(sockClient, buff, sizeof(buff), 0);
	if (num == SOCKET_ERROR || num == 0)
	{
		cout << " The connecttion is end." << endl;
		system("pause");
	}
	else
	{
		memcpy(hosts, buff, sizeof(buff));
		for (int i = 0; hosts[i].hostid != 0; i++)
			cout << "(" << hosts[i].hostid << ") " << hosts[i].hostname << endl;
	}
}

int connection::total()
{
	char show[1] = { 't' };
	char buff[1024];
	int num;
	memset(buff, 0, sizeof(buff));
	send(sockClient, show, 1, 0);
	num = recv(sockClient, buff, sizeof(buff), 0);
	if (num == SOCKET_ERROR || num == 0)
	{
		cout << " The connecttion is end." << endl;
		system("pause");
		return -1;
	}
	else
		return atoi(buff);
}

void connection::inhost(string name)
{
	while (true)
	{
		char buff[1024];
		memset(buff, 0, sizeof(buff));
		cout << "You are in " << name << "'s host!" << endl;
		cout << "what do you want to do?" << endl;
		cout << "(1) Fight with others    (2) Return to the Holy War menue" << endl;
		cout << "Other palyers:" << endl;
		//Thread join :showotherplayers();
		//Thread join :listerinhost();
		char ch;
		while (true)
		{
			ch = _getch();
			if (ch = '1')
			{
				//deadlock here
				int fuck;
				cout << "Please chooese the number you want to attack:" << endl;
				cin >> fuck;
				while (cin.fail())
				{
					cout << "Illegal input! Please type the number which is less than the max number and larger than 0 in:" << endl;
					cin.clear();
					cin.ignore();
					cin >> fuck;
				}
				send(sockClient, (char*)fuck, sizeof(fuck), 0);
				do {
					int num = recv(sockClient, buff, sizeof(buff), 0);
					if (num == SOCKET_ERROR || num == 0)
					{
						cout << " Cannot connect to the host." << endl;
						system("pause");
						//end thread
						return;
					}
					if ((string)buff == "no")
						cout << "You cannot fight with this ID!" << endl;
					cout << (string)buff << endl;
				} while ((string)buff != "end");
				cout << "-----------------" << endl;
				cout << "The battle is over;" << endl;
				system("pause");
				send(sockClient, (char*)"end", sizeof("end"), 0);
				break;
			}
			else if (ch = '2')
			{
				//deadlock here
				send(sockClient, (char*)"Bye", sizeof("Bye"), 0);
				//end thread here
				return;
			}
		}
	}
}

void connection::joinnum(int num)
{
	char buff[1024];
	int newnum;
	memset(buff, 0, sizeof(buff));
	send(sockClient, (char*) num, sizeof(num), 0);
	newnum = recv(sockClient, buff, sizeof(buff), 0);
	if (newnum == SOCKET_ERROR || newnum == 0)
	{
		cout << " The connecttion is end." << endl;
		system("pause");
	}
	else if(hosts[num].realid != (int) buff)
		cout << "This host is no longer connected." << endl;
	else
		inhost(hosts[num].hostname);
}

void connection::listner()
{
}

void connection::SYSTEM()
{
	init();
	while (true)
	{
		system("cls");
		cout << "-------------------------------------------------Holy War---------------------------------------------------" << endl;
		cout << "You are at the battlae of the Holy War now!" << endl;
		cout << "(A) Connect to others         (B) Refresh list           (C) Start a host        (D) Escape" << endl;
		cout << "--------------------------------------------------------------------------------" << endl;
		cout << "Hosts here:" << endl;
		showallhosts();
		int maxnum = total();
		char ch;
		while (true)
		{
			ch = _getch();
			if (ch = 'a' || 'A')
			{
				int fuck;
				cout << "Please chooese the number you want to connect:" << endl;
				cin >> fuck;
				while (fuck > maxnum || fuck < 1)
				{
					cout << "Illegal input! Please type the number which is less than the max number and larger than 0 in:" << endl;
					cin >> fuck;
				}
				joinnum(fuck);
				break;
			}
			else if (ch = 'b' || 'B')
				break;
			else if (ch = 'c' || 'C')
			{
				starthost();
				break;
			}
			else if (ch = 'd' || 'D')
			{
				return;
			}
		}
	}
}
