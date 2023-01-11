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
			std::cout << index << "번째 단어 " << current << "이(가) 반복되었습니다." << std::endl;
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
