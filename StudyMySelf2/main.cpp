#include <iostream>

// 문자열은 Null 문자로 종료되는 배열
// 배열은 포인터
// 포인터 연산 가능

int GetLength(char* pc)
{
	int count{};

	while (*pc != '\0')
	{
		count++;
		pc++;
	}

	return count;
}

int main()
{
	char input[1000];

	std::cin >> input;

	std::cout << input << " : " << GetLength(input) << std::endl;
}