#pragma once 

#include"../rapidjson/document.h"
#include"../rapidjson/pointer.h"
#include"../rapidjson/writer.h"
#include"../rapidjson/stringbuffer.h"
#include"../creature/Player.h"
#include"../List/Linkedlist.h"
#include"../inventory/Carrier.h"
#include"../inventory/equipment.h"
#include"../inventory/items.h"
#include"../inventory/Potion.h"

using namespace rapidjson;

class SYSTEM;
class Serialization
{
public:
	Document document;
	Serialization();
	Serialization(linkedlist<items>* list);
	Serialization(linkedlist<Creature>* list);
	Serialization(Player* pler);
	Serialization(SYSTEM* sys);
};