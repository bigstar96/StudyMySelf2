#include <iostream>
#include <chrono>

using Comparison = bool(*)(int, int);

// 오름차순
bool Asscending(int x, int y)
{
	return x < y;
}

bool Descending(int x, int y)
{
	return x > y;
}

void Sort(int numbers[], int count, Comparison f)
{
	int temp{};

	for (int i = 0; i < count; ++i)
	{
		for (int j = i + 1; j < count; ++j)
		{
			if (f(numbers[i], numbers[j]))
			{
				temp = numbers[i];
				numbers[i] = numbers[j];
				numbers[j] = temp;
			}
		}
	}
}

int main()
{
	const int NumArray{ 10 };
	int scores[NumArray]{ 20,10,40,15,30,70,60,90,80,50 };

	auto startTime = std::chrono::system_clock::now();
	Sort(scores, NumArray, Asscending);
	auto endTime = std::chrono::system_clock::now();

	for (int i = 0; i < NumArray; ++i)
	{
		if (i == (NumArray - 1))
		{
			std::cout << scores[i] << std::endl;
			break;
		}
		std::cout << scores[i] << ", ";
	}
	auto duration = endTime - startTime;

	std::cout << "Sort() runs : " << duration.count() << "ms" << std::endl;
}