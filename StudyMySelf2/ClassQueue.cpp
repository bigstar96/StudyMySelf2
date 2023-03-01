#include "ClassQueue.h"

ClassQueue::ClassQueue() :
	mCount{}, mFront{ nullptr }, mRear{ nullptr }
{ }

ClassQueue::~ClassQueue()
{
	Element* temp = mFront;
	Element* next = nullptr;

	while (temp != nullptr)
	{
		next = temp->next;
		delete temp;
		temp = next;
	}
}

void ClassQueue::Enqueue(int value)
{
	Element* element = new Element{};
	element->value = value;
	element->next = nullptr;

	if (mCount == 0)
	{
		mFront = element;
		mRear = element;
	}
	else
	{
		mRear->next = element;
		mRear = element;
	}

	mCount++;
}

bool ClassQueue::Dequeue()
{
	if (mCount == 0)
	{
		std::cout << "QUEUE is EMPTY!" << std::endl;
		return false;
	}

	Element* element = mFront;
	std::cout << "dequeue : " << element->value << std::endl;

	mFront = element->next;

	delete element;
	mCount--;

	if (mCount == 0)
	{
		mFront = nullptr;
		mRear = nullptr;
	}

	return false;
}

void ClassQueue::Print() const
{
	Element* element = mFront;
	while (element != nullptr)
	{
		std::cout << element->value << std::endl;
		element = element->next;
	}
}
