#include <iostream>

class MyClass
{
public:
	int mValue;
	MyClass(int value) : mValue{ value }
	{
		std::cout << "[ MyClass() ] : "
			<< mValue << std::endl;
	}

	MyClass operator+(const MyClass& c)
	{
		return MyClass{ mValue + c.mValue };
	}
};

int Square(const MyClass& c)
{
	return c.mValue * c.mValue;
}

int main()
{
	MyClass c1{ 1 }, c2{ 2 };

	std::cout << "----------" << std::endl;
	Square(c1 + c2);

	std::cout << "-----" << std::endl;
	std::cout << (c1 + c2).mValue << std::endl;

	std::cout << "-------" << std::endl;
	MyClass c3{ c1 + c2 };
}