#include <iostream>	

void WhoAmI(int value);
void WhoAmI(float value);
void WhoAmI(float value1, float value2);

int main()
{
	WhoAmI(10.0f,0.0f);
}

void WhoAmI(int value)
{
	std::cout << "나는 정수를 처리합니다." << value << std::endl;
}

void WhoAmI(float value)
{
	std::cout << "나는 소수를 처리합니다." << value << std::endl;
}

void WhoAmI(float value1, float value2)
{
	std::cout << "나는 소수를 2개 처리합니다." << value1 << ", " << value2 << std::endl;
}

