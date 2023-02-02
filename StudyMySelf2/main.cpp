#include <iostream>

// �ǽ� - �������� ���� ������ ������ ���� �Լ��� ����� ������.
// �Լ� �ñ״���
// void Sort(int numbers[], int count)

// ��������, �������� ���Լ��� ���� �� �Լ� �����ͷ� Ȯ���Ͻÿ�.

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