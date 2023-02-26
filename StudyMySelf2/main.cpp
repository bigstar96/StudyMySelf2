#include <iostream>
#include "ClassStack.h"


int main()
{
	ClassStack cs{};
	int command = -1;
	int num;
	while (true)
	{
		cs.Print();
		std::cout << "----------" << std::endl;
		std::cin >> command;
		switch (command)
		{
			case PUSH:
				std::cout << " > ";
				std::cin >> num;
				cs.Push(num);
				break;

			case POP:
				cs.Pop();
				break;

			case EXIT:
				return 0;
				break;

			default:

				break;
		}

	}

	return 0;
}


