#include <iostream>

// 연습문제
// 1. 문자를 입력하여 출력하는 프로그램을 작성해 보세요.
//	a. 'z'를 입력해 보세요.
//	b. "abc"를 입력해 보세요.
//	c. 1234를 입력해 보세요.
// 2. 소수점을 입력하여 출력하는 프로그램을 작성해 보세요.
//	a. 1.1 형태로 입력해보세요. (일반형)
//	b. 1.1f 형태로 입력해 보세요.(부동소수점 리터럴)
// 3. bool 형식의 변수로 입력값을 가져와 출력해 보세요.
//	a. true / false 형태로 입력해 보세요.
//	b. 0, 1, 2, 3 형태로 입력해 보세요.
// 

void ccout()
{
	char c;
	std::cout << "문자를 입력하세요 : ";
	std::cin >> c;
	std::cout << "입력받은 문자는 " << c << " 입니다." << std::endl;
}

void fla()
{
	float f;
	std::cout << "소수점을 입력하세요 : ";
	std::cin >> f;
	std::cout << "입력받은 숫자는 " << f << " 입니다." << std::endl;
}

void boo()
{
	bool b;
	std::cout << "bool형식의 변수를 입력하세요 : ";
	std::cin >> b;
	std::cout << "입력받은 변수는 " << b << " 입니다.";
}

int main()
{
	ccout();
	fla();
	boo();
}
