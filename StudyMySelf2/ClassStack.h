#pragma once
#include <iostream>

enum Command
{
	PUSH = 1,
	POP = 2,
	EXIT = 3
};

class ClassStack
{
	struct Element
	{
		Element* mNext;
		int mValue;
	};

	int mCount;
	Element* mTop;

public:
	ClassStack();
	~ClassStack();

	void Push(int value);
	bool Pop();
	void Print() const;
};

