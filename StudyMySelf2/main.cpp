#include <iostream>	

char ReadInput();
void PrintHeader();
void PrintTable(char start, char end);
char GetAsciiCharacter(int code);

int main()
{
	std::cout << "�ƽ�Ű ���� ����, ���� �Է��ϼ���!";
	char start{ ReadInput() }, end{ ReadInput()};

	PrintHeader();

	PrintTable(start, end);
}

char ReadInput()
{
	char ch;
	std::cin >> ch;
	return ch;
}

void PrintHeader()
{
	std::cout << std::endl;
	std::cout << "----- ASCII TABLE -----";
	std::cout << std::endl;
}

char GetAsciiCharacter(int code)
{
	return (char)(code);
}

void PrintTable(char start, char end)
{
	for (int ch = start; ch <= end; ++ch)
	{
		std::cout << ch << '\t' << GetAsciiCharacter(ch) << std::endl;
	}
}
