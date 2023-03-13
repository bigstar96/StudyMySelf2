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