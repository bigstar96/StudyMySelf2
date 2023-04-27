#include <iostream>
#include "Monster.h"
#include "tinyxml2.h"

using namespace tinyxml2;

bool SaveToXML(const char* filename, const std::vector<Monster>& monsters)
{
	XMLDocument doc;

	XMLDeclaration* decl = doc.NewDeclaration(
		R"(xml version="1.0" encoding="EUC-KR")"
	);
	doc.LinkEndChild(decl);

	XMLElement* pRootNode = doc.NewElement("monsters");
	for (auto monster : monsters)
	{
		auto pMonsterNode = doc.NewElement("monster");
		pMonsterNode->SetAttribute("name", monster.GetName().c_str());

		auto pStatusNode = doc.NewElement("status");
		Status status = monster.GetStatus();
		pStatusNode->SetAttribute("level", status.mLevel);
		pStatusNode->SetAttribute("hp", status.mHP);
		pStatusNode->SetAttribute("mp", status.mMP);
		pMonsterNode->LinkEndChild(pStatusNode);

		auto pItemsNode = doc.NewElement("items");
		for (auto item : monster.GetDeropItems())
		{
			auto pItemNode = doc.NewElement("item");
			pItemNode->SetAttribute("name", item.mName.c_str());
			pItemNode->SetAttribute("gold", item.mGold);
			pItemsNode->LinkEndChild(pItemNode);
		}
		pMonsterNode->LinkEndChild(pItemsNode);
		pRootNode->LinkEndChild(pMonsterNode);
	}

	doc.LinkEndChild(pRootNode);
	return (doc.SaveFile(filename) == XML_SUCCESS);
}

bool LoadFromXML(const char* filename, std::vector<Monster>& monsters)
{
	XMLDocument doc;
	if (doc.LoadFile(filename) != XML_SUCCESS)
	{
		return false;
	}

	auto pRootNode = doc.FirstChildElement("monsters");
	for (auto pMonsterNode = pRootNode->FirstChildElement();
		pMonsterNode;
		pMonsterNode = pMonsterNode->NextSiblingElement())
	{
		Monster monster;

		monster.SetName(pMonsterNode->Attribute("name"));

		auto pStatusNode = pMonsterNode->FirstChildElement("status");
		Status status;
		status.mLevel = pStatusNode->IntAttribute("level");
		status.mHP = pStatusNode->IntAttribute("hp");
		status.mMP = pStatusNode->IntAttribute("mp");
		monster.SetStatus(status);

		auto pItemsNode = pMonsterNode->FirstChildElement("items");
		for (auto pItemNode = pItemsNode->FirstChildElement();
			pItemNode;
			pItemNode = pItemNode->NextSiblingElement())
		{
			Item item;
			item.mName = pItemNode->Attribute("name");
			item.mGold = pItemNode->IntAttribute("gold");
			monster.AddDropItem(item);
		}
		monsters.push_back(monster);
	}
	return true;
}



int main()
{
	std::vector<Monster> monsters;
	Monster monster;
	monster.SetName("ΩΩ∂Û¿”");
	monster.SetStatus(Status{ 1,1,1 });
	monster.AddDropItem(Item{ "≤ˆ¿˚«— ¡©∏Æ", 1 });
	monsters.push_back(monster);
	monster.GetDeropItems().clear();

	monster.SetName("¥¡¥Î¿Œ∞£");
	monster.SetStatus(Status{ 5,5,5 });
	monster.AddDropItem(Item{ "πﬂ≈È", 2 });
	monster.AddDropItem(Item{ "¥¡¥Î∞°¡◊", 5 });
	monsters.push_back(monster);
	monster.GetDeropItems().clear();

	monster.SetName("æ«∏∂");
	monster.SetStatus(Status{ 10,10,10 });
	monster.AddDropItem(Item{ "≥Ø∞≥",10 });
	monster.AddDropItem(Item{ "º’≈È",5 });
	monsters.push_back(monster);

	SaveToXML("Data/monsters.xml", monsters);
	monsters.clear();
	LoadFromXML("Data/monsters.xml", monsters);
}