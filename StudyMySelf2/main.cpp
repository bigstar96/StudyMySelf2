#include <iostream>

// 실습 - 내림차순 정렬 문제를 다음과 같은 함수로 만들어 보세요.
// 함수 시그니쳐
// void Sort(int numbers[], int count)

// 오름차순, 내림차순 비교함수를 만든 후 함수 포인터로 확장하시오.

using Comparison = bool (*)(int, int);

bool Asscending(int x, int y)
{
	return x > y;
}

bool Descending(int x, int y)
{
	return x < y;
}

void Sort(int numbers[], int count, Comparison f)
{
	for (int i = 0; i < count; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			if (f(numbers[i], numbers[j]))
			{
				int temp = numbers[i];
				numbers[i] = numbers[j];
				numbers[j] = temp;
			}
		}
	}

}

int main()
{
	const int NumArray = 10;
	int scores[NumArray]{ 20,10,40,15,30,70,85,100,60,90 };

	Sort(scores, NumArray, Descending);

	for (int i = 0; i < NumArray; ++i)
	{
		std::cout << scores[i];
		if (i < NumArray - 1) std::cout << ", ";
	}
}