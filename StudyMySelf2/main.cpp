#include <iostream>	



int main()
{
	int SizePeople{};
	std::cout << "�� ���� ģ���� �ֳ���? ";
	std::cin >> SizePeople;

	if (SizePeople <= 0)
	{
		std::cout << "�߸��� ũ���Դϴ�." << std::endl;
		return 0;
	}

	std::string* pName = new std::string[SizePeople];

	for (int i = 0; i < SizePeople; ++i)
	{
		std::cout << "ģ�� �̸� #" << i + 1 << " : ";
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
	
	std::cout << "�̸��� ���� �� ģ���� " << pName[num] << " �Դϴ�." << std::endl;


	delete[] pName;
}