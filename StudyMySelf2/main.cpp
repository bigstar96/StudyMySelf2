#include <iostream>


int main()
{
	std::cout << "C++�� ��Ʈ �����ڸ� �Է��ϼ���.";
	char inputOperator;
	std::cin >> inputOperator;

	switch (inputOperator)
	{
	case '!':
		std::cout << "���� ������";
		break;

	case '&':
	case '|':
	case '^':
		std::cout << "���� ������";
		break;

	default:
		std::cout << "��Ʈ �����ڰ� �ƴմϴ�.";
		break;
	}
}
