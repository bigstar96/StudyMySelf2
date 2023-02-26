#include "ClassStack.h"

ClassStack::ClassStack() : mCount{}, mTop{ nullptr }
{
}

ClassStack::~ClassStack()
{
	Element* element = mTop;
	Element* next = nullptr;

	while (element != nullptr)
	{
		next = element->mNext;
		delete element;
		element = next;
	}
}

void ClassStack::Push(int value)
{
	Element* element = new Element{};
	element->mValue = value;

	element->mNext = mTop;
	mTop = element;
	mCount++;
}

bool ClassStack::Pop()
{
	if (mCount == 0)
	{
		std::cout << "STACK is EMPTY!" << std::endl;
		return false;
	}

	Element* prevTop = mTop;
	int value = prevTop->mValue;

	mTop = prevTop->mNext;
	mCount--;

	delete prevTop;

	std::cout << "POP : " << value << std::endl;

	return true;
}

void ClassStack::Print() const
{
	Element* elmt = mTop;

	while (elmt != nullptr)
	{
		std::cout << elmt->mValue << std::endl;
		elmt = elmt->mNext;
	}
}
