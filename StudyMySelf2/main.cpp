#include <iostream>

// 기존방식
typedef unsigned int uint;

// c++11 방식
using uint = unsigned int;

uint myuint = 1;

void ExistingMethod()
{
	const int PhysicalAttack = 0;
	const int MagicalAttack = 1;
	const int FixedAttack = 2;

	int attackType{ PhysicalAttack };

	switch (attackType)
	{
		case PhysicalAttack:
			break;

		case MagicalAttack:
			break;

		case FixedAttack:
			break;

		default:
			break;
	}
}

void Enumeration()
{
	enum AttackType { Physical, Magical, Fixed };
	AttackType type = Physical;

	switch (type)
	{
		case Physical:
			break;

		case Magical:
			break;

		case Fixed:
			break;

		default:
			break;
	}
}

void Color()
{
	enum color
	{
		Red = 0xFFFF0000,
		Magenta = 0xFFFF00FF,
		Pink = 0xFFFFC0CB
	};
}

int main()
{
	bool quest1Complete = false;
	bool quest2Complete = false;
	bool quest3Complete = false;
	bool quest4Complete = false;

	if (quest1Complete && quest3Complete)
	{
		// 5번 퀘스트 시작
	}

	int questComplete{ 0 };
	// 1, 3번 퀘스트 클리어
	questComplete |= 1;
	questComplete |= 3;
	
	if (questComplete & 1 && questComplete & 4)
	{
		// 5번 퀘스트 시작
	}

	questComplete |= 0x01;
	questComplete |= 0x04;

	// c++11 추가
	questComplete |= 0b0001;
	questComplete |= 0b0100;

	enum QuestCleared
	{
		Quest1 = 0b0001,
		Quest2 = 0b0010,
		Quest3 = 0b0100,
		Quest4 = 0b1000
	};

	int q{};

	q |= Quest1;
	q |= Quest3;
}