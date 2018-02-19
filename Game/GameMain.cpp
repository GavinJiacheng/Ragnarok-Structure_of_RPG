#include<iostream>
#include <stdio.h>
#include <ctime> 
#include "Creature.h"
#include "Human.h"
#include "Elf.h"
#include "Demon.h"
#include "Cyberdemon.h"
#include "Balrog.h"

using namespace std;

void battleArena(Creature A, Creature B)
{
	int A_damage, B_damage;
	cout << A.getName() <<" is attacking  "<< B.getName() <<endl;
	cout << A.getName() <<" HP is " << A.gethitpoints() << endl;
	cout << B.getName() <<" HP is " << B.gethitpoints() << endl;
	while (A.gethitpoints() > 0 && B.gethitpoints() > 0 )
	{
		A_damage = A.getDamage();
		B_damage = B.getDamage();
		cout << A.getName() <<" damage is " << A_damage << endl;
		cout << B.getName() <<" damage is " << B_damage << endl;
		A.hitpointschanger(B_damage);
		B.hitpointschanger(A_damage);
		cout << A.getName() <<" HP is " << A.gethitpoints() << endl;
		cout << B.getName() <<" HP is " << B.gethitpoints() << endl;
	}
	if ( B.gethitpoints() <= 0 )
		cout << A.getName() <<" has Killed "<< B.getName() <<endl;
	else 
		cout << A.getName() <<" has been killed by "<<B.getName() <<endl;
}

int main()
{
	Balrog Badguy_1("Bad Balrog" , 10 , 30);
	Cyberdemon Badguy_2("Bad Cyberdemon" , 25 , 60);
	Elf Badguy_3("Bad Elf", 15 , 10);
	Human Good_guy("Hero", 15 , 50);
} 