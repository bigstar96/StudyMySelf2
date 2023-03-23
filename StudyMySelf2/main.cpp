#include <iostream>

int operator""km(long double dist)
{
	return static_cast<int>(dist);
}

int main()
{
	int distance = 1.0km;
	std::cout << distance;
}


/*
nullptr
auto
Initializer list
uniform initialization
Lambda Expression
R-value reference
std:move
constexpr
decltype
noexcept
std::current_exception();
std::rethrow_exception(...);

nsmaespace NAME1
{
	inline namespace NAME2 {...}
}

int operator""km(long double dist)
{
	return static_cast<int>(dist);
}


*/