#include <iostream>



int main()
{
	std::cout << "Input number : ";

	int number{ 0 };
	std::cin >> number;
	std::cout << "number is " << number << std::endl
		<< "number + 1 is " << number + 1 << std::endl
		<< "number mutiply 3 is " << number * 3 << std::endl
		<< "number's square is " << number * number << std::endl;
}
