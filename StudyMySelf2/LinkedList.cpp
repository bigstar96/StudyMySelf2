#include <iostream>
#include "LinkedList.h"

Monster* CreatMonster(MonsterList& list, const char* name, const int hp)
{

	Monster* pNew = new Monster;

	strcpy_s(pNew->name, NAME_LENGTH, name);
	pNew->hp = hp;
	pNew->pNext = nullptr;

	if (list.pTail == nullptr)
	{
		list.pHead = pNew;
		list.pTail = pNew;
	}
	else
	{
		list.pTail->pNext = pNew;
		list.pTail = pNew;
	}

	return pNew;
}

int GetCountMonsterList(const MonsterList& list)
{
	Monster* p = list.pHead;
	int count{};

	while (p != nullptr)
	{
		p = p->pNext;
		count++;
	}

	return count;
}

void PrintMonsterList(const MonsterList& list)
{
	Monster* p = list.pHead;
	
	if (list.pHead == nullptr && list.pTail == nullptr)
	{
		std::cout << "No Data" << std::endl;
		return;
	}

	while (p != nullptr)
	{
		std::cout << "NAME : " << p->name << "\t" << "HP :" << p->hp << std::endl;
		p = p->pNext;
	}
}

void PrintListRecursive(Monster* monster)
{
	// base
	if (monster == nullptr)
	{
		return;
	}

	// recursive
	std::cout << monster->name << " : " << monster->hp << std::endl;

	PrintListRecursive(monster->pNext);
}

Monster* FindMonster(const MonsterList& list, const char* name)
{
	for (Monster* p = list.pHead; p != nullptr; p = p->pNext)
	{
		if (strcmp(p->name, name) == 0)
		{
			std::cout << "Find! : " << p->name << " - " << p->hp << std::endl;
			return p;
		}
	}
	return nullptr;
}

bool MonsterDelete(MonsterList& list, const char* name)
{
	Monster* pCurrent = list.pHead;
	Monster* pPrevious{};

	while (pCurrent != nullptr)
	{
		if (strcmp(pCurrent->name, name) == 0)
		{
			break;
		}
		pPrevious = pCurrent;
		pCurrent = pCurrent->pNext;
	}

	if (pCurrent == nullptr)
	{
		return false;
	}

	if (list.pHead == list.pTail)
	{
		// 원소 하나만 있을 때
		list.pHead = list.pTail = nullptr;
	}
	else if (list.pHead == pCurrent)
	{
		// 첫번째 원소
		list.pHead = pCurrent->pNext;
	}
	else if (list.pTail == pCurrent)
	{
		// 마지막 원소
		list.pTail = pPrevious;
		pPrevious->pNext = nullptr;
	}
	else
	{
		// 중간에 있을 때
		pPrevious->pNext = pCurrent->pNext;
	}
	delete pCurrent;

	return true;
}

void DeleteAllMonster(MonsterList& list)
{
	Monster* p = list.pHead;
	Monster* pNext{};

	while (p != nullptr)
	{
		pNext = p->pNext;
		
		delete p;

		p = pNext;
	}

	list.pHead = nullptr;
	list.pTail = nullptr;
}

