#include <iostream>

// 평균을 구하는 함수
// 입력 : a < b < c 를 만족하는 양수
// 출력 : 평균(양수)

int average(int a, int b, int c)
{
	if (!(a > 0 && a < b && b < c))
	{
		throw std::logic_error("a, b, c should positive and a < b < c");
	}

	int average{};
	average = (double)(a + b + c) / 3.0;

	if (average < 0)
	{
		throw std::logic_error("average is negative!");
	}

	return average;
}

int main()
{
	int a, b, c;

	std::cout << "세 정수를 입력하세요 : ";
	std::cin >> a >> b >> c;

	try
	{
		std::cout << average(a, b, c) << std::endl;
	}
	catch (std::logic_error)
	{
		std::cerr << "divide by zero" << std::endl;
	}

	return 0;
}