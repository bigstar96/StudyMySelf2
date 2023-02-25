#pragma once
#include <iostream>


class MySelfString
{
	char* mString;
	int mLength;
public:
	MySelfString(const char* string);
	~MySelfString();

	void Print();
};

