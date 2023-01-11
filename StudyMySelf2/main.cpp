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
	// do while - ������ ��ġ���� �ʾƵ� �ѹ��� ����
	DoWhile();

	// while - ������ ���� ������ �ѹ��� �������� ����
	While();
}
