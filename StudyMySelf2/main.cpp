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
	std::cout << "���� ������ ó���մϴ�." << value << std::endl;
}

void WhoAmI(float value)
{
	std::cout << "���� �Ҽ��� ó���մϴ�." << value << std::endl;
}

void WhoAmI(float value1, float value2)
{
	std::cout << "���� �Ҽ��� 2�� ó���մϴ�." << value1 << ", " << value2 << std::endl;
}

