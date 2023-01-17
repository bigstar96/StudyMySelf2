#include <iostream>

void GuGuDan(int dan)
{
	std::cout << "---" << dan << "´Ü---" << std::endl;

	for (int i = 1; i <= 9; ++i)
	{
		std::cout << dan << " x " << i << " = " << dan * i << std::endl;
	}
}

int main()
{
	for (int i = 1; i <= 9; ++i)
	{
		GuGuDan(i);
	}

}