#include <iostream>

void Pointer()
{
	int a{ 1025 };

	int* pa = &a;

	char* p0 = (char*)pa;

	for (int i = 0; i < 4; ++i)
	{
		std::cout << (void*)p0 << " : " << (int)*p0 << std::endl;
		p0++;
	}
}

void PointerOfAPointer()
{
	int a{ 10 };
	int* p = &a;
	int** pp = &p;
}

void StructureAndPointer()
{
	struct Status
	{
		int HP;
		int MP;
	};

	Status myStatus{ 100,10 };

	Status* pStatus = &myStatus;

	std::cout << (*pStatus).HP << std::endl;
}

int main()
{
	const int x{ 10 }, y{ 20 };
	const int* p;
	p = &x;
	*p = 1;

	std::cout << *p << std::endl;
}