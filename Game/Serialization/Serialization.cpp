#include "Serialization.h"

Serialization::Serialization()
{
}

Serialization::Serialization(linkedlist<items>* list)
{
	Pointer("/project").Set(document, "listitems");
	Pointer("/size").Set(document, list->listsize());
	if (list->listsize() > 0)
	{
		rapidjson::Value info_array(rapidjson::kArrayType);
		rapidjson::Document::AllocatorType& allocator = document.GetAllocator();
		for (int i = 1; i <= list->listsize(); i++)
		{
			rapidjson::Value info_object(rapidjson::kObjectType);
			info_object.SetObject();
			info_object.AddMember("ID", list->getindex(i)->getID(), allocator);
			info_object.AddMember("name", StringRef(list->getindex(i)->getname().c_str()), allocator);
			info_object.AddMember("amount", list->getindex(i)->getam(), allocator);
			info_object.AddMember("maxamount", list->getindex(i)->getmax(), allocator);
			info_object.AddMember("price", list->getindex(i)->getpri(), allocator);
			info_object.AddMember("usable", list->getindex(i)->canbeused(), allocator);
			if (list->getindex(i)->getSpecies() == "Equipment-Weapon" || list->getindex(i)->getSpecies() == "Equipment-Armor")
			{
				info_object.AddMember("species", "equipment", allocator);
				equipment* shit = dynamic_cast<equipment*>(list->getindex(i));
				info_object.AddMember("att", shit->getattack(), allocator);
				info_object.AddMember("arm", shit->getarm(), allocator);
				info_object.AddMember("weap", shit->isweapon(), allocator);
				info_object.AddMember("equiped", shit->isequiped(), allocator);
				info_object.AddMember("special", shit->getspecial(), allocator);
			}
			else if (list->getindex(i)->getSpecies() == "potion")
			{
				info_object.AddMember("species", "potion", allocator);
				potion* shit = dynamic_cast<potion*>(list->getindex(i));
				info_object.AddMember("healamount", shit->gethealamount(), allocator);
			}
			info_array.PushBack(info_object, allocator);
		}
		document.AddMember("Nodes", info_array, allocator);
	}
	else 
		Pointer("/Nodes/0").Create(document);
}

Serialization::Serialization(Player * pler)
{
	Pointer("/name").Set(document, StringRef(pler->getName().c_str()));
	Pointer("/strength").Set(document, pler->getstrength());
	Pointer("/hitpoints").Set(document, pler->gethitpoints());
	Pointer("/returnexp").Set(document, pler->getreturnexp());
	Pointer("/defense").Set(document, pler->getdefense());
	Pointer("/money").Set(document, pler->showmethemoney());
	if (pler->getWeapon() == NULL)
		Pointer("/Weapon").Set(document, 0);
	else
	{
		int id = pler->searchitemnumer(pler->getWeapon());
		Pointer("/Weapon").Set(document, id);
	}
	if (pler->getAromor() == NULL)
		Pointer("/Aromor").Set(document, 0);
	else
	{
		int id = pler->searchitemnumer(pler->getAromor());
		Pointer("/Aromor").Set(document, id);
	}
	Serialization inventorylist(pler->showinventory());
	StringBuffer buffer;
	Writer<StringBuffer> writer(buffer);
	inventorylist.document.Accept(writer);
	const char* output = buffer.GetString();
	Pointer("/Inventory").Set(document, output);
	Pointer("/level").Set(document, pler->getlevel());
	Pointer("/exp").Set(document, pler->getexp());
}

Serialization::Serialization(SYSTEM * sys)
{
}
