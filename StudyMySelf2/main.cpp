#include <iostream>

// �ǽ� - �������� ���� ������ ������ ���� �Լ��� ����� ������.
// �Լ� �ñ״���
// void Sort(int numbers[], int count)

void Sort(int numbers[], int count)
{
	for (int i = 0; i < count; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			if (numbers[i] < numbers[j])
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
	int scores[NumArray]{ 20,10,40,15,30 };

	Sort(scores, NumArray);

	for (int i = 0; i < NumArray; ++i)
	{
		std::cout << scores[i];
		if (i < NumArray - 1) std::cout << ", ";
	}
}