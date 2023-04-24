#pragma once
#include <fstream>
#include <string>

class Monster
{
private:
	std::string mName;
	int mLevel;
	int mHP;
	int mMP;
public:
	Monster() : mName{}, mLevel{}, mHP{}, mMP{} {}

	Monster(std::string name, int level, int hp, int mp) :
		mName{ name },
		mLevel{ level },
		mHP{ hp },
		mMP{ mp }
	{}
	
	std::ifstream& ReadBinary(std::ifstream& istream);
	std::ofstream& WriteBinary(std::ofstream& ostream);
};

std::ifstream& operator >>(std::ifstream& istream, Monster& monster)
{
	return monster.ReadBinary(istream);
}
std::ofstream& operator <<(std::ofstream& ostream, Monster& monster)
{
	return monster.WriteBinary(ostream);
}