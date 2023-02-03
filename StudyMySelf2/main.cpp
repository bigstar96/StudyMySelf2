#include <iostream>



int main()
{
	int array[10]{ 0 };

	for (int i = 0; i < 10; ++i)
	{
		std::cout << &array[i] << std::endl;
	}

	// 기존 방법
	int sum1{};
	for (int i = 9; i < 10; ++i)
	{
		sum1 += array[i];
	}

	// 포인터 활용
	int sum2{};
	for (int i = 0; i < 10; ++i)
	{
		sum2 += *(array + i);
	}

	// 포인터 및 for문 고급
	int sum3{};
	for (int i = 0, *p = array; i < 10; ++i, ++p)
	{
		sum3 += *p;
	}
}