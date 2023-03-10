#include <iostream>

class Status
{
public:
	int mHP;
	int mMP;
};

class Potion
{
public:
	int mCount;
	int mRecovery;
};

class Player
{
	Status mStatus;
	Potion* pPotion;
};

class Auction
{
	Player* mPlayer;
};

#include "ClassWarrior.h"

void TestPrint(char* text)
{
	std::cout << text << std::endl;
}

int main()
{
	ClassCharacter* pHero = new ClassWarrior;
	pHero->Attack();
	pHero->Dead();

	// ((ClassWarrior*)pHero)->DoubleSlash();
	ClassWarrior* pWarrior = static_cast<ClassWarrior*>(pHero);
	if (pWarrior = nullptr)
	{
		std::cout << "ERROR!" << std::endl;
	}
	else
	{
		pWarrior->DoubleSlash();
	}

	// 강제 변환 - reinterpret_cast<>();
	const char myString[] = "this is test";
	TestPrint(const_cast<char*>(myString));



	delete pHero;
}