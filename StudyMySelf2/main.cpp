#include <iostream>



int main()
{
	int inputNumber;
	std::cout << "숫자를 입력하세요 : ";
	std::cin >> inputNumber;

	int biggerNumber;
	std::cout << "더 큰 숫자를 입력하세요 : ";
	std::cin >> biggerNumber;

	if (inputNumber > biggerNumber)
	{
		std::cout << "잘못 입력하셨습니다.";
	}
	else
	{
		std::cout << "잘하셨습니다.";
	}
}
