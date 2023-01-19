#include <iostream>

char ConvertToUpperCase(char input);

int main()
{
	char buffer[50] = "Hello wolrd";
	for (int i = 0; i < 50; ++i)
	{
		std::cout << ConvertToUpperCase(buffer[i]);
	}
}

char ConvertToUpperCase(char input)
{
	if (input >= 'a' && input <= 'z')
	{
		return input - 'a' + 'A';
	}
	else
	{
		return input;
	}
}