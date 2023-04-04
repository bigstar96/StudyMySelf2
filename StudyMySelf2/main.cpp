#include <iostream>

auto Function(int x, int y)
{
	return x + y;
}

decltype(auto) Function2()
{
	return Function(1, 2);
}

template<typename T> T pi = T(3.141592653589793);


int main()
{
	auto hex = 0x2A;

	auto bin = 0b01010;

	auto x = 4;
	auto z = [y = x + 1] {
		return y + 1;
	}();

	// auto sum = [](const auto a, const auto b) { return a + b; }();

	std::cout << "INT PI : " << pi<int> << std::endl;
	std::cout << "FLOAT PI : " << pi<float> << std::endl;

	auto money = 100'000;

	auto string = "HELLO WORLD"s;
	auto minute = 60s;

}