#include <iostream>

int InputFromUser();
void Move(char from, char to);
void Hanoi(int n, char from, char temp, char to);


int main()
{
	int n = InputFromUser();

	Hanoi(n, 'A', 'B', 'C');
}

int InputFromUser()
{
	int n{};

	std::cout << "<�ϳ����� ž>" << std::endl;
	std::cout << "1. �ѹ��� �ϳ��� ���Ǹ� �ű� �� �ִ�." << std::endl;
	std::cout << "2. ū ������ ���� ���� ���� �־�� �ȵȴ�." << std::endl;
	std::cout << "------------------------------" << std::endl;
	std::cout << "������ ������ �Է��ϼ��� : ";
	std::cin >> n;

	return n;
}

void Move(int n, char from, char to)
{
	std::cout << from << "���� " << to << "�� ����" << n << "�� �ű�ϴ�." << std::endl;
}

void Hanoi(int n, char from, char temp, char to)
{
	if (n == 1)
	{
		Move(n, from, to);
	}
	else
	{
		Hanoi(n - 1, from, to, temp);
		Move(n, from, to);
		Hanoi(n - 1, temp, from, to);
	}
}
