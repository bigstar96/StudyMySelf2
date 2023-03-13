#include <iostream>

// STL : Standard Library
// Container - �ڷ� ������ ���� ���ø� Ŭ����, Stack, Queue, List ��� ���� ���Ҹ� �����ϴ� ���հ� ���� ����
// �ٸ� ���δ� �÷���(Collection)�̶�� ��.
// �� �����̳� ���� ������� �����Ƿ� Ư¡�� �� �����ϰ� ������ ���� ������ ������.

// Iterator - �����̳��� ���ҵ��� ��ȸ�ϱ� ���� �Ϲ�ȭ�� ����� �ݺ���(Iterator) ��� ��
// �ݺ��ڴ� �����̳� ���������� �ʱ� ������ �������� �и�/�����Ͽ� ����� ����.
// ������ ���� : ���Ҹ� ����Ŵ
// ���� ��ȸ : ++, !=, == ���� ������ ����
// ����, �� ���� : begin(), end()

// Algorithm - ���� ������ �� �ִ� ����, �˻�, ���� ���� �����ϱ� ����� ��ɱ��� ���� �ְ��� ���α׷��ӵ���
// �̸� �غ��ص� �˰��� ����. �����̳ʸ� �ٷ� �� �ִ� ���� ���ø� �Լ����� �������� �Ǿ��ְ�,
// �����̳ʿ� �и� �Ǿ� �־ ��� �����̳ʿ��� ������ �� �ִ� ������ ����.

#include <bitset>

int main()
{
	int myInt = 123;
	float myFloat = 3.141592f;
	bool myBool = true;

	std::cout << myBool << std::endl;
	std::cout << std::boolalpha << myBool << std::endl;

	std::cout << std::dec << myInt << std::endl;
	std::cout << std::hex << myInt << std::endl;
	std::cout << std::oct << myInt << std::endl;

	std::cout << std::bitset<8>(myInt).to_string() << std::endl;

	std::cout.precision(3);
	std::cout << myFloat << std::endl;

	std::cout.width(10);
	std::cout << myInt << std::endl;

	std::cout.fill('0');
	std::cout.width(10);
	std::cout << std::right << myInt << std::endl;
}