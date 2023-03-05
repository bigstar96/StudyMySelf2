#include "ClassString.h"

ClassString::ClassString() : mLength{ 0 }
{ 
	mString = new char[1];
	mString[0] = '\0';
}

ClassString::ClassString(int length)
{
	mString = new char[length + 1];
	mLength = length;
}

ClassString::ClassString(const char* str)
{
	int len{};

	while (str[len] != '\0')
	{
		len++;
	}

	mString = new char[len + 1];
	mLength = len;

	for (int i = 0; i < len; ++i)
	{
		mString[i] = str[i];
	}
	mString[mLength] = '\0';
}

ClassString::ClassString(const ClassString& str)
{
	mString = new char[str.mLength + 1];
	mLength = str.mLength;

	int len{};
	for (len = 0; len < mLength; ++len)
	{
		mString[len] = str.mString[len];
	}
	mString[mLength] = '\0';
}

ClassString::~ClassString()
{
	delete[] mString;
	mString = nullptr;
	mLength = 0;
}

char& ClassString::operator[](int index)
{
	// TODO: 여기에 return 문을 삽입합니다.

	// (조건문) ? 반환값1 : 반환값2  =  ? 연산자 - 조건문이 참이면 반환값1을 거짓이면 반환값2를 반환
	return (index > mLength) ? mString[mLength] : mString[index];
}

char ClassString::operator[](int index) const
{
	return (index > mLength) ? mString[mLength] : mString[index];
}

ClassString ClassString::operator+(const ClassString& str)
{
	ClassString string(mLength + str.mLength);

	int i{};
	for (i; i < mLength; ++i)
	{
		string.mString[i] = mString[i];
	}
	
	for (i; i <= mLength + str.mLength; ++i)
	{
		string.mString[i] = str.mString[i - mLength];
	}

	string.mString[string.mLength] = '\0';

	return string;
}

void ClassString::operator+=(const ClassString& str)
{
	ClassString result = *this + str;

	*this = result;
}

ClassString& ClassString::operator=(const ClassString& str)
{
	if (this == &str)
		return *this;

	delete[] this->mString;
	mString = nullptr;

	mLength = str.mLength;
	mString = new char[mLength + 1];

	for (int i = 0; i < mLength; ++i)
	{
		mString[i] = str.mString[i];
	}
	mString[mLength] = '\0';

	return *this;
}

std::ostream& operator << (std::ostream& os, const ClassString str)
{
	for (int i = 0; i < str.mLength; i++)
	{
		std::cout << str.mString[i];
	}

	return os;
}