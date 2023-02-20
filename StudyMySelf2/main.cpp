#include <iostream>
#include "LinkedList.h"


int main()
{
	/*MonsterList myList{};

	CreatMonster(myList, "Wolf", 10);
	CreatMonster(myList, "Slime", 20);
	CreatMonster(myList, "Demon", 30);
	
	std::cout << GetCountMonsterList(myList) << std::endl;
	std::cout << std::endl;
	PrintMonsterList(myList);
	std::cout << std::endl;
	PrintListRecursive(myList.pHead);
	std::cout << std::endl;

	std::cout << ((FindMonster(myList, "Slime") == nullptr)) << std::endl;
	std::cout << std::endl;

	MonsterDelete(myList, "Slime");
	std::cout << std::endl;
	PrintMonsterList(myList);
	std::cout << std::endl;
	std::cout << std::endl;

	DeleteAllMonster(myList);
	PrintMonsterList(myList);
	std::cout << std::endl;*/


	MyMonsterList myMonster{};

	MySelfMonsterProcessUserInput(myMonster);

	return 0;
}