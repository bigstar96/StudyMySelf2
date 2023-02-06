#include <iostream>

int Sum1(int input[], int size)
{
	int sum{};

	for (int i = 0; i < size; ++i)
	{
		sum += input[i];
	}
	return sum;
}

int SumP(int(*input)[3], int count)
{
	int sum{};

	int(*p)[3] = input;

	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			sum += *((*p) + j);
		}
	}

	return sum;
}

int SumP2(int* input, int count)
{
	int sum{};

	int* p = input;
	for (int i = 0; i < count; ++i)
	{
		sum += *p++;
	}

	return sum;
}

int main()
{
	int array[2][3]{
		{1,2,3},
		{4,5,6}
	};
	std::cout << SumP(array, 2);


	int array2[3]{ 7,8,9 };
	std::cout << SumP2(&array2[0][0], 2 * 3) << std::endl;
	std::cout << SumP2(&array2[0], 3) << std::endl;

}