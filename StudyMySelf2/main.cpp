#include <iostream>

double Max(double x, double y)
{
	return (x > y) ? x : y;
}

int ReadValue()
{
	std::cout << "������ �Է��ϼ��� : ";
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