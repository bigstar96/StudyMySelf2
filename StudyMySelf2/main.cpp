#include <iostream>



int main()
{
	int inputNumber;
	std::cout << "���ڸ� �Է��ϼ��� : ";
	std::cin >> inputNumber;

	int biggerNumber;
	std::cout << "�� ū ���ڸ� �Է��ϼ��� : ";
	std::cin >> biggerNumber;

	if (inputNumber > biggerNumber)
	{
		std::cout << "�߸� �Է��ϼ̽��ϴ�.";
	}
	else
	{
		std::cout << "���ϼ̽��ϴ�.";
	}
}
