#pragma once
#include <iostream>

const int QUEUE_SIZE{ 10 };

enum CommandQueue
{
	ENQUEUE = 1,
	DEQUEUE = 2,
	EXIT = 3
};

struct Queue
{
	int container[QUEUE_SIZE]{};
	int head = 0;
	int tail = 0;
};

void Queue_PrintInfo();
void Queue_Print(Queue& queue);
void Queue_Enqueue(Queue& queue);
void Queue_Dequeue(Queue& queue);
void Queue_ProcessUserInput(Queue& queue);
