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
	void func1(){}// �������̵� �ƴ� (const Ÿ���� �ƴ�)
	void func2(){}// �������̵� �ƴ� (Base::func2()�� virtual�� �ƴ�)
};

class Base
{
public:
	virtual void func3() const final {}
	virtual void func4() {}
};

class Derived : public Base
{
	// void func3() const override {} // �����Ͽ���
	void func4() override {}
};


//<enum class>
enum class Color						// enum class ����
{
	red,
	blue
};
enum class TrafficLight : char			// ���� �����͸� char�� �����Ͽ� ���� ����
{
	red,
	yellow,
	green
};


//<��ȯ�� ���̻�(suffix return type)
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
��ȯ�� ���̻�� �켱 ��ȯ���� auto�� ������ �� �Ű����� ���ķ� �̷�� ����Դϴ�.
auto function - name(arguments)->ret - type {}
*/


//<���� ���ڿ� ���ͷ�(raw string literal)>
// ex) std::string str = "\"\'\\\'\"";
// ���� �˾ƺ��� ����
// std::string str2 = R"("'\'")";
// ����(raw)�� ù���ڸ� ����Ͽ� R�� ���̰� "( �� )" ���̿� ���ڿ��� �����ϸ� �˴ϴ�.


//<���� ���� ���ø�>
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
1. ���ø� �Լ����� �޴� �Ű������� ������ Ÿ�Ե�(class... Types)�� ������ �� �ΰ� ���������� ...�� ���Դϴ�.
2. �����ڿ� ���� �Ű������� �״�� �����ϱ� ���ؼ� C++11�� std::forward<T>()...���ø� �Լ��� ����մϴ�.
perfect forwarding �� variadic template�� ����ϸ� �Ϻ��� ���丮�� ���� �� �ְ� �˴ϴ�. *���*
*/


//<extern ���ø�>
/*
template<typename T>
void MyFunction()
{
	// ���� �� �ڵ�
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
�̷��� ������ �ڵ���� �����Ϸ��� ������ �ϰ� �� ����� ������ ������ �̴ϴ�.
MySource1.o		Func1();
				MyFunction<int>();
MySource2.o		Func2();
				MyFunction<int>();
�����Ϸ��� �ν��Ͻ�ȭ �ɶ����� �ڵ带 �����ϹǷ� ���� ���� �ߺ� ����/������ �� ���Դϴ�.

�̷��� �ߺ��� ���ϱ� ���� ������ ���� extern���� ������ �� �ְ� �Ǿ����ϴ�.

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
<������� for(range-based for)>

std::vector<int> v;
for(auto x : v){}

for(auto& x : v){}

for(auto x : {1,2,3,4,5}){}


<���ٽ�>
[=]()mutable throw() -> int
{
	int n = x + y;
	x = y;
	y = n;
	return n;
}

1. [=] - ĸ���� : �⺻������ ���ٽ��� �ܺ��� �������� ����� �� �����ϴ�.
[] : �ܺ� ���� ��� �Ұ�
[&] : �ܺ� ������ ���������� ��� (Call by Reference)
[=] : �ܺ� ������ ������ ��� (Call by Value)

2. () - �Ķ���� : �Լ��� ���� �Ķ���͵��� �����մϴ�.
3. mutable - �ɼ�. �ϴ� ����
4. throw - �ɼ�. �ϴ� ����
-> int - ���ϰ� : ��ȯ�ϴ� ���� ������ ���. ��ȯ �ڷ����� �����ؾ��մϴ�.

ex) [](int a, int b) {} - �Ű����� 2���� �޴� �͸��Լ�
[](int a) -> int { return result; } - �Ű����� 1���� ��ȯ���� �ִ� �͸��Լ�


<������ ���� (R-value reference)�� std::move ����>


<�⺻ �̵� ������ �� ���� ������

MyClass(const Myclass&)					���� ������
MyClass& operator=(const MyClass&);		���� ����
MyClass(MyClass&&);						�̵� ������
MyClass& operator=(MyClass&&);			�̵� ����

�̵� ������
- �̵��� ��ü�� ���� �ٸ� ��ü�� �ű�� ������, ����ʹ� �޸� ������ �ٸ� ��ü�� ���� �Ű����� ������
�����͸� �����ϰ� �Ǿ� �����ϴ�. �̷��� �̵��� �������� �̸� ���� ��ü(unnamed object)�� ���� �߻��մϴ�.

�̸� ���� ��ü = ���� ��ü, �ӽö� �̸��� �ʿ� ���� ����ε�, �ַ� �Լ��� ��ȯ������ �̷� ���� ��ü�� �˴ϴ�.
�̷� ���� ��ü�� ���� �� �ٽ� ���� ���� �����Ƿ� ������ �ʿ䰡 ����, �׳� �̵��� ������ �׸��Դϴ�.
�̵� �����ڴ� �Ű������� �ϳ��� ��ü�� �޴µ� ������ ����(R-value reference)���̶�� && �����ڰ� ���˴ϴ�.
Dog(Dog&& dog);

Dog dog1;			// �⺻ ������
Dog dog2 = dog1;	// ���� ������
Dog dog3 = Dog();	// �̵� ������


�̵� �Ҵ� ������
- �� ���簡 �ƴ� �̵��� ���������� ǥ���ϰ� ������ Dog& operator=(Dog&&) �����ڸ� �����ε� �ؾ� �մϴ�.
Dog dog1;
Dog dog2 = dog1;
Dog dog3 = dog1 + dog2;		// �̵� ������





*/
