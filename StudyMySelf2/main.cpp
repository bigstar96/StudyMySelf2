#include <iostream>

int Sum1(int input[5], int start, int end)
{
	if (start == end)
	{
		return input[start];
	}

	return input[start] + Sum1(input, start + 1, end);
}

int Sum2(int numbers[], int count)
{
	if (count <= 1)
	{
		return numbers[0];
	}

	return numbers[count - 1] + Sum2(numbers, count - 1);
}

int main()
{
	int array[]{ 1,2,3,4,5 };
	// std::cout << Sum1(array, 0, 4);

	int numbers[5]{ 1,2,-3,4,5 };
	std::cout << Sum2(numbers, 5) << std::endl;
}