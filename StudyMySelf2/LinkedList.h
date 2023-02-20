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


