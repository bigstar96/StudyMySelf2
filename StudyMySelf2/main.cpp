#include <iostream>

class MyClass
{
	int mValue;
public:
	MyClass(int value) : mValue{ value } 
	{
		std::cout << "�Ϲ� ������" << std::endl;
	}

	MyClass(const MyClass& from)
	{
		mValue = from.mValue;
		std::cout << "�⺻ ������" << std::endl;
	}

};

int main()
{
	MyClass c1{ MyClass{1} };

}