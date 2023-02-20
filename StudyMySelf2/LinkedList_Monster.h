#pragma once

const int NAME_LENGTH{ 16 };

struct Monster
{
	char name[NAME_LENGTH];
	int hp;

	Monster* pNext;
};

struct MyMonster
{
	char name[NAME_LENGTH];
	int hp;

	MyMonster* pNext;
};