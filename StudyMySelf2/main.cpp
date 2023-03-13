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
	std::cout << "숫자를 공백으로 구분하여 입력하세요!" << std::endl;
	std::cout << "입력 종료는 숫자가 아닌 문자를 입력하시면 됩니다." << std::endl;

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

	std::cout << "합 : " << sum << std::endl;
	std::cout << "평균 : " << average << std::endl;*/

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