#include <iostream>



int main()
{
	int inputNumber{};
	std::cin >> inputNumber;

	int absoulteNumber = inputNumber < 0 ? -inputNumber : inputNumber;
	std::cout << absoulteNumber << std::endl;
}
