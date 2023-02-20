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

void Stack_PrintInfo();
void Stack_PrintStack(Stack& stack);
void Stack_Push(Stack& stack);
void Stack_Pop(Stack& stack);
void Stack_ProcessUserInput(Stack& stack);
