#include <iostream>



int main()
{
	int scores[10];

	for (int i = 0; i < 10; ++i)
	{
		std::cout << "Input score[" << i << "] : ";
		std::cin >> scores[i];
	}

	for (int i = 0; i < 10; ++i)
	{
		std::cout << i << " : " << scores[i] << std::endl;
	}
}