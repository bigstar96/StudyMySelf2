#include <iostream>


int main()
{
	const int USDTOWON = 1240;
	const float YENTOWON = 9.46f;
	const float EUROTOWON = 1340.85f;
	const float POUNDTOWON = 1518.07f;
	int money{};
	char kind;

	std::cout << "�޷�(S)ȭ, ��(Y)ȭ, ����(E)ȭ, �Ŀ��(P)ȭ�� �Է��ϼ��� : ";
	std::cin >> money >> kind;

	switch (kind)
	{
		case 'S': case 's':
			std::cout << money << " USD�� ";
			std::cout << money * USDTOWON << "�� �Դϴ�.";
			break;

		case 'Y': case 'y':
			std::cout << money << " JPY�� ";
			std::cout << money * YENTOWON << "�� �Դϴ�.";
			break;

		case 'E': case 'e':
			std::cout << money << " EUR�� ";
			std::cout << money * EUROTOWON << "�� �Դϴ�.";
			break;

		case 'P': case 'p':
			std::cout << money << " GBP�� ";
			std::cout << money * POUNDTOWON << "�� �Դϴ�.";
			break;

		default:
			std::cout << "�� �� ���� ȭ�� �����Դϴ�.";
			break;
	}
	
}
