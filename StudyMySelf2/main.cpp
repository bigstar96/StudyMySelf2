#include <iostream>

int operator""km(long double dist)
{
	return static_cast<int>(dist);
}

class X
{
public:
	// 복사 생성자를 기본 생성자로
	X(const X&) = default;

	// 복사 배정 금지
	X& operator=(const X&) = delete;
};

class MyClass
{
public:
	explicit operator int() { return 100; }
};

#include <vector>
template<class T>
using Vector = std::vector<T>;

#include <type_traits>

int main()
{
	int distance = 1.0km;
	std::cout << distance;

	MyClass c;

	// 컴파일 에러 : 암시적 변환
	// int val1 = c;

	// 성공
	int val2 = static_cast<int>(c);

	Vector<int> vector{ 1,2,3 };
	
	{
		struct Less
		{
			bool operator()(const X& a, const X& b)
			{
				return true;
			}
		};

		// ERROR : Less 객체는 로컬
		// sort(v.begin(), v.end(), Less());
	}

	
}


/*
16_1_0_C++11

<언어 - 일반>

nullptr
auto
Initializer list
uniform initialization
Lambda Expression
R-value reference & std:move
constexpr

decltype
- declared type의 약자로 표현식의 타입을 알려주는 키워드입니다.
ex) 
int x;
decltype(x+1) y = x + 1;
auto와는 달리 수식의 값으로 타입을 추론합니다.

noexcept
- 함수 뒤에 표기하여 예외를 던지지 않는다는 것을 명시합니다.

예외 복사 및 다시 던지기
- 현재 예외를 복사해서 다시 던지기가 가능합니다.
std::current_exception();
std::rethrow_exception(...);

인라인 이름공간(inline namespace)
- 이름 공간 안에 또 다른 이름 공간을 만들어 둡니다.
ex)
nsmaespace NAME1
{
	inline namespace NAME2 {...}
}

사용자 지정 리터럴
- 리터럴 뒤에 붙는 첨자를 이용해 10km 와 같이 사용자 지정 리터럴을 만들 수 있습니다.
int operator""km(long double dist)
{
	return static_cast<int>(dist);
}


<언어 - 클래스>
기본 이동 생성자 및 복사 생성자
대리 생성자
클래스 내부에서의 멤버 초기화
override & final

상속 생성자
- 기반 클래스의 생성자를 가져올 수 있습니다.
ex)
class Derived : public Base
{
public:
	using Base::Base;
}

= default, = delete
- delete : 특정 함수 정의를 금지합니다.
default : 기본 생성자를 명시적으로 지정합니다.
ex)
class X
{
public:
	// 복사 생성자를 기본 생성자로
	X(const X&) = default;

	// 복사 배정 금지
	X& operator=(const X&) = delete;
};

명시적 형변환 연산자
- 생성자에서만 사용가능하던 explicit 키워드를 연산자에 적용 가능합니다.
ex)
class MyClass
{
public:
	explicit operator int() { return 100; }
};

int main()
{
	MyClass c;
	
	// 컴파일 에러 : 암시적 변환
	int val1 = c;

	// 성공
	int val2 = static_cast<int>(c);
}


<언어 - 타입>
enum class
long long - 64비트변수 추가

<언어 - 기타>
반환형 접미사(suffix return type)
원시 문자열 리터럴(raw string literal)

std:static_assert
- 기존의 assert는 실행시간에 판단하지만, 조금 더 오류를 일찍 걸러내기 위해서는 컴파일 시간에 판정할 필요도 있습니다.
const_expr을 판정합니다.

메모리 정렬
- 객체 내부의 변수들의 메모리 경계를 지정할 수 있습니다.
ex)
alignas(bytes)

struct alignas(16) STRUCT
{
	int myInt;
};
이 구조체는 16바이트로 정렬되므로 실제 4바이트라 해도 정렬되어 16바이트의 공간을 차지하게 됩니다.
12 바이트는 비어있습니다.


<언어 - 템플릿>
가변 인자 템플릿(variadic template)
extern 템플릿

템플릿 별명
- using을 통해 템플릿 별명을 지정할 수 있습니다.
ex)
template<class T>
using Vector = std::vector<T>;

int main()
{
	Vector<int> vector{ 1,2,3 };
}

지역 타입 템플릿 인자
- 과거에는 지역 객체를 템플릿 인자로 사용하지 못했습니다.
ex)
{
	struct Less
	{
		bool operator()(const X& a, const X& b)
		{
			return true;
		}
	}

	// ERROR : Less 객체는 로컬
	sort(v.begin(), v.end(), Less());
}
C++11 에서는 이런 로컬 객체도 사용가능합니다. 그래서 람다식도 사용가능해 진 것입니다.

> 표기 개선
- >> 시프트 연산자와 구분을 하지 못해 과거에는 제한적이었으나, C++11 에서 해결되었습니다.
ex)
std::list<std::list<int> >	list;	// old
std::list<std::list<int>>	list;	// c++11


<STL 일반>
std::unique_ptr
std::shared_ptr
std::weak_ptr
std::tuple
std::function & std::bind
정규표현식(regular expression)

타입 특성(type traits)
- 컴파일타임에 주어진 객체의 타입정보(type traits)를 구할 수 있습니다.
<type_traits> 헤더에 선언되어 있으며, is_arry, is_class, is_base_of 등 다양한 기능을 제공합니다.
너무 많아서 실제 사용하게 될 때 조금씩 설명하도록 하겠습니다.

시간 유틸리티
- 정밀한 시간을 관리할 수 있게 도와주는 기능들입니다.
게임에서는 조금 다른 기능을 사용하는데, 프레임워크 제작에서 알려드리겠습니다.

난수 생성
- 컴퓨터는 정해진 입/출력 을 가지고 있어서 무엇인가를 만들어 내지는 못해서 결국 흉내낼 뿐이죠.
그래서 임의의 수 같은 것은 최대한 그럴싸 하게 만들어야 합니다.
이런 난수의 기능이 조금 더 강화 되었습니다.


<STL 컨테이너 및 알고리즘>
std::array
std::forward_list

unordered_계열 컨테이너
- map, set 에 정렬이 빠진 unordered_map, unordered_set 이 추가되었습니다.


<STL 동시성>
std::thred
상호 배제(Mutual Exclusion) - std::mutex
std::lock
std::async


*/