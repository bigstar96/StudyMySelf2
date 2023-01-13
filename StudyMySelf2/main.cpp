#include <iostream>

union MyUnion
{
	int i;
	float f;
	char c;
};



int main()
{
	MyUnion myUnion;

	myUnion.i = 98;
	std::cout << myUnion.i << ", " << myUnion.f << ", " << myUnion.c << std::endl;

	myUnion.f = 1.1f;
	std::cout << myUnion.i << ", " << myUnion.f << ", " << myUnion.c << std::endl;

	myUnion.c = 'a';
	std::cout << myUnion.i << ", " << myUnion.f << ", " << myUnion.c << std::endl;
}