#include <iostream>

class MyClass
{
	int mValue;
public:
	MyClass(int value) : mValue{ value } 
	{
		std::cout << "老馆 积己磊" << std::endl;
	}

	MyClass(const MyClass& from)
	{
		mValue = from.mValue;
		std::cout << "扁夯 积己磊" << std::endl;
	}

};

int main()
{
	MyClass c1{ MyClass{1} };

}