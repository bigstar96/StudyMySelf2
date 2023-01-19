#include <iostream>

// 전역 변수
// int myGlobalInteger = 5;

// 외부 변수
extern int myGlobalInteger;

void Step1()
{
	int myInteger{ 5 };

	for (int i = 0; i < 5; ++i)
	{
		int myInteger2{ 0 };
		myInteger = myInteger2 = i;
	}
	// std::cout << myInteger << " , " << myinteger2 << std::endl;
}

void Step2()
{
	int myInteger{};
	myInteger = myGlobalInteger;

	std::cout << myInteger << std::endl;
}

void func()
{
	int x;
}
void func2()
{
	int x;
}

void Step3()
{
	int myInteger{};
	myInteger = myGlobalInteger;

	std::cout << myInteger << std::endl;
}

// Step4
int GetOrderNumber()
{
	static int number{ 0 };
	return ++number;
}

int main()
{
	for (int i = 0; i < 10; ++i)
	{
		std::cout << GetOrderNumber() << std::endl;
	}

}
