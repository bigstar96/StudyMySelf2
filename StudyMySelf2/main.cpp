#include <iostream>

// ������ ���� ����� ���͸� ����� ���ô�.
// Ÿ�� { Wolf, Demon, Slime }
// �̸� ���ڿ�
// HP ����
// �� �����ͷ� Ȳõ����( HP 10 ), ��ť���� ( HP 100 )�� �ν��Ͻ�ȭ�ϰ� �ش� ������ ����ϴ� �Լ��� ����� ���ô�.

struct Monster
{
	int HP = 10;
	int MP = 0;
	std::string name;
}; 

Monster Wolf{ 10, 0, "Wolf" };
Monster Demon{ 100, 10, "Demon" };

void NAME(Monster m)
{
	int num{ 1 };
	
	for (int i = 0; i < num; ++i)
	{
		if (m.name[i] != '\0')
		{
			++num;
		}
		else
		{
			break;
		}
	}

	for (int i = 0; i < num; ++i)
	{
		std::cout << m.name[i];
	}
}

void Print(Monster m)
{
	std::cout << m.name << std::endl;
	std::cout << std::endl;
	std::cout << "HP - " << m.HP << std::endl;
	std::cout << "MP - " << m.MP << std::endl;
}

int main()
{
	Print(Wolf);
	Print(Demon);
}