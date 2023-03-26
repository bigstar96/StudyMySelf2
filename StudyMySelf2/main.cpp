#include <iostream>

int operator""km(long double dist)
{
	return static_cast<int>(dist);
}

class X
{
public:
	// ���� �����ڸ� �⺻ �����ڷ�
	X(const X&) = default;

	// ���� ���� ����
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

	// ������ ���� : �Ͻ��� ��ȯ
	// int val1 = c;

	// ����
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

		// ERROR : Less ��ü�� ����
		// sort(v.begin(), v.end(), Less());
	}

	
}


/*
16_1_0_C++11

<��� - �Ϲ�>

nullptr
auto
Initializer list
uniform initialization
Lambda Expression
R-value reference & std:move
constexpr

decltype
- declared type�� ���ڷ� ǥ������ Ÿ���� �˷��ִ� Ű�����Դϴ�.
ex) 
int x;
decltype(x+1) y = x + 1;
auto�ʹ� �޸� ������ ������ Ÿ���� �߷��մϴ�.

noexcept
- �Լ� �ڿ� ǥ���Ͽ� ���ܸ� ������ �ʴ´ٴ� ���� ����մϴ�.

���� ���� �� �ٽ� ������
- ���� ���ܸ� �����ؼ� �ٽ� �����Ⱑ �����մϴ�.
std::current_exception();
std::rethrow_exception(...);

�ζ��� �̸�����(inline namespace)
- �̸� ���� �ȿ� �� �ٸ� �̸� ������ ����� �Ӵϴ�.
ex)
nsmaespace NAME1
{
	inline namespace NAME2 {...}
}

����� ���� ���ͷ�
- ���ͷ� �ڿ� �ٴ� ÷�ڸ� �̿��� 10km �� ���� ����� ���� ���ͷ��� ���� �� �ֽ��ϴ�.
int operator""km(long double dist)
{
	return static_cast<int>(dist);
}


<��� - Ŭ����>
�⺻ �̵� ������ �� ���� ������
�븮 ������
Ŭ���� ���ο����� ��� �ʱ�ȭ
override & final

��� ������
- ��� Ŭ������ �����ڸ� ������ �� �ֽ��ϴ�.
ex)
class Derived : public Base
{
public:
	using Base::Base;
}

= default, = delete
- delete : Ư�� �Լ� ���Ǹ� �����մϴ�.
default : �⺻ �����ڸ� ��������� �����մϴ�.
ex)
class X
{
public:
	// ���� �����ڸ� �⺻ �����ڷ�
	X(const X&) = default;

	// ���� ���� ����
	X& operator=(const X&) = delete;
};

����� ����ȯ ������
- �����ڿ����� ��밡���ϴ� explicit Ű���带 �����ڿ� ���� �����մϴ�.
ex)
class MyClass
{
public:
	explicit operator int() { return 100; }
};

int main()
{
	MyClass c;
	
	// ������ ���� : �Ͻ��� ��ȯ
	int val1 = c;

	// ����
	int val2 = static_cast<int>(c);
}


<��� - Ÿ��>
enum class
long long - 64��Ʈ���� �߰�

<��� - ��Ÿ>
��ȯ�� ���̻�(suffix return type)
���� ���ڿ� ���ͷ�(raw string literal)

std:static_assert
- ������ assert�� ����ð��� �Ǵ�������, ���� �� ������ ���� �ɷ����� ���ؼ��� ������ �ð��� ������ �ʿ䵵 �ֽ��ϴ�.
const_expr�� �����մϴ�.

�޸� ����
- ��ü ������ �������� �޸� ��踦 ������ �� �ֽ��ϴ�.
ex)
alignas(bytes)

struct alignas(16) STRUCT
{
	int myInt;
};
�� ����ü�� 16����Ʈ�� ���ĵǹǷ� ���� 4����Ʈ�� �ص� ���ĵǾ� 16����Ʈ�� ������ �����ϰ� �˴ϴ�.
12 ����Ʈ�� ����ֽ��ϴ�.


<��� - ���ø�>
���� ���� ���ø�(variadic template)
extern ���ø�

���ø� ����
- using�� ���� ���ø� ������ ������ �� �ֽ��ϴ�.
ex)
template<class T>
using Vector = std::vector<T>;

int main()
{
	Vector<int> vector{ 1,2,3 };
}

���� Ÿ�� ���ø� ����
- ���ſ��� ���� ��ü�� ���ø� ���ڷ� ������� ���߽��ϴ�.
ex)
{
	struct Less
	{
		bool operator()(const X& a, const X& b)
		{
			return true;
		}
	}

	// ERROR : Less ��ü�� ����
	sort(v.begin(), v.end(), Less());
}
C++11 ������ �̷� ���� ��ü�� ��밡���մϴ�. �׷��� ���ٽĵ� ��밡���� �� ���Դϴ�.

> ǥ�� ����
- >> ����Ʈ �����ڿ� ������ ���� ���� ���ſ��� �������̾�����, C++11 ���� �ذ�Ǿ����ϴ�.
ex)
std::list<std::list<int> >	list;	// old
std::list<std::list<int>>	list;	// c++11


<STL �Ϲ�>
std::unique_ptr
std::shared_ptr
std::weak_ptr
std::tuple
std::function & std::bind
����ǥ����(regular expression)

Ÿ�� Ư��(type traits)
- ������Ÿ�ӿ� �־��� ��ü�� Ÿ������(type traits)�� ���� �� �ֽ��ϴ�.
<type_traits> ����� ����Ǿ� ������, is_arry, is_class, is_base_of �� �پ��� ����� �����մϴ�.
�ʹ� ���Ƽ� ���� ����ϰ� �� �� ���ݾ� �����ϵ��� �ϰڽ��ϴ�.

�ð� ��ƿ��Ƽ
- ������ �ð��� ������ �� �ְ� �����ִ� ��ɵ��Դϴ�.
���ӿ����� ���� �ٸ� ����� ����ϴµ�, �����ӿ�ũ ���ۿ��� �˷��帮�ڽ��ϴ�.

���� ����
- ��ǻ�ʹ� ������ ��/��� �� ������ �־ �����ΰ��� ����� ������ ���ؼ� �ᱹ �䳻�� ������.
�׷��� ������ �� ���� ���� �ִ��� �׷��� �ϰ� ������ �մϴ�.
�̷� ������ ����� ���� �� ��ȭ �Ǿ����ϴ�.


<STL �����̳� �� �˰���>
std::array
std::forward_list

unordered_�迭 �����̳�
- map, set �� ������ ���� unordered_map, unordered_set �� �߰��Ǿ����ϴ�.


<STL ���ü�>
std::thred
��ȣ ����(Mutual Exclusion) - std::mutex
std::lock
std::async


*/