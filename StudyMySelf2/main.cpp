#include <iostream>

void Subway()
{
	int age;
	int payment;
	int distance;
	std::cout << "나이를 입력하세요 : ";
	std::cin >> age;
	std::cout << "결제 수단을 입력하세요 { 0 : 교통카드, 1 : 일반(현금) }";
	std::cin >> payment;
	std::cout << "거리를 입력하세요 : ";
	std::cin >> distance;

	if (payment == 0)
	{
		if (distance < 10)
		{
			if (age < 6)
			{
				std::cout << "무료";
			}
			else if (age >= 6 && age < 13)
			{
				std::cout << "450원";
			}
			else if (age >= 13 && age < 18)
			{
				std::cout << "720원";
			}
			else
			{
				std::cout << "1,250원";
			}
		}

		else if (distance < 15)
		{
			if (age < 6)
			{
				std::cout << "무료";
			}
			else if (age >= 6 && age < 13)
			{
				std::cout << "500원";
			}
			else if (age >= 13 && age < 18)
			{
				std::cout << "800원";
			}
			else
			{
				std::cout << "1,350원";
			}
		}

		else if (distance < 20)
		{
			if (age < 6)
			{
				std::cout << "무료";
			}
			else if (age >= 6 && age < 13)
			{
				std::cout << "550원";
			}
			else if (age >= 13 && age < 18)
			{
				std::cout << "880원";
			}
			else
			{
				std::cout << "1,450원";
			}
		}
		else
		{
			std::cout << "잘못된 거리입니다.";
		}
	}
	else if (payment == 1)
	{
		if (distance < 10)
		{
			if (age < 6)
			{
				std::cout << "무료";
			}
			else if (age < 13)
			{
				std::cout << "450원";
			}
			else if (age >= 13)
			{
				std::cout << "1,350원";
			}
			else
			{
				std::cout << "잘못 입력하셨습니다.";
			}

		}

		else if (distance < 15)
		{
			if (age < 6)
			{
				std::cout << "무료";
			}
			else if (age < 13)
			{
				std::cout << "500원";
			}
			else if (age >= 13)
			{
				std::cout << "1,450원";
			}
			else
			{
				std::cout << "잘못 입력하셨습니다.";
			}

		}

		else if (distance < 20)
		{
			if (age < 6)
			{
				std::cout << "무료";
			}
			else if (age < 13)
			{
				std::cout << "550원";
			}
			else if (age >= 13)
			{
				std::cout << "1,550원";
			}
			else
			{
				std::cout << "잘못 입력하셨습니다.";
			}
		}
		else
		{
			std::cout << "잘못된 거리입니다.";
		}
	}
	else
	{
		std::cout << "잘못된 결제 수단입니다.";
	}
}

int main()
{
	Subway();
}
