#pragma once

//#include <iostream>
//#include <time.h>
#include "LinkedList_Monster.h"


struct MonsterList
{
	Monster* pHead;
	Monster* pTail;
};

Monster* CreatMonster(MonsterList& list, const char* name, const int hp);
int GetCountMonsterList(const MonsterList& list);
void PrintMonsterList(const MonsterList& list);
void PrintListRecursive(Monster* monster);
Monster* FindMonster(const MonsterList& list, const char* name);
bool MonsterDelete(MonsterList& list, const char* name);
void DeleteAllMonster(MonsterList& list);


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
