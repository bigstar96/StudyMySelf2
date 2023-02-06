#include <iostream>



int main()
{
	char c[6];
	char* pc;

	c[0] = 'd';
	c[1] = 'o';
	c[2] = 'g';
	c[3] = 'g';
	c[4] = 'y';
	std::cout << c << std::endl;


	pc = &c[0];
	std::cout << pc << std::endl;


	char myString[] = "Doggy";
	char* p = myString;
	std::cout << p << std::endl;


	int myInteger = 5;
	char myString1[] = { " is integer value" };
	std::cout << myString1 + myInteger << std::endl;

	// 한글과 컴퓨터

	int myInteger2 = 5;
	wchar_t myString2[] = { L"는 정수입니다." };
	std::locale myLocale("kor");
	std::wcout.imbue(myLocale);
	std::wcout << myString2 + myInteger2 << std::endl;
}