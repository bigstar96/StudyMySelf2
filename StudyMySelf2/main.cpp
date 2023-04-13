#include <iostream>
#include <map>
#include <string>

using fib_history = std::map<int64_t, int64_t>;

int64_t Fibonacci(int64_t n, fib_history& h)
{
	if (h.count(n) == 1)
	{
		return h[n];
	}

	if (n <= 2)
	{
		return 1;
	}

	h[n] = Fibonacci(n - 1, h) + Fibonacci(n - 2, h);

	return h[n];
}

int FindWay(int m, int n)
{
	if (m == 0 || n == 0)
	{
		return 0;
	}

	if (m == 1 && n == 1)
	{
		return 1;
	}

	return FindWay(m - 1, n) + FindWay(m, n - 1);
}

using way_history = std::map<std::string, int>;

int FindWays(int m, int n, way_history& h)
{
	const std::string key = std::to_string(m) + "," + std::to_string(n);

	if (h.count(key) == 1)
	{
		return h[key];
	}

	const std::string rkey = std::to_string(n) + "," + std::to_string(m);
	if (h.count(rkey) == 1)
	{
		return h[rkey];
	}

	if (m == 0 || n == 0)
	{
		return 0;
	}

	if (m == 1 && n == 1)
	{
		return 1;
	}

	h[key] = FindWays(m - 1, n, h) + FindWays(m, n - 1, h);

	return h[key];
}

int main()
{
	fib_history fh;
	std::cout << Fibonacci(50, fh) << std::endl;

	std::cout << FindWay(5, 5) << std::endl;

	way_history wh;
	std::cout << FindWays(20, 20, wh) << std::endl;

	return 0;
}