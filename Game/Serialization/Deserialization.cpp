#include "Deserialization.h"

Deserialization::Deserialization()
{
}

Deserialization::Deserialization(linkedlist<items>* list, const char * json)
{
	list->resetlist();
	document.Parse(json);
	int size = document["size"].GetInt();
	const Value& nodes = document["Nodes"];
	if (nodes.IsArray()) {
		for (int i = 0; i < size; i++) {
			const Value& object = nodes[i];
			int ID = object["ID"].GetInt();
			string name = object["name"].GetString();
			int amount = object["amount"].GetInt();
			int maxam = object["maxamount"].GetInt();
			int price = object["price"].GetInt();
			bool usable = object["usable"].GetBool();
			if (strcmp(object["species"].GetString(), "equipment") == 0)
			{
				int att = object["att"].GetInt();
				int arm = object["arm"].GetInt();
				bool weap = object["weap"].GetBool();
				bool equiped = object["equiped"].GetBool();
				int special = object["special"].GetInt();
				equipment* equip = new equipment(ID, name, price, att, arm, weap, equiped, special);
				items* it = equip;
				list->append(it);
			}
			else if (strcmp(object["species"].GetString(), "potion") == 0)
			{
				int heal = object["healamount"].GetInt();
				potion* newpotion = new potion(ID, name, amount, price, heal);
				items* it = newpotion;
				list->append(it);
			}
		}
	}
}

Deserialization::Deserialization(Player * pler, const char * json)
{
	document.Parse(json);
	string name = document["name"].GetString();
	int str = document["strength"].GetInt();
	int hp = document["hitpoints"].GetInt();
	int money = document["money"].GetInt();
	pler->set_name(name);
	pler->set_hp(hp);
	pler->setmoney(money);
	int def = document["defense"].GetInt();
	pler->set_power_and_defense(str, def);
	int maxhp = document["maxhp"].GetInt();
	pler->set_maxhp(maxhp);
	int exp = document["exp"].GetInt();
	int level = document["level"].GetInt();
	pler->set_level_and_exp(level, exp);
	const char* inventory = document["Inventory"].GetString();
	linkedlist<items>* playersinventory = pler->showinventory();
	Deserialization Inventory(playersinventory, inventory);
	int weaponID = document["Weapon"].GetInt();
	int aromorID = document["Aromor"].GetInt();
	if (weaponID == 0)
		pler->setwea(NULL);
	else
	{
		equipment *Equipment = dynamic_cast<equipment *>(playersinventory->getindex(weaponID));
		pler->setwea(Equipment);
	}
	if (aromorID == 0)
		pler->setarm(NULL);
	else
	{
		equipment *Equipment = dynamic_cast<equipment *>(playersinventory->getindex(aromorID));
		pler->setarm(Equipment);
	}
}

Deserialization::Deserialization(SYSTEM * sys, const char * json)
{
}
