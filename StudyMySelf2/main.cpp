#include <iostream>



int main()
{
	int array[10]{ 0 };

	for (int i = 0; i < 10; ++i)
	{
		std::cout << &array[i] << std::endl;
	}

	// ���� ���
	int sum1{};
	for (int i = 9; i < 10; ++i)
	{
		sum1 += array[i];
	}

	// ������ Ȱ��
	int sum2{};
	for (int i = 0; i < 10; ++i)
	{
		sum2 += *(array + i);
	}

	// ������ �� for�� ���
	int sum3{};
	for (int i = 0, *p = array; i < 10; ++i, ++p)
	{
		sum3 += *p;
	}
}