#include <iostream>

void OddEvenNumber()
{
	int number{};

	std::cout << "숫자를 입력하세요 : ";
	std::cin >> number;

	std::cout << "입력하신 " << number << "은(는)";
	if (number % 2)
	{
		std::cout << "홀수 입니다.";
	}
	else
	{
		std::cout << "짝수 입니다.";
	}
}

void Dollar()
{
	const int USDTOWON = 1260;
	int dollar{};

	std::cout << "USD를 입력하세요 : ";
	std::cin >> dollar;

	std::cout << dollar << " USD는 ";
	std::cout << dollar * USDTOWON << "원 입니다.";
}

void YenOrDollar()
{
	const int USDTOWON = 1260;
	const int JPYTOWON = 954;

	int money{};
	char kind;

	std::cout << "달러(S)화 혹은 엔(Y)화를 입력하세요 : ";
	std::cin >> money >> kind;

	if (kind == 'S' || kind == 's')
	{
		std::cout << money << " USD는 ";
		std::cout << money * USDTOWON << "원 입니다.";
	}
	else if (kind == 'Y' || kind == 'y')
	{
		std::cout << money << " JPY는 ";
		std::cout << money * JPYTOWON << "원 입니다.";
	}
}

int main()
{
	YenOrDollar();
}
