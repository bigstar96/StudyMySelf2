#include <iostream>

class MyClass
{
public:
	static int sCount;

	MyClass()
	{
		sCount++;
	}
	~MyClass()
	{
		sCount--;
	}

};

int MyClass::sCount{ 0 };

class MyIDGenerator
{
public:
	static int sID;

	static int CreateNewID()
	{
		return ++sID;
	}
};

int MyIDGenerator::sID{ 0 };

int main()
{
	MyClass c1;
	MyClass c2;
	MyClass c3;
	
	std::cout << c3.sCount << std::endl;
	std::cout << MyClass::sCount << std::endl;

	std::cout << std::endl;

	std::cout << MyIDGenerator::CreateNewID() << std::endl;
	std::cout << MyIDGenerator::CreateNewID() << std::endl;
	std::cout << MyIDGenerator::CreateNewID() << std::endl;
}