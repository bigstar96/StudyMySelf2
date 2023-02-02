#include <iostream>

void swap(int* x, int* y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

void PrintValue(const int& x)
{
	std::cout << x << std::endl;
}

int Sum(int x, int y)
{
	return x + y;
}

int Sigma(int (*f)(int x), int m, int n)
{
	int sum = 0;
	for (int k = m; k <= n; ++k)
	{
		sum += f(k);
	}

	return sum;
}

int NormalFunction(int x)
{
	return x;
}

int SquareSunction(int x)
{
	return x * x;
}

int main()
{
	/*int x{ 10 }, y{ 20 };
	swap(&x, &y);
	std::cout << x << " , " << y << std::endl;*/

	/*const int& ref3{ 10 + 20 };
	std::cout << ref3 << std::endl;

	int x1{ 10 };
	PrintValue(x1);

	const int y1{ 20 };
	PrintValue(y1);
	PrintValue(30);
	PrintValue(40 + 50);*/

	/*int x{ 1 }, y{ 2 };
	std::cout << &x << " , " << &y << std::endl;
	std::cout << Sum << " , " << main << std::endl;
	std::cout << &Sum << " , " << &main << std::endl;

	Sum(x, y);*/

	std::cout << "NormalFunction : " << &NormalFunction << std::endl;
	std::cout << Sigma(NormalFunction, 1, 10) << std::endl;
	std::cout << Sigma(SquareSunction, 1, 10) << std::endl;


}