#include <iostream>

void DoWhile()
{
	int i{ 1 }, j{ 0 };
	do
	{
		j = j + i;
		std::cout << i++ << " , " << j << std::endl;

	} while (i <= 10);
}

void While()
{
	int i{ 0 }, j{ 0 };

	while (i < 10)
	{
		++i;
		j += i;
		std::cout << i << " , " << j << std::endl;
	}
}

int main()
{
	// do while - 조건이 일치하지 않아도 한번은 실행
	DoWhile();

	// while - 조건이 맞지 않으면 한번도 실행하지 않음
	While();
}
