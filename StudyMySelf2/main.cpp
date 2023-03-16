#include <iostream>

// STL : Standard Library
// Container - 자료 구조를 위한 템플릿 클래스, Stack, Queue, List 등과 같이 원소를 관리하는 집합과 같은 공간
// 다른 말로는 컬렉션(Collection)이라고도 함.
// 각 컨테이너 별로 장단점이 있으므로 특징을 잘 이해하고 있으면 높은 성능을 발휘함.

// Iterator - 컨테이너의 원소들을 순회하기 위한 일반화된 방법을 반복자(Iterator) 라고 함
// 반복자는 컨테이너 종속적이지 않기 때문에 언제든지 분리/결합하여 사용이 가능.
// 포인터 개념 : 원소를 가르킴
// 원소 순회 : ++, !=, == 등의 연산자 지원
// 시작, 끝 제공 : begin(), end()

// Algorithm - 쉽게 생각할 수 있는 정렬, 검색, 복사 부터 구현하기 어려운 기능까지 세계 최고의 프로그래머들이
// 미리 준비해둔 알고리즘 집합. 컨테이너를 다룰 수 있는 전역 템플릿 함수들의 집합으로 되어있고,
// 컨테이너와 분리 되어 있어서 모든 컨테이너에게 적용할 수 있는 장점이 있음.

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


	// 인스턴스화를 위해서 원소의 타입을 지정합니다.
	std::forward_list<int> list{ 10,11,20,21 };
	// find()는 주어진 반복자 안에서 값을 찾아 반복자를 반환합니다.
	auto itr = std::find(list.begin(), list.end(), 11);
	// insert_after 멤버함수는 주어진 반복자 뒤에 값을 삽입하고, 해당 반복자를 반환합니다.
	itr = list.insert_after(itr, 12);
	// splice_after(itr, list) 멤버 함수는 주어진 반복자 뒤에 list를 옮겨 붙입니다. list는 모두 비워집니다.
	// list { 10,11,12,10,11,20,21 } , list2 {}
	std::forward_list<int> list2{ 10,11 };
	list.splice_after(itr, list2);
	// list를 정렬합니다.
	list.sort();
	// unique()멤버 함수는 중복되는 값을 모두 제거합니다. 람다식은 같은지 판단하기 위한 참/거짓입니다.
	// 단, 이 비교는 앞뒤 원소만 비교하기 때문에 정렬등이 되어 있어야만 정상 작동합니다.
	list.unique([](int a, int b) {return a == b; });
	// 반복자 다음 원소를 지웁니다.
	list.erase_after(list.begin());
	// 정렬 오름차순
	list.sort(std::less<int>());
	// 정렬 내림차순
	list.sort(std::greater<int>());

	
	// 인스턴스화를 위해서는 원소의 타입을 지정합니다.
	std::list<int> List{ 1,2,3 };
	// 역순으로 나열합니다.
	List.reverse();
	std::list<int> List2{ 4,5,6 };
	// List를 정렬합니다.
	List.sort();
	// 매개변수의 리스트를 모두 옮겨서 하나로 병합니다. **단! 두 리스트 모두 똑같이 정렬되어 있어야 합니다.
	// (안되어있을때 런타임에러 발생)
	List2.merge(List);


	std::deque<int> deque{ 3,4,5 };
	// push_front() : 앞에 값을 추가합니다.
	deque.push_front(1);
	// push_back() : 뒤에 값을 추가합니다.
	deque.push_back(6);
	// pop_front() : 앞에 값을 제거합니다.
	deque.pop_front();
	// pop_back() : 뒤에 값을 제거합니다.
	deque.pop_back();


	std::stack<int> stack;
	// 값을 추가하기 위해서는 push만 사용가능합니다.
	stack.push(1);	// { 1 }
	stack.push(2);	// { 2, 1 }
	stack.push(3);	// { 3, 2, 1 }
	// 값을 제거하기 위해서는 pop만 사용가능합니다.
	stack.pop();

	std::stack<int> tempStack(stack);
	while (!tempStack.empty())
	{
		std::cout << tempStack.top() << " ";
		tempStack.pop();
	}

	
	std::queue<int> queue;
	// 값을 추가하기 위해서는 push만 사용할 수 있습니다.
	queue.push(1);	// { 1 }
	queue.push(2);	// { 1, 2 }
	queue.push(3);	// { 1, 2, 3 }
	// 값을 제거하기 위해서는 pop만 사용 가능합니다.
	queue.pop();	// { 2, 3 }
	
	std::queue<int> tempQueue(queue);
	while (!tempQueue.empty())
	{
		std::cout << tempQueue.front() << " ";
		tempQueue.pop();
	}


	return 0;
}