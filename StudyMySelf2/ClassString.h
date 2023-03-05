#pragma once
#include <iostream>
// 2022-04-07

class ClassString
{
private:
	int mLength;
	char* mString;

public:
	ClassString();
	ClassString(int length);
	ClassString(const char* str);
	ClassString(const ClassString& str);
	~ClassString();

	int GetLength() const { return mLength; }
	const char* GetString() const { return mString; }

public:
	char& operator[](int index);
	char operator[](int index) const;
	ClassString operator+(const ClassString& str);
	void operator+=(const ClassString& str);
	ClassString& operator=(const ClassString& str);
	
	friend std::ostream& operator << (std::ostream& os, const ClassString str);
};

