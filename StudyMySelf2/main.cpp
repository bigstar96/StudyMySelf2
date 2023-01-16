#include <iostream>

double Max(double x, double y)
{
	return (x > y) ? x : y;
}

int ReadValue()
{
	std::cout << "정수를 입력하세요 : ";
	int x{};
	std::cin >> x;

	return x;
}

void WriteValue(int x)
{
	std::cout << "x : " << x << std::endl;
}

int main()
{
	WriteValue(ReadValue());
}