#include <iostream>



int main()
{
	std::cout << "이름과 나이를 입력하고 엔터를 누르세요" << std::endl;

	std::string name;
	int age;

	std::cin >> name >> age;

	std::cout << "hello, " << name << "(" << age << ")" << std::endl;
}
