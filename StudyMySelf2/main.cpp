#include <iostream>

int Fibonacci(int n)
{
	if (n <= 2)
	{
		return 1;
	}

	return Fibonacci(n - 1) + Fibonacci(n - 2);
}

int SimpleOne(int n)
{
	if (n <= 1)
	{
		return 1;
	}

	SimpleOne(n - 1);
}

int SimpleTwo(int n)
{
	if (n <= 1)
	{
		return 1;
	}

	SimpleTwo(n - 2);
}

int SimpleThree(int n)
{
	if (n <= 1)
	{
		return 1;
	}

	SimpleThree(n - 1);
	SimpleThree(n - 1);
}

int SimpleFour(int n)
{
	if (n <= 1)
	{
		return 1;
	}

	SimpleFour(n - 2);
	SimpleFour(n - 2);
}

int main()
{
	std::cout << Fibonacci(6) << std::endl;
	std::cout << Fibonacci(40) << std::endl;
}