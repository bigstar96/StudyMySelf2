#include <iostream>

void PrintDottedLine()
{
	std::cout << "--------------------" << std::endl;
}

void PrintNumber(int x)
{
	std::cout << x << std::endl;
}

int Square(int x)
{
	return x * x;
}

void PrintNumberNotChange(int x)
{
	x = -100;
	std::cout << x << std::endl;
}

int main()
{
	PrintDottedLine();

	int x{ 3 };

	PrintNumber(x);

	std::cout << Square(9) << std::endl;

	PrintNumberNotChange(x);
	std::cout << x << std::endl;
}