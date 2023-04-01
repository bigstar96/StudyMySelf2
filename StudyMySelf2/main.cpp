#include <iostream>

#include <list>

class Demon
{
};

class Warrior
{
};

#include <vector>

template<class T>
T swap(T& a, T& b)
{
	T temp(a);
	a = b;
	b = temp;
}

template<class T>
T swap(T& a, T& b)
{
	T tmp = std::move(a);
	a = std::move(b);
	b = std::move(tmp);
}

template<typename T>
void templateFunction(T&& x)
{
	function(x);
}

template<typename T>
void TemplateFucntion(T&& x)
{
	function(std::forward<T>(x));
}

enum Flags {
	none = 0,
	slow = 1,
	paralyse = 2,
	bleed = 4,
	poison = 8
};

constexpr int operator| (Flags f1, Flags f2)
{
	return Flags(int(f1) | int(f2));
}


class MyHero
{
	int mHP;
	int mMP;
public:
	MyHero() : MyHero(0, 0) {} // old - { mHP = 0; mMP = 0; }
	MyHero(int hp) : MyHero(hp, 0) {}// old - { mHP = hp; mMP = 0; }
	MyHero(int hp, int mp) { mHP = hp; mMP = mp; }
};


class Base
{
public:
	virtual void func1()const{}
	void func2(){}
};

class Derived : public Base
{
	void func1(){}// 오버라이드 아님 (const 타입이 아님)
	void func2(){}// 오버라이드 아님 (Base::func2()는 virtual이 아님)
};

class Base
{
public:
	virtual void func3() const final {}
	virtual void func4() {}
};

class Derived : public Base
{
	// void func3() const override {} // 컴파일에러
	void func4() override {}
};


//<enum class>
enum class Color						// enum class 사용법
{
	red,
	blue
};
enum class TrafficLight : char			// 내부 테이터를 char로 한정하여 공간 절약
{
	red,
	yellow,
	green
};


//<반환형 접미사(suffix return type)
/*
template<class T, class U>
 decltype(x + y) Add(T x, T y) // error
{
	return x + y;
}
*/
template<class T, class U>
auto Add(T x, T y) -> decltype(x + y)
{
	return x + y;
}

/*
반환형 접미사는 우선 반환형을 auto로 지정한 후 매개변수 이후로 미루는 방식입니다.
auto function - name(arguments)->ret - type {}
*/


//<원시 문자열 리터럴(raw string literal)>
// ex) std::string str = "\"\'\\\'\"";
// 예는 알아보기 힘듦
// std::string str2 = R"("'\'")";
// 원시(raw)의 첫글자를 사용하여 R을 붙이고 "( 와 )" 사이에 문자열을 지정하면 됩니다.


//<가변 인자 템플릿>
/*
Warrior* Make() { return new Warrior; }
Archer* Make(int arg1) { return new Archer; }
Wizard* Make(int arg1, int arg2) { return new Wizard; }
*/
template<class T>
T* Make()
{
	return new T;
}
template<class T, class...Types>
T* Make(Types&& ... args)
{
	return new T(std::forward<Types>(args)...);
}
/*
1. 템플릿 함수에서 받는 매개변수를 별도의 타입들(class... Types)로 지정을 해 두고 감변형태인 ...을 붙입니다.
2. 생성자에 가변 매개변수를 그대로 전달하기 위해서 C++11의 std::forward<T>()...템플릿 함수를 사용합니다.
perfect forwarding 과 variadic template를 사용하면 완벽한 팩토리를 만들 수 있게 됩니다. *기억*
*/


//<extern 템플릿>
/*
template<typename T>
void MyFunction()
{
	// 수백 줄 코드
}
// MySource1.cpp
void Func1()
{
	MyFunction<int>();
}
// MySource2.cpp
void Func2()
{
	MyFunction<int>();
}
이렇게 구성된 코드들을 컴파일러가 컴파일 하고 난 결과는 다음과 같아질 겁니다.
MySource1.o		Func1();
				MyFunction<int>();
MySource2.o		Func2();
				MyFunction<int>();
컴파일러는 인스턴스화 될때마다 코드를 생성하므로 위와 같이 중복 생성/컴파일 될 것입니다.

이러한 중복을 피하기 위해 다음과 같이 extern으로 선언할 수 있게 되었습니다.

extern template void MyFunction<int>();
void Func2()
{
	MyFunction<int>();
}

*/

