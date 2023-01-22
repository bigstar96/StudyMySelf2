#include <iostream>

// 다음과 같이 설계된 몬스터를 만들어 봅시다.
// 타입 { Wolf, Demon, Slime }
// 이름 문자열
// HP 정수
// 위 데이터로 황천늑대( HP 10 ), 서큐버스 ( HP 100 )를 인스턴스화하고 해당 정보를 출력하는 함수를 만들어 봅시다.

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