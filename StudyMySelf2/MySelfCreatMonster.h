#pragma once
#include <iostream>

const int NAME_LENGTH{ 16 };

struct MyMonster
{
	char name[NAME_LENGTH];
	int hp;

	MyMonster* pNext;
};

struct MyMonsterList
{
	MyMonster* pHead;
	MyMonster* pTail;
};

enum Command
{
	Create = 1,
	Delete = 2,
	Exit = 3
};

void MySelfMonsterInfo();
MyMonster* MySelfCreatMonster(MyMonsterList& list);
void MySelfPrintMonster(const MyMonsterList& list);
void HowManyCreatMonster(MyMonsterList& list);
char* MySelfFindMonster(MyMonsterList& list);
bool MySelfDeleteMonster(MyMonsterList& list);
void MySelfDeleteAll(MyMonsterList& list);

void MySelfMonsterProcessUserInput(MyMonsterList& list);
