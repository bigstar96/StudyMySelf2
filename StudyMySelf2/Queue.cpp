#include "Queue.h"

void PrintInfoQueue()
{
	std::cout << "[QUEUE]" << std::endl;
	std::cout << "[1] ENQUEUE" << std::endl;
	std::cout << "[2] DEQUEUE" << std::endl;
	std::cout << "[3] EXIT" << std::endl;
}


void PrintQueue(Queue& queue)
{
	std::cout << "-----------" << std::endl;

	if (queue.head == queue.tail)
	{
		std::cout << "	EMPTY	" << std::endl;
		std::cout << "-----------" << std::endl;
		return;
	}

	/*for (int i = queue.head; i != queue.tail; i = (i + 1) % QUEUE_SIZE)
	{
		std::cout << queue.container[i] << std::endl;
	}*/

	int i = queue.head;
	while (i != queue.tail)
	{
		i = (i + 1) % QUEUE_SIZE;
		std::cout << queue.container[i] << std::endl;
	}

	std::cout << "-----------" << std::endl;
}


void Enqueue(Queue& queue)
{
	if (queue.head == (queue.tail + 1) % QUEUE_SIZE)
	{
		std::cout << "- QUEUE IS FULL! -" << std::endl;
		return;
	}

	int num;

	std::cout << "	> ";
	std::cin >> num;

	queue.tail = (queue.tail + 1) % QUEUE_SIZE;
	queue.container[queue.tail] = num;
}


void Dequeue(Queue& queue)
{
	if (queue.head == queue.tail)
	{
		std::cout << "- NOT QUEUE -" << std::endl;
		return;
	}

	std::cout << "	DEQUEUE : " << queue.container[queue.head] << std::endl;
	queue.container[queue.head] = NULL;
	queue.head = (queue.head + 1) % QUEUE_SIZE;
}


void ProcessUserInputQueue(Queue& queue)
{
	int command = -1;

	while (true)
	{
		PrintInfoQueue();
		PrintQueue(queue);

		std::cout << std::endl;
		std::cout << " > ";
		std::cin >> command;

		switch (command)
		{
			case ENQUEUE:
				Enqueue(queue);
				break;

			case DEQUEUE:
				Dequeue(queue);
				break;

			case EXIT:
				std::cout << "프로그램을 끝냅니다." << std::endl;
				return;
				break;

			default:
				std::cout << "잘못 입력하셨습니다." << std::endl;
				break;
		}
	}
}

