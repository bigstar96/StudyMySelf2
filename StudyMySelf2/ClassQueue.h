#pragma once
#include <iostream>

class ClassQueue
{
	struct Element
	{
		int value;
		Element* next;
	};

	int mCount;
	Element* mFront;
	Element* mRear;

public:
	ClassQueue();
	~ClassQueue();

	void Enqueue(int value);
	bool Dequeue();
	void Print() const;
};

