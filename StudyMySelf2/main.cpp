#include <iostream>
#include <vector>
#include <map>
#include <string>


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

using int_vector = std::vector<int>;
using accum_history_map_shared = std::map<int, std::shared_ptr<int_vector>>;

std::shared_ptr<int_vector> HowAccumulate(
	int sum,
	const int_vector& numbers,
	std::shared_ptr<accum_history_map_shared> h)
{
	{
		if (h->count(sum) == 1)
		{
			return (*h)[sum];
		}
		if (sum == 0)
		{
			return std::make_shared<int_vector>();
		}
		if (sum < 0)
		{
			return nullptr;
		}

		int remain{};

		for (auto e : numbers)
		{
			remain = sum - e;
			auto ret = HowAccumulate(remain, numbers, h);

			if (ret != nullptr)
			{
				ret->push_back(e);
				(*h)[sum] = ret;
				return (*h)[sum];
			}
		}
	}

	(*h)[sum] = nullptr;
	return nullptr;
}

void Print(int_vector* r)
{
	std::cout << "{ ";

	if (r != nullptr)
	{
		for (auto e : *r)
		{
			std::cout << e << " ";
		}
	}
	std::cout << "}" << std::endl;
}


std::shared_ptr<int_vector> OptimizeAccumulate(
	int sum,
	const int_vector& numbers,
	std::shared_ptr<accum_history_map_shared> h
)
{
	if (h->count(sum) == 1)
	{
		return (*h)[sum];
	}
	if (sum == 0)
	{
		return std::make_shared<int_vector>();
	}
	if (sum < 0)
	{
		return nullptr;
	}

	int remain{};
	std::shared_ptr<int_vector> optimized = nullptr;

	for (auto e : numbers)
	{
		remain = sum - e;
		auto ret = OptimizeAccumulate(remain, numbers, h);

		if (ret != nullptr)
		{
			std::shared_ptr<int_vector> v = std::make_shared<int_vector>();
			v->resize(ret->size());
			std::copy(ret->begin(), ret->end(), v->begin());
			v->push_back(e);
			if (optimized == nullptr || v->size() < optimized->size())
			{
				optimized = v;
			}
		}
	}

	(*h)[sum] = optimized;
	return (*h)[sum];
}

bool CanGenerate(std::string target, const std::vector<std::string>& stringlist)
{
	if (target == "")
	{
		return true;
	}

	for (auto e : stringlist)
	{
		if (target.find(e) == 0)
		{
			const std::string subs = target.substr(e.length());
			if (CanGenerate(subs, stringlist))
			{
				return true;
			}
		}
	}

	return false;
}

using gen_history = std::map<std::string, bool>;

bool CanGenerate2(std::string target, const std::vector<std::string>& stringlist, gen_history& h)
{
	if (h.count(target) == 1)
	{
		return h[target];
	}

	if (target == "")
	{
		return true;
	}

	for (auto e : stringlist)
	{
		if (target.find(e) == 0)
		{
			const std::string subs = target.substr(e.length());
			if (CanGenerate2(subs, stringlist, h))
			{
				h[target] = true;
				return h[target];
			}
		}
	}

	h[target] = false;
	return h[target];
}


int CanGenerate3(std::string target, const std::vector<std::string>& stringlist)
{
	if (target == "")
	{
		return 1;
	}

	int count{ 0 };

	for (auto e : stringlist)
	{
		if (target.find(e) == 0)
		{
			const std::string subs = target.substr(e.length());
			count += CanGenerate3(subs, stringlist);
		}
	}

	return count;
}

using gen_history_map = std::map<std::string, int>;

int HowManyGenerate(std::string target, const std::vector<std::string>& stringlist, gen_history_map& h)
{
	if (h.count(target) == 1)
	{
		return h[target];
	}
	if (target == "")
	{
		return 1;
	}

	int count{};

	for (auto e : stringlist)
	{
		if (target.find(e) == 0)
		{
			const std::string subs = target.substr(e.length());
			count += HowManyGenerate(subs, stringlist, h);
		}
	}

	h[target] = count;
	return count;
}

