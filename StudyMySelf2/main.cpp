#include <iostream>

void Subway()
{
	int age;
	int payment;
	int distance;
	std::cout << "���̸� �Է��ϼ��� : ";
	std::cin >> age;
	std::cout << "���� ������ �Է��ϼ��� { 0 : ����ī��, 1 : �Ϲ�(����) }";
	std::cin >> payment;
	std::cout << "�Ÿ��� �Է��ϼ��� : ";
	std::cin >> distance;

	if (payment == 0)
	{
		if (distance < 10)
		{
			if (age < 6)
			{
				std::cout << "����";
			}
			else if (age >= 6 && age < 13)
			{
				std::cout << "450��";
			}
			else if (age >= 13 && age < 18)
			{
				std::cout << "720��";
			}
			else
			{
				std::cout << "1,250��";
			}
		}

		else if (distance < 15)
		{
			if (age < 6)
			{
				std::cout << "����";
			}
			else if (age >= 6 && age < 13)
			{
				std::cout << "500��";
			}
			else if (age >= 13 && age < 18)
			{
				std::cout << "800��";
			}
			else
			{
				std::cout << "1,350��";
			}
		}

		else if (distance < 20)
		{
			if (age < 6)
			{
				std::cout << "����";
			}
			else if (age >= 6 && age < 13)
			{
				std::cout << "550��";
			}
			else if (age >= 13 && age < 18)
			{
				std::cout << "880��";
			}
			else
			{
				std::cout << "1,450��";
			}
		}
		else
		{
			std::cout << "�߸��� �Ÿ��Դϴ�.";
		}
	}
	else if (payment == 1)
	{
		if (distance < 10)
		{
			if (age < 6)
			{
				std::cout << "����";
			}
			else if (age < 13)
			{
				std::cout << "450��";
			}
			else if (age >= 13)
			{
				std::cout << "1,350��";
			}
			else
			{
				std::cout << "�߸� �Է��ϼ̽��ϴ�.";
			}

		}

		else if (distance < 15)
		{
			if (age < 6)
			{
				std::cout << "����";
			}
			else if (age < 13)
			{
				std::cout << "500��";
			}
			else if (age >= 13)
			{
				std::cout << "1,450��";
			}
			else
			{
				std::cout << "�߸� �Է��ϼ̽��ϴ�.";
			}

		}

		else if (distance < 20)
		{
			if (age < 6)
			{
				std::cout << "����";
			}
			else if (age < 13)
			{
				std::cout << "550��";
			}
			else if (age >= 13)
			{
				std::cout << "1,550��";
			}
			else
			{
				std::cout << "�߸� �Է��ϼ̽��ϴ�.";
			}
		}
		else
		{
			std::cout << "�߸��� �Ÿ��Դϴ�.";
		}
	}
	else
	{
		std::cout << "�߸��� ���� �����Դϴ�.";
	}
}

int main()
{
	Subway();
}
