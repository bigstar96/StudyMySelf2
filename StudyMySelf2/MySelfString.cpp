#include "MySelfString.h"

MySelfString::MySelfString(const char* string) : 
	mString{},mLength{}
{
	mLength = 0;
	while (string[mLength] != '\0')
	{
		mLength++;
	}

	mString = new char[mLength + 1];

	for (int i = 0; i < mLength; ++i)
	{
		mString[i] = string[i];
	}

	mString[mLength] = '\0';
}

MySelfString::~MySelfString()
{
	delete[] mString;
	mString = nullptr;
}

void MySelfString::Print()
{
	std::cout << mString;
}
