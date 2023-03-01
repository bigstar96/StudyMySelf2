#include <iostream>
#include "ClassQueue.h"

enum Command
{
	ENQUEUE = 1,
	DEQUEUE = 2,
	EXIT = 3
};

int main()
{
	ClassQueue queue{};
	int command = -1;
	int num{};

	while (true)
	{
		queue.Print();
		std::cout << "> ";
		std::cin >> command;
		switch (command)
		{
			case ENQUEUE:
				std::cout << " > ";
				std::cin >> num;
				queue.Enqueue(num);
				break;

			case DEQUEUE:
				queue.Dequeue();
				break;

			case EXIT:
				return 0;
				break;

			default:
				std::cout << "NO" << std::endl;
				break;
		}
	}

}


