#include <iostream>


int main()
{
	const int USDTOWON = 1240;
	const float YENTOWON = 9.46f;
	const float EUROTOWON = 1340.85f;
	const float POUNDTOWON = 1518.07f;
	int money{};
	char kind;

	std::cout << "달러(S)화, 엔(Y)화, 유로(E)화, 파운드(P)화를 입력하세요 : ";
	std::cin >> money >> kind;

	switch (kind)
	{
		case 'S': case 's':
			std::cout << money << " USD는 ";
			std::cout << money * USDTOWON << "원 입니다.";
			break;

		case 'Y': case 'y':
			std::cout << money << " JPY는 ";
			std::cout << money * YENTOWON << "원 입니다.";
			break;

		case 'E': case 'e':
			std::cout << money << " EUR는 ";
			std::cout << money * EUROTOWON << "원 입니다.";
			break;

		case 'P': case 'p':
			std::cout << money << " GBP는 ";
			std::cout << money * POUNDTOWON << "원 입니다.";
			break;

		default:
			std::cout << "알 수 없는 화폐 단위입니다.";
			break;
	}
	
}
