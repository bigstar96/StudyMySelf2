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


int main()
{
	std::vector<int> v1{ 2,3,1,5,6 };
	std::vector<std::string> names{ "doggy","kitty","bunny","piggy" };
	std::vector<int> v2(5);

	// std::cout << v1[0];

	std::vector<int> v3{ 2,3,1,5,6 };
	for (int i = 0; i < v3.size(); ++i)
	{
		std::cout << v3[i] << " ";
	}
	std::cout << std::endl;

	for (int x : v3)
	{
		std::cout << x << " ";
	}
	std::cout << std::endl;

	for (std::string name : names)
	{
		std::cout << name << " ";
	}

	/*std::vector<int> v4{};
	std::cout << "���ڸ� �������� �����Ͽ� �Է��ϼ���!" << std::endl;
	std::cout << "�Է� ����� ���ڰ� �ƴ� ���ڸ� �Է��Ͻø� �˴ϴ�." << std::endl;

	for (int value; std::cin >> value;)
	{
		v4.push_back(value);
	}

	int sum{};
	for (int element : v4)
	{
		sum += element;
	}

	float average = static_cast<float>(sum) / v4.size();

	std::cout << "�� : " << sum << std::endl;
	std::cout << "��� : " << average << std::endl;*/

	std::vector<int> v5{ 1,2,3 };
	std::vector<int>::iterator itr1 = v5.begin();

	while (itr1 != v5.end())
	{
		std::cout << *itr1;
		itr1++;
	}
	for (std::vector<int>::iterator itr2 = v5.begin(); itr2 != v5.end(); ++itr2)
	{
		std::cout << *itr2;
	}


	return 0;
}