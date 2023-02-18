#pragma once
#include <iostream>

const int STACK_SIZE{ 10 };

enum CommandStack
{
	PUSH = 1,
	POP = 2,
	EXIT = 3
};

struct Stack
{
	int container[STACK_SIZE]{};
	int topIndex = -1;
};

void PrintInfoStack();
void PrintStack(Stack& stack);
void Push(Stack& stack);
void Pop(Stack& stack);
void ProcessUserInput(Stack& stack);
