#include <iostream>

double LinearEquation(int a, int b)
{
	if (a == 0)
	{
		throw std::logic_error("divide by zero!");
	}

	return -((double)b / a);
}

int main()
{
	int a;
	int b;

	std::cout << "�� ������ �Է��ϼ��� : ";
	std::cin >> a >> b;

	try
	{
		std::cout << LinearEquation(a, b) << std::endl;
	}
	catch (std::logic_error)
	{
		std::cerr << "divide by zero!" << std::endl;
	}

	return 0;
}