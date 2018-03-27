#pragma once
#include <iostream>
#include <string>
#include "../creature/Player.h"

using std::string;

struct hostinfo 
{
	int hostid;
	string hostname;
	int realid;
};

class connection
{
private:
	string playername;
	Player *pler;
	WSADATA wsaData;
	SOCKADDR_IN addrSrv;
	SOCKET sockClient;
	bool ishost;
	hostinfo hosts[10];
	int hostid = 0;
public:
	connection();
	connection(string name, Player *localpler);
	void init();
	void serveradd(string ipad, int portnumber);
	void start();
	void showallhosts();
	int total();
	void inhost(string name);
	void joinnum(int num);
	void listner();
	void SYSTEM();
};