#include <iostream>

// ���� a�� b�� ���� ���� ���ϴ� �Լ��� �������� ���ϴ� �Լ��� ����� ���ô�.
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
	std::cout << "�� : " << Quotient(a, b) << std::endl;
	std::cout << "������ : " << Remainder(a, b) << std::endl;
}