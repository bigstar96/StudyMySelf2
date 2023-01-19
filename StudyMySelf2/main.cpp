#include <iostream>	

int Sum(int input[5])
{
	int sum{};
	for (int i = 0; i < 5; ++i)
	{
		sum += input[i];
	}

	input[0] = 0;
	input[1] = 0;

	return sum;
}

int main()
{
	int numbers[] = { 1,2,3,4,5 };
	std::cout << Sum(numbers);
	std::cout << numbers[0] << " , " << numbers[1];
}