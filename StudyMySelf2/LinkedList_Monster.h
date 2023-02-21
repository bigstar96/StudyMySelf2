#pragma once

const int NAME_LENGTH{ 16 };

struct Monster
{
	char name[NAME_LENGTH];
	int hp;

	Monster* pNext;
};


struct Monster2
{
	char name[NAME_LENGTH];
	int hp;

	Monster2* pNext;
	Monster2* pPrev;
};