#include <list>
using result = std::list<std::list<std::string>>;

result FindGenerate(std::string target, const std::vector<std::string>& stringlist)
{
	if (target == "")
	{
		return result{ {} };
	}
	result r;

	for (auto e : stringlist)
	{
		if (target.find(e) == 0)
		{
			const std::string subs = target.substr(e.length());
			auto ret = FindGenerate(subs, stringlist);

			for (auto e2 : ret)
			{
				e2.push_front(e);

				r.push_front(e2);
			}
		}
	}

	return r;
}

using result2 = std::list<std::list<std::string>>;
using gen_history_list = std::map<std::string, result2>;

result2 FindGenerate2(std::string target, const std::vector<std::string>& stringlist, gen_history_list& h)
{
	if (h.count(target) == 1)
	{
		return h[target];
	}
	if (target == "")
	{
		return result2{ {} };
	}

	result2 r;

	for (auto e : stringlist)
	{
		if (target.find(e) == 0)
		{
			const std::string subs = target.substr(e.length());
			auto ret = FindGenerate2(subs, stringlist, h);

			for (auto e2 : ret)
			{
				e2.push_front(e);

				r.push_front(e2);
			}
		}
	}
	h[target] = r;
	return h[target];
}

void Print2(const result& r)
{
	std::cout << "{ " << std::endl;
	for (auto e1 : r)
	{
		std::cout << "\t{ ";
		for (auto e2 : e1)
		{
			std::cout << e2 << ", ";
		}
		std::cout << "}, " << std::endl;
	}

	std::cout << "}" << std::endl;
}



int main()
{
	accum_history h;

	std::cout << CanAccumulate(900, { 7, 14 }, h) << std::endl;
	h.clear();
	std::cout << CanAccumulate(7, { 5,3,4,7 }, h) << std::endl;
	h.clear();
	std::cout << CanAccumulate(7, { 2,4 }, h) << std::endl;

	std::cout << "---HowAccumulate---" << std::endl;
	Print(HowAccumulate(7, { 5, 3, 4, 7 }, std::make_shared<accum_history_map_shared>()).get());
	Print(HowAccumulate(7, { 1, 7 }, std::make_shared<accum_history_map_shared>()).get());
	Print(HowAccumulate(7, { 7, 14 }, std::make_shared<accum_history_map_shared>()).get());

	std::cout << "----OptimizeAccumulate---" << std::endl;
	Print(OptimizeAccumulate(7, { 5,3,4,7 }, std::make_shared<accum_history_map_shared>()).get());
	Print(OptimizeAccumulate(7, { 1, 4 }, std::make_shared<accum_history_map_shared>()).get());
	Print(OptimizeAccumulate(900, { 7, 14 }, std::make_shared<accum_history_map_shared>()).get());
	Print(OptimizeAccumulate(1750, { 10, 50, 100, 500, 1000 }, std::make_shared<accum_history_map_shared>()).get());

	std::cout << "---Cangenerate---" << std::endl;
	std::cout << CanGenerate("abcdef", { "ab", "abc", "cd", "def", "abcd" }) << std::endl;

	std::cout << "---gen history---" << std::endl;
	gen_history h2;
	std::cout << CanGenerate2("abcdef", { "ab", "abc", "cd", "def", "abcd" }, h2) << std::endl;

	std::cout << "---count string---" << std::endl;
	std::cout << CanGenerate3("abcdef", { "ab", "abc", "cd", "def", "abcd" }) << std::endl;

	std::cout << "---map count string---" << std::endl;
	gen_history_map h3;
	std::cout << HowManyGenerate("abcdef", { "ab", "abc", "cd", "def", "abcd" }, h3) << std::endl;

	std::cout << "--- ---" << std::endl;
	Print2(FindGenerate("hello", { "he", "h", "e", "llo", "hell" }));

	std::cout << "---- ----" << std::endl;
	gen_history_list h4;
	Print2(FindGenerate2("hello", { "he", "h", "e", "llo", "hell" }, h4));

	return 0;
}