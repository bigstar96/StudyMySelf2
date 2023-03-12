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

void TestPrint(std::string& str)
{
	std::cout << str.length() << " : " << str << std::endl;
}


#include <string>
#include <sstream>


int main()
{
	std::string empty;
	TestPrint(empty);
	std::string sized(10, '\0');
	TestPrint(sized);
	std::string s1("test");
	std::cout << s1[0] << s1[1] << s1[2] << s1[3] << std::endl;
	std::string s2(s1);
	std::string s3 = s1 + s2;
	TestPrint(s3);
	s3 += s3;
	s3[0] = 'T';
	TestPrint(s3);
	empty = s3;
	TestPrint(empty);
	empty = empty;
	TestPrint(empty);


	int number1{ 123 };
	std::string str1{ "" };
	str1 = std::to_string(number1);
	number1 = stoi(str1);
	std::cout << str1 << "<->" << number1 << std::endl;

	wchar_t c1 = L'A';
	std::wstring String = L"확장 문자열";
	
	int number2{ 1 };
	char name[]{ "Doggy" };
	float average{ 90.1f };
	char output[128]{};

	sprintf_s(output, sizeof(output),
		"%d번 학생 %s는 평균 %.1f 입니다.",
		number2, name, average
		);
	std::string str2{ output };
	std::cout << str2 << std::endl;

	std::cout << snprintf(output, sizeof(output), "%d번 학생 %s는 평균 %.1f 입니다.", number2, name, average);

	std::ostringstream oss;
	oss << number2 << "번 학생 " << name << "는 평균 " << average << "입니다." << std::endl;

	std::string buffer = oss.str();
	std::cout << buffer << std::endl;
}