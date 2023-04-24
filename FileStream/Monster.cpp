#include "Monster.h"

std::ifstream& Monster::ReadBinary(std::ifstream& istream)
{
	int strLen{};
	istream.read(reinterpret_cast<char*>(&strLen), sizeof(int));
	mName.resize(strLen);
	istream.read(&mName[0], strLen);
	istream.read(reinterpret_cast<char*>(&mLevel), sizeof(int));
	istream.read(reinterpret_cast<char*>(&mHP), sizeof(int));
	istream.read(reinterpret_cast<char*>(&mMP), sizeof(int));

	return istream;
}

std::ofstream& Monster::WriteBinary(std::ofstream& ostream)
{
	int strLen = static_cast<int>(mName.size());
	ostream.write(reinterpret_cast<char*>(&strLen), sizeof(int));
	ostream.write(mName.c_str(), strLen);
	ostream.write(reinterpret_cast<char*>(&mLevel), sizeof(int));
	ostream.write(reinterpret_cast<char*>(&mHP), sizeof(int));
	ostream.write(reinterpret_cast<char*>(&mMP), sizeof(int));

	return ostream;
}
