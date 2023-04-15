#include <iostream>
#include <vector>
#include <map>

using accum_history = std::map<int, bool>;

bool CanAccumulate(int sum, const std::vector<int>& numbers, accum_history& h)
{
	if (h.count(sum) == 1)
	{
		return h[sum];
	}
	if (sum == 0)
	{
		return true;
	}
	if (sum < 0)
	{
		return false;
	}

	int remain{};

	for (auto e : numbers)
	{
		remain = sum - e;
		if (CanAccumulate(remain, numbers, h) == true)
		{
			h[sum] = true;
			return true;
		}
	}
	h[sum] = false;
	return false;
}



int main()
{
	accum_history h;

	std::cout << CanAccumulate(900, { 7, 14 }, h) << std::endl;

	h.clear();
	std::cout << CanAccumulate(7, { 5,3,4,7 }, h) << std::endl;

	h.clear();
	std::cout << CanAccumulate(7, { 2,4 }, h) << std::endl;

	return 0;
}