int main()
{
	void function1(int);
	void function2(char*);

	function1(0);
	function2(nullptr);

	auto myInteger = 7;


	std::list<int> myList{};
	for (std::list<int>::iterator itr = myList.begin(); itr != myList.end(); ++itr)
	{
		std::cout << *itr << " ";
	}
	std::cout << std::endl;
	for (auto itr = myList.begin(); itr != myList.end(); ++itr)
	{
		std::cout << *itr << " ";
	}

	int myValue = { 0 };
	std::string myName = { "doggy" };

	void fucntion3(std::initializer_list<int> initializer);
	// function3({ 1,2 });

	int myValue1 = 3;
	int myArray1[] = {1,2,3,4};
	Demon myDemon1 = Demon();
	Warrior* pWarrior1 = new Warrior;

	int myValue2{ 3 };
	int myArray2[]{ 1,2,3,4 };
	Demon myDemon2{};
	Warrior* pWarrior2 = new Warrior{};

	
	std::vector<int> v;
	for (auto x : v) {}
	for (auto& x : v) {}
	for (auto x : { 1,2,3,4,5 }) {}

	[](int a, int b) {};
	[](int a) -> int { return a + a; };

	Flags myStatus{ none };
	switch (myStatus)
	{
	case none:
		break;

	case slow | paralyse:
		break;
	
	}



}


/*
<범위기반 for(range-based for)>

std::vector<int> v;
for(auto x : v){}

for(auto& x : v){}

for(auto x : {1,2,3,4,5}){}


<람다식>
[=]()mutable throw() -> int
{
	int n = x + y;
	x = y;
	y = n;
	return n;
}

1. [=] - 캡쳐절 : 기본적으로 람다식은 외부의 변수들을 사용할 수 없습니다.
[] : 외부 변수 사용 불가
[&] : 외부 변수를 참조형으로 사용 (Call by Reference)
[=] : 외부 변수를 값으로 사용 (Call by Value)

2. () - 파라미터 : 함수에 사용될 파라미터들을 정의합니다.
3. mutable - 옵션. 일단 무시
4. throw - 옵션. 일단 무시
-> int - 리턴값 : 반환하는 값이 있을때 사용. 반환 자료형을 지정해야합니다.

ex) [](int a, int b) {} - 매개변수 2개를 받는 익명함수
[](int a) -> int { return result; } - 매개변수 1개와 반환값이 있는 익명함수


<우측값 참조 (R-value reference)와 std::move 구문>


<기본 이동 생성자 및 복사 생성자

MyClass(const Myclass&)					복사 생성자
MyClass& operator=(const MyClass&);		복사 대입
MyClass(MyClass&&);						이동 생성자
MyClass& operator=(MyClass&&);			이동 대입

이동 생성자
- 이동은 객체의 값을 다른 객체로 옮기는 것으로, 복사와는 달리 실제로 다른 객체로 값을 옮겨져서 원본은
데이터를 유실하게 되어 버립니다. 이러한 이동은 원본값이 이름 없는 객체(unnamed object)일 때만 발생합니다.

이름 없는 객체 = 무명 객체, 임시라서 이름이 필요 없는 경우인데, 주로 함수의 반환값등이 이런 무명 객체가 됩니다.
이런 무명 객체를 만들 때 다시 사용될 일이 없으므로 복사할 필요가 없고, 그냥 이동해 버리면 그만입니다.
이동 생성자는 매개변수로 하나의 객체를 받는데 우측값 참조(R-value reference)형이라는 && 연산자가 사용됩니다.
Dog(Dog&& dog);

Dog dog1;			// 기본 생성자
Dog dog2 = dog1;	// 복사 생성자
Dog dog3 = Dog();	// 이동 생성자


이동 할당 연산자
- 값 복사가 아닌 이동을 배정문으로 표현하고 싶으면 Dog& operator=(Dog&&) 연산자를 오버로딩 해야 합니다.
Dog dog1;
Dog dog2 = dog1;
Dog dog3 = dog1 + dog2;		// 이동 생성자





*/
