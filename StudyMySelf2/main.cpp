#include <iostream>	



int main()
{
	int number = 5;
	int* p = &number;

	std::cout << p << " : " << *p << std::endl;

	int** pp = &p;
	std::cout << pp << " : " << *pp << " : " << **pp;
}