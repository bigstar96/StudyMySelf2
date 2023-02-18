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

void PrintInfoQueue();
void PrintQueue(Queue& queue);
void Enqueue(Queue& queue);
void Dequeue(Queue& queue);
void ProcessUserInputQueue(Queue& queue);
