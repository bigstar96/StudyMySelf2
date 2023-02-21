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


struct Monster2List
{
	Monster2* pHead;
	Monster2* pTail;
};

Monster2* CreatMonster(Monster2List& list, const char* name, const int hp);
int GetCountMonsterList(const Monster2List& list);
void PrintMonsterList(const Monster2List& list);
void PrintListRecursive(Monster2* monster);
Monster2* FindMonster(const Monster2List& list, const char* name);
bool MonsterDelete(Monster2List& list, const char* name);
void DeleteAllMonster(Monster2List& list);