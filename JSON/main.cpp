#include "Monster.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <rapidjson/document.h>
#include <rapidjson/prettywriter.h>

using namespace rapidjson;

bool SaveToJson(const char* filename, std::vector<Monster>& monsters)
{
	StringBuffer sb;
	PrettyWriter<StringBuffer> writer(sb);
	writer.StartObject();
	writer.Key("monsters");
	writer.StartArray();
	for (auto monster : monsters)
	{
		writer.StartObject();
		{
			writer.Key("name"); writer.String(monster.GetName().c_str());
			writer.Key("status");
			writer.StartObject();
			{
				Status status = monster.GetStatus();
				writer.Key("level"); writer.Int(status.mLevel);
				writer.Key("hp"); writer.Int(status.mHP);
				writer.Key("mp"); writer.Int(status.mMP);
			}
			writer.EndObject();
			writer.Key("item");
			writer.StartArray();
			{
				for (auto item : monster.GetDeropItems())
				{
					writer.StartObject();
					writer.Key("name"); writer.String(item.mName.c_str());
					writer.Key("gold"); writer.Int(item.mGold);
					writer.EndObject();
				}
			}
			writer.EndArray();
		}
		writer.EndObject();
	}
	writer.EndArray();
	writer.EndObject();
	std::ofstream ofs;
	ofs.exceptions(std::ofstream::badbit | std::ofstream::failbit);
	try
	{
		ofs.open(filename);
		ofs << sb.GetString();
		ofs.close();
	}
	catch (std::ofstream::failure e)
	{
		std::cerr << "파일 저장 중에 예외가 발생했습니다.\n";
		std::cerr << e.what();
		ofs.close();
		return false;
	}

	return true;
}

bool LoadFromJson(const char* filename, std::vector<Monster>& monsters)
{
	std::ifstream ifs;
	ifs.exceptions(std::ifstream::badbit | std::ifstream::failbit);
	std::stringstream ss;
	try
	{
		ifs.open(filename);
		ss << ifs.rdbuf();
		ifs.close();
	}
	catch (std::ifstream::failure e)
	{
		std::cerr << "파일을 읽는 도중 예외가 발생했습니다.\n";
		std::cerr << e.what();
		ifs.close();
		return false;
	}

	Document d;
	d.Parse(ss.str().c_str());
	for (auto& elem : d["monsters"].GetArray())
	{
		Monster monster;
		monster.SetName(elem["name"].GetString());
		Status status;
		status.mLevel = elem["status"].GetObject()["level"].GetInt();
		status.mHP = elem["status"].GetObject()["hp"].GetInt();
		status.mMP = elem["status"].GetObject()["mp"].GetInt();
		monster.SetStatus(status);
		for (auto& elem2 : elem["items"].GetArray())
		{
			Item item;
			item.mName = elem2["name"].GetString();
			item.mGold = elem2["gold"].GetInt();
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
	monster.SetName("슬라임");
	monster.SetStatus(Status{ 1,1,1 });
	monster.AddDropItem(Item{ "끈적한 젤리", 1 });
	monsters.push_back(monster);
	monster.GetDeropItems().clear();
	monster.SetName("늑대인간");
	monster.SetStatus(Status{ 5,5,5 });
	monster.AddDropItem(Item{ "발톱", 2 });
	monster.AddDropItem(Item{ "늑대가죽", 5 });
	monsters.push_back(monster);
	monster.GetDeropItems().clear();
	monster.SetName("악마");
	monster.SetStatus(Status{ 10,10,10 });
	monster.AddDropItem(Item{ "날개", 10 });
	monster.AddDropItem(Item{ "손톱", 5 });
	monsters.push_back(monster);

	SaveToJson("Data/monsters.json", monsters);
	monsters.clear();
	LoadFromJson("Data/monsters.json", monsters);
}
