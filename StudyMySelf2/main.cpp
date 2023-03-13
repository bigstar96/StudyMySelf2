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

#include <vector>

#include <algorithm>

int IntCompare(const void* left, const void* right)
{
	int lhs = *static_cast<const int*> (left);
	int rhs = *static_cast<const int*> (right);

	/*if (lhs > rhs)
	{
		return -1;
	}
	else if (lhs < rhs)
	{
		return 1;
	}

	return 0;*/

	return rhs - lhs;
}

int main()
{
	std::vector<int> v1{ 1,2,3 };

	qsort(v1.data(), v1.size(), sizeof(v1[0]), IntCompare);

	for (int value1 : v1)
	{
		std::cout << value1 << " ";
	}
	std::cout << std::endl;

	std::vector<int> v2{ 4,3,1,5,2 };
	qsort(v2.data(), v2.size(), sizeof(v2[0]),
		[](const void* a, const void* b) { return *static_cast<const int*>(b) - *static_cast<const int*>(a); }
	);
	for (int value2 : v2)
	{
		std::cout << value2 << " ";
	}
	std::cout << std::endl;

	std::vector<int> v3{ 1,2,3,5,4 };
	std::for_each(v3.begin(), v3.end(), [](const int& val) {std::cout << val << " "; });

	return 0;
}