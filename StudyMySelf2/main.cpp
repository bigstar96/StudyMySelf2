#include <iostream>

bool Succes{ true };
const int succes[3][3]{
		{ 0, 0, 1 },
		{ 0, 0, 2 },
		{ 0, 0, 3 }
};


void PrintInfo(int hanoi[3][3])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			std::cout << hanoi[i][j] << "\t";
		}
		std::cout << std::endl;
	}
	return;
}

void Move(int hanoi[3][3], int move1, int move2)
{
	for (int i = 0; i < 3; ++i)
	{
		if (hanoi[i][move1] != 0)
		{
			for (int j = 0; j < 3; j++)
			{
				if (hanoi[j][move2] != 0)
				{
					if (hanoi[i][move1] < hanoi[j][move2])
					{
						hanoi[j - 1][move2] = hanoi[i][move1];
						hanoi[i][move1] = 0;
						return;
					}
					else
					{
						std::cout << "큰수를 작은수 위에 올릴수 없습니다." << std::endl;
						return;
					}
				}
				else if (hanoi[0][move2] == 0 &&
					hanoi[1][move2] == 0 &&
					hanoi[2][move2] == 0)
				{
					hanoi[2][move2] = hanoi[i][move1];
					hanoi[i][move1] = 0;
					return;
				}
			}
		}
	}
}

void Hanoi(int hanoi[3][3])
{
	int move1{ 0 }, move2{ 0 };

	while (Succes)
	{
		PrintInfo(hanoi);
		if (hanoi == succes)
		{
			std::cout << "정답입니다." << std::endl;
			return;
		}

		std::cout << "어떻게 움직일까요? ";
		std::cin >> move1 >> move2;

		if (move1 == move2)
		{
			std::cout << "같은 곳에는 움직일수 없습니다." << std::endl;
			continue;
		}
		else if (move1 < 0 || 3 < move1 ||
			move2 < 0 || 3 < move2 ||
			move1 == 0 || move2 == 0)
		{
			std::cout << "입력하신 숫자가 1~3 이 아닙니다." << std::endl;
			continue;
		}


		Move(hanoi, move1 - 1, move2 - 1);

		if (hanoi[0][2] == succes[0][2] &&
			hanoi[0][1] == succes[0][1] &&
			hanoi[0][0] == succes[0][0])
		{
			PrintInfo(hanoi);
			std::cout << "정답입니다!" << std::endl;
			Succes = false;
		}
	}
}

int main()
{
	int hanoi[3][3]{
		{ 1, 0, 0 },
		{ 2, 0, 0 },
		{ 3, 0, 0 }
	};

	Hanoi(hanoi);

	return 0;
}