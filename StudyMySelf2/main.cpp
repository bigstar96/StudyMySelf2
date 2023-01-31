#include <iostream>



int main()
{
	int a{ 1 }, b{ 2 };
	int* p;
	p = &a;
	*p = 3;
	std::cout << *p << std::endl;

	std::cout << &a << " : " << a << std::endl;
	std::cout << &b << " : " << b << std::endl;
	std::cout << p << " : " << *p << std::endl;

	int a1{ 1 };
	int* p1 = &a;

	std::cout << p << std::endl;
	std::cout << p + 1 << std::endl;
	std::cout << p + 2 << std::endl;
	p = p + sizeof(int) * 2;
	std::cout << p << std::endl;
}