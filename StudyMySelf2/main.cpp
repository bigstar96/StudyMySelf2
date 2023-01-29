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

	std::cout << "<하노이의 탑>" << std::endl;
	std::cout << "1. 한번에 하나의 원판만 옮길 수 있다." << std::endl;
	std::cout << "2. 큰 원판이 작은 원판 위에 있어서는 안된다." << std::endl;
	std::cout << "------------------------------" << std::endl;
	std::cout << "원판의 갯수를 입려하세요 : ";
	std::cin >> n;

	return n;
}

void Move(int n, char from, char to)
{
	std::cout << from << "에서 " << to << "로 원반" << n << "을 옮깁니다." << std::endl;
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
