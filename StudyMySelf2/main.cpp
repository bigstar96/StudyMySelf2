#include <iostream>

void OddEvenNumber()
{
	int number{};

	std::cout << "���ڸ� �Է��ϼ��� : ";
	std::cin >> number;

	std::cout << "�Է��Ͻ� " << number << "��(��)";
	if (number % 2)
	{
		std::cout << "Ȧ�� �Դϴ�.";
	}
	else
	{
		std::cout << "¦�� �Դϴ�.";
	}
}

void Dollar()
{
	const int USDTOWON = 1260;
	int dollar{};

	std::cout << "USD�� �Է��ϼ��� : ";
	std::cin >> dollar;

	std::cout << dollar << " USD�� ";
	std::cout << dollar * USDTOWON << "�� �Դϴ�.";
}

void YenOrDollar()
{
	const int USDTOWON = 1260;
	const int JPYTOWON = 954;

	int money{};
	char kind;

	std::cout << "�޷�(S)ȭ Ȥ�� ��(Y)ȭ�� �Է��ϼ��� : ";
	std::cin >> money >> kind;

	if (kind == 'S' || kind == 's')
	{
		std::cout << money << " USD�� ";
		std::cout << money * USDTOWON << "�� �Դϴ�.";
	}
	else if (kind == 'Y' || kind == 'y')
	{
		std::cout << money << " JPY�� ";
		std::cout << money * JPYTOWON << "�� �Դϴ�.";
	}
}

int main()
{
	YenOrDollar();
}
