#include <iostream>	



int main()
{
	int SizePeople{};
	std::cout << "몇 명의 친구가 있나요? ";
	std::cin >> SizePeople;

	if (SizePeople <= 0)
	{
		std::cout << "잘못된 크기입니다." << std::endl;
		return 0;
	}

	std::string* pName = new std::string[SizePeople];

	for (int i = 0; i < SizePeople; ++i)
	{
		std::cout << "친구 이름 #" << i + 1 << " : ";
		std::cin >> pName[i];
	}

	int num{};
	int maxlen{};
	for (int i = 0; i < SizePeople; ++i)
	{
		if (pName[i].size() > maxlen)
		{
			maxlen = pName[i].size();
			num = i;
		}
	}
	
	std::cout << "이름이 가장 긴 친구는 " << pName[num] << " 입니다." << std::endl;


	delete[] pName;
}