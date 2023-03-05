#include <iostream>

class ClassA
{
public:
	ClassA() {}
};

class ClassB
{
public:
	ClassB() = default;
};

int main()
{
	std::cout << std::is_trivial<ClassA>::value << std::is_pod<ClassA>::value << std::endl;

	std::cout << std::is_trivial<ClassB>::value << std::is_pod<ClassB>::value << std::endl;
}