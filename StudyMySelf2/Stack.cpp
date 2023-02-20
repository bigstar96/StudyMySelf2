#include "Stack.h"


void Stack_PrintInfo()
{
	std::cout << "<STACK>" << std::endl;
	std::cout << "[1] PUSH" << std::endl;
	std::cout << "[2] POP" << std::endl;
	std::cout << "[3] EIXT" << std::endl;
}


void Stack_PrintStack(Stack& stack)
{
	std::cout << "----------" << std::endl;

	for (int i = stack.topIndex; i > -1; --i)
	{
		std::cout << i + 1 << ". " << stack.container[i] << std::endl;
	}

	std::cout << "----------" << std::endl;
}

void Stack_Push(Stack& stack)
{
	if (stack.topIndex == STACK_SIZE - 1)
	{
		std::cout << "더 이상 PUSH를 할 수 없습니다." << std::endl;
		return;
	}
	int num{};
	std::cout << "	> push value : ";
	std::cin >> num;

	stack.topIndex++;
	stack.container[stack.topIndex] = num;
}

void Stack_Pop(Stack& stack)
{
	if (stack.topIndex == -1)
	{
		std::cout << "더 이상 POP을 할 수 없습니다." << std::endl;
		return;
	}
	std::cout << stack.container[stack.topIndex] << " POP!" << std::endl;

	stack.container[stack.topIndex] = NULL;
	stack.topIndex--;
}

void Stack_ProcessUserInput(Stack& stack)
{
	int command = -1;

	while (true)
	{
		Stack_PrintInfo();
		Stack_PrintStack(stack);

		std::cout << std::endl;
		std::cout << "> ";
		std::cin >> command;
		switch (command)
		{
			case PUSH:
				Stack_Push(stack);
				break;

			case POP:
				Stack_Pop(stack);
				break;

			case EXIT:
				return;
				break;

			default:
				std::cout << "잘못 입력하셨습니다." << std::endl;
				break;
		}
	}
}

//int main()
//{
//	Stack myStack;
//
//	ProcessUserInput(myStack);
//
//	return 0;
//}