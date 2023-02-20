#include "MySelfCreatMonster.h"

void MySelfMonsterInfo()
{
	std::cout << "  <MONSTER>" << std::endl;
	std::cout << " [1] Create" << std::endl;
	std::cout << " [2] Delete" << std::endl;
	std::cout << " [3] Exit" << std::endl;
	std::cout << "------------" << std::endl;
}

MyMonster* MySelfCreatMonster(MyMonsterList& list)
{

	MyMonster* pNew = new MyMonster;

	std::string name;
	std::cout << "������ �̸��� �Է��ϼ��� : ";
	std::cin >> name;

	char* cstyleName = new char[name.size() + 1];
	strcpy_s(cstyleName, name.size() + 1, name.c_str());
	strcpy_s(pNew->name, NAME_LENGTH, cstyleName);
	delete cstyleName;
	cstyleName = nullptr;

	int hp = (rand() % 10 + 1) * 100;
	pNew->hp = hp;
	pNew->pNext = nullptr;

	if (list.pTail == nullptr)
	{
		list.pHead = pNew;
		list.pTail = pNew;
	}
	else
	{
		list.pTail->pNext = pNew;
		list.pTail = pNew;
	}

	return pNew;
}

void MySelfPrintMonster(const MyMonsterList& list)
{
	MyMonster* p = list.pHead;

	if (list.pHead == nullptr && list.pTail == nullptr)
	{
		std::cout << "Non" << std::endl;
		return;
	}

	while (p != nullptr)
	{
		std::cout << "Name : " << p->name << "\t" << "HP : " << p->hp << std::endl;
		p = p->pNext;
	}
}

void HowManyCreatMonster(MyMonsterList& list)
{
	int num{};
	std::cout << "�� ������ ���͸� �����ұ��? : ";
	std::cin >> num;
	for (int i = 0; i < num; ++i)
	{
		MySelfCreatMonster(list);
	}
}

char* MySelfFindMonster(MyMonsterList& list)
{
	char name[NAME_LENGTH];
	std::cout << "ã�� ������ �̸��� �����ּ��� : ";
	std::cin >> name;

	MyMonster* p = list.pHead;
	for (; p != nullptr; p = p->pNext)
	{
		if (p->name == name)
		{
			break;
		}
	}

	return p->name;
}

bool MySelfDeleteMonster(MyMonsterList& list)
{
	MyMonster* pCurrent = list.pHead;
	MyMonster* pPrevious{};

	while (pCurrent != nullptr)
	{
		if (strcmp(pCurrent->name, MySelfFindMonster(list)) == 0)
		{
			break;
		}
		pPrevious = pCurrent;
		pCurrent = pCurrent->pNext;
	}

	if (pCurrent == nullptr)
	{
		return false;
	}

	if (list.pHead == list.pTail)
	{
		// ���� �ϳ��� ���� ��
		list.pHead = list.pTail = nullptr;
	}
	else if (list.pHead == pCurrent)
	{
		// ù��° ����
		list.pHead = pCurrent->pNext;
	}
	else if (list.pTail == pCurrent)
	{
		// ������ ����
		list.pTail = pPrevious;
		pPrevious->pNext = nullptr;
	}
	else
	{
		// �߰��� ���� ��
		pPrevious->pNext = pCurrent->pNext;
	}
	delete pCurrent;

	return true;
}

void MySelfDeleteAll(MyMonsterList& list)
{
	MyMonster* p = list.pHead;
	MyMonster* pNext{};
	while (p != nullptr)
	{
		pNext = p;
		delete p;
		p = pNext;
	}
	list.pHead = nullptr;
	list.pTail = nullptr;
}

enum Comd
{
	Single = 1,
	All = 2
};

void MySelfMonsterProcessUserInput(MyMonsterList& list)
{
	int command{ -1 }, comd{ -1 };

	while (true)
	{
		MySelfMonsterInfo();
		MySelfPrintMonster(list);
		std::cout << std::endl;
		std::cout << " > ";
		std::cin >> command;

		switch (command)
		{
			case Create:
				HowManyCreatMonster(list);
				break;

			case Delete:
				std::cout << "<Delete>" << std::endl;
				std::cout << "[1]Single" << std::endl;
				std::cout << "[2]All" << std::endl;
				std::cout << "[3]Back" << std::endl;
				std::cout << "\t > ";
				std::cin >> comd;

				switch (comd)
				{
					case Single:
						MySelfDeleteMonster(list);
						break;

					case All:
						MySelfDeleteAll(list);
						break;

					default:
						break;
				}
				break;

			case Exit:
				std::cout << "���α׷��� �����մϴ�." << std::endl;
				return;

			default:
				std::cout << "�߸� �Է��ϼ̽��ϴ�." << std::endl;
				if (command == 0)
				{
					std::cout << "������ ��� �ý����� �����մϴ�.";
					return;
				}
				break;
		}
	}
}
