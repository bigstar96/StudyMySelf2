#include <iostream>

void ForLoop(int n)
{
	if (n < 0)
	{
		std::cout << std::endl;
		return;
	}

	ForLoop(n - 1);
	std::cout << n << ",";
	
}

int main()
{
	ForLoop(9);
}