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
class Deserialization
{
public:
	Document document;
	Deserialization();
	Deserialization(linkedlist<items>* list, const char* json);
	Deserialization(linkedlist<Creature>* list, const char* json);
	Deserialization(Player* pler, const char* json);
	Deserialization(SYSTEM* sys, const char* json);
};