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
// std::vector<int>
#include <algorithm>

#include <array>
// std::array<int, 3>
#include <forward_list>
// std::forward_list<int>
#include <list>
// std::list<int>
#include <deque>
// std::deque<int>
#include <stack>
// std::stack<int>
#include <queue>
// std::queue<int>

int main()
{
	std::vector<int> v1{ 1,2,3 };
	std::for_each(v1.begin(), v1.end(), [](const int& val) {std::cout << val << " "; });
	std::cout << std::endl;
	std::cout << std::endl;


	std::array<int, 4> intArray = { 0,1,2,3 };
	for (auto value : intArray)
	{
		std::cout << value << " ";
	}
	std::cout << std::endl;
	for (auto iter = intArray.begin(); iter != intArray.end(); ++iter)
	{
		std::cout << *iter << " ";
	}
	std::cout << std::endl;
	for (int i = 0; i < intArray.size(); ++i)
	{
		std::cout << intArray[i] << " ";
	}
	std::cout << std::endl;

	v1.push_back(4);
	for (auto value : v1)
	{
		std::cout << value << " ";
	}
	std::cout << std::endl;
	v1.pop_back();
	for (auto value : v1)
	{
		std::cout << value << " ";
	}
	std::cout << std::endl;
	v1.resize(5, 0);
	for (auto value : v1)
	{
		std::cout << value << " ";
	}
	std::cout << std::endl;
	v1.erase(v1.begin());
	for (auto value : v1)
	{
		std::cout << value << " ";
	}
	std::cout << std::endl;
	v1.clear();
	for (auto value : v1)
	{
		std::cout << value << " ";
	}
	std::cout << std::endl;
	std::cout << std::endl;


	// �ν��Ͻ�ȭ�� ���ؼ� ������ Ÿ���� �����մϴ�.
	std::forward_list<int> list{ 10,11,20,21 };
	// find()�� �־��� �ݺ��� �ȿ��� ���� ã�� �ݺ��ڸ� ��ȯ�մϴ�.
	auto itr = std::find(list.begin(), list.end(), 11);
	// insert_after ����Լ��� �־��� �ݺ��� �ڿ� ���� �����ϰ�, �ش� �ݺ��ڸ� ��ȯ�մϴ�.
	itr = list.insert_after(itr, 12);
	// splice_after(itr, list) ��� �Լ��� �־��� �ݺ��� �ڿ� list�� �Ű� ���Դϴ�. list�� ��� ������ϴ�.
	// list { 10,11,12,10,11,20,21 } , list2 {}
	std::forward_list<int> list2{ 10,11 };
	list.splice_after(itr, list2);
	// list�� �����մϴ�.
	list.sort();
	// unique()��� �Լ��� �ߺ��Ǵ� ���� ��� �����մϴ�. ���ٽ��� ������ �Ǵ��ϱ� ���� ��/�����Դϴ�.
	// ��, �� �񱳴� �յ� ���Ҹ� ���ϱ� ������ ���ĵ��� �Ǿ� �־�߸� ���� �۵��մϴ�.
	list.unique([](int a, int b) {return a == b; });
	// �ݺ��� ���� ���Ҹ� ����ϴ�.
	list.erase_after(list.begin());
	// ���� ��������
	list.sort(std::less<int>());
	// ���� ��������
	list.sort(std::greater<int>());

	
	// �ν��Ͻ�ȭ�� ���ؼ��� ������ Ÿ���� �����մϴ�.
	std::list<int> List{ 1,2,3 };
	// �������� �����մϴ�.
	List.reverse();
	std::list<int> List2{ 4,5,6 };
	// List�� �����մϴ�.
	List.sort();
	// �Ű������� ����Ʈ�� ��� �Űܼ� �ϳ��� ���մϴ�. **��! �� ����Ʈ ��� �Ȱ��� ���ĵǾ� �־�� �մϴ�.
	// (�ȵǾ������� ��Ÿ�ӿ��� �߻�)
	List2.merge(List);


	std::deque<int> deque{ 3,4,5 };
	// push_front() : �տ� ���� �߰��մϴ�.
	deque.push_front(1);
	// push_back() : �ڿ� ���� �߰��մϴ�.
	deque.push_back(6);
	// pop_front() : �տ� ���� �����մϴ�.
	deque.pop_front();
	// pop_back() : �ڿ� ���� �����մϴ�.
	deque.pop_back();


	std::stack<int> stack;
	// ���� �߰��ϱ� ���ؼ��� push�� ��밡���մϴ�.
	stack.push(1);	// { 1 }
	stack.push(2);	// { 2, 1 }
	stack.push(3);	// { 3, 2, 1 }
	// ���� �����ϱ� ���ؼ��� pop�� ��밡���մϴ�.
	stack.pop();

	std::stack<int> tempStack(stack);
	while (!tempStack.empty())
	{
		std::cout << tempStack.top() << " ";
		tempStack.pop();
	}

	
	std::queue<int> queue;
	// ���� �߰��ϱ� ���ؼ��� push�� ����� �� �ֽ��ϴ�.
	queue.push(1);	// { 1 }
	queue.push(2);	// { 1, 2 }
	queue.push(3);	// { 1, 2, 3 }
	// ���� �����ϱ� ���ؼ��� pop�� ��� �����մϴ�.
	queue.pop();	// { 2, 3 }
	
	std::queue<int> tempQueue(queue);
	while (!tempQueue.empty())
	{
		std::cout << tempQueue.front() << " ";
		tempQueue.pop();
	}


	return 0;
}