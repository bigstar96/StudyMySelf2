#include <iostream>

void while1()
{
	bool whatelse{ true };
	int count{ 0 };

	while (whatelse)
	{
		if (count > 100)
		{
			whatelse = false;
			std::cout << count << std::endl;
		}
		else
		{
			count++;
		}
	}
}

void for1()
{
	int i = 1;
	for (;;)
	{
		if (i > 10)
			break;
		std::cout << i++ << std::endl;
	}

	for (int i = 1; i <= 10; ++i)
	{
		if (i % 2 == 0)
			continue;
		std::cout << i << std::endl;
	}

	for (int i = 1; i <= 10; i = i + 2)
	{
		std::cout << i << std::endl;
	}
}

void for2()
{
	// 최초의 프로그램을 for구문으로 표현
	for (int count = 0; count < 100; ++count)
	{
		std::cout << count << "\t" << count * count << std::endl;
	}

	std::cout << std::endl;
}

void for3()
{
	// for 문 고급
	for (int i = 0, j = 1; i < 10; i += 2, j = i + 1)
	{
		std::cout << i << ", " << j << std::endl;
	}
}

int main()
{
	

	return 0;
}
