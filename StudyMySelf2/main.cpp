#include <iostream>
#include <ctime>

//���� �߱� ���� �����
void CreateAnswer();
void InputNumber();
bool CheckNumber();

int gResultArray[3]{};
int gInputArray[3]{};


int main()
{
	CreateAnswer();

	while (true)
	{
		InputNumber();
		if (CheckNumber())
		{
			break;
		}
	}

	return 0;
}

void CreateAnswer()
{
	int usedDigit[10]{ 0 };

	std::srand(std::time(nullptr));

	for (int i = 0; i < 3; ++i)
	{
		bool isDuplicated = true;
		int random_digit{};

		while (isDuplicated)
		{
			random_digit = std::rand() % 10;
			if (usedDigit[random_digit] == 0)
			{
				usedDigit[random_digit] = 1;
				break;
			}
		}
		gResultArray[i] = random_digit;

		// std::cout << random_digit;
	}
}

void InputNumber()
{
	char input[4]{};

	std::cout << "���ڸ� ���ڸ� �Է��ϼ��� : ";
	std::cin >> input;

	for (int i = 0; i < 3; ++i)
	{
		gInputArray[i] = input[i] - '0';
	}
}

bool CheckNumber()
{
	int ball{ 0 }, strike{ 0 };

	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			if (gInputArray[i] == gResultArray[j])
			{
				if (i == j)
				{
					strike++;
				}
				else
				{
					ball++;
				}
			}
		}
	}

	std::cout << strike << " ��Ʈ����ũ!, " << ball << " ��!" << std::endl;

	if (strike == 3)
	{
		std::cout << "�����Դϴ�!" << std::endl;
		return true;
	}

	return false;
}
