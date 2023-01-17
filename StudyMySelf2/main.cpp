#include <iostream>

// 정수 a를 b로 나눈 몫을 구하는 함수와 나머지를 구하는 함수를 만들어 봅시다.
int Quotient(int a, int b)
{
	return a / b;
}

int Remainder(int a, int b)
{
	return a % b;
}


int main()
{
	int a{ 7 };
	int b{ 3 };

	std::cout << a << " / " << b << " = " << std::endl;
	std::cout << "몫 : " << Quotient(a, b) << std::endl;
	std::cout << "나머지 : " << Remainder(a, b) << std::endl;
}