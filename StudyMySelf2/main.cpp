#include <iostream>



int main()
{
	std::string previous = " ";
	std::string current;
	int index{ 1 };

	while (std::cin >> current)
	{
		if (previous == current)
		{
			std::cout << index << "��° �ܾ� " << current << "��(��) �ݺ��Ǿ����ϴ�." << std::endl;
			index = 1;
		}
		else
		{
			++index;
		}

		previous = current;
	}

	return 0;
}
