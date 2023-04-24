#include <iostream>

#include <vector>

int64_t fibonacci1(const int n)
{
	if (n == 0)
	{
		return 0;
	}

	std::vector<int64_t> table(n + 1);
	table[1] = 1;

	/*
	for (int i = 0; i <= n; ++i)
	{
		if (i + 2 <= n)
		{
			table[i + 2] += table[i];
		}
		if (i + 1 <= n)
		{
			table[i + 1] += table[i];
		}
	}
	*/

	for (int i = 2; i <= n; ++i)
	{
		table[i] = table[i - 1] + table[i - 2];
	}

	return table[n];
}

#include <vector>

int FindWays(int m, int n)
{
	std::vector<std::vector<int>> table(m + 1, std::vector<int>(n + 1, 0));
	table[1][1] = 1;

	for (int row = 0; row <= m; ++row)
	{
		for (int col = 0; col <= n; ++col)
		{
			if (row + 1 <= m)
			{
				table[row + 1][col] += table[row][col];
			}

			if (col + 1 <= n)
			{
				table[row][col + 1] += table[row][col];
			}
		}
	}
	return table[m][n];
}

#include <vector>

bool CanAccumulate(int sum, const std::vector<int>& numbers)
{
	std::vector<bool> table(sum + 1);
	table[0] = true;

	for (int i = 0; i <= sum; ++i)
	{
		if (table[i] == true)
		{
			for (auto e : numbers)
			{
				if (i + e <= sum)
				{
					table[i + e] = true;
				}
			}
		}
	}
	return table[sum];
}

#include <vector>

using int_vector = std::vector<int>;

std::shared_ptr<int_vector> HowAccumulate(int sum, const int_vector& numbers)
{
	std::vector<std::shared_ptr<int_vector>> table(sum + 1, nullptr);

	table[0] = std::make_shared<int_vector>(0);

	for (int i = 0; i <= sum; ++i)
	{
		if (table[i] != nullptr)
		{
			for (auto e : numbers)
			{
				if (i + e <= sum)
				{
					table[i + e] = std::make_shared<int_vector>(*table[i]);
					table[i + e]->push_back(e);
				}
			}
		}
	}
	return table[sum];
}

#include <vector>

using int_vector = std::vector<int>;
std::shared_ptr<int_vector> OptimizeAccumulate(
	int sum, const int_vector& numbers
)
{
	std::vector<std::shared_ptr<int_vector>> table(sum + 1, nullptr);
	table[0] = std::make_shared<int_vector>(0);

	for (int i = 0; i <= sum; ++i)
	{
		if (table[i] != nullptr)
		{
			for (auto e : numbers)
			{
				if (i + e <= sum)
				{
					if (table[i + e] == nullptr || (table[i + e]->size() - 1 > table[i]->size()))
					{
						table[i + e] = std::make_shared<int_vector>(*table[i]);
						table[i + e]->push_back(e);
					}
				}
			}
		}
	}

	return table[sum];
}

#include <vector>
#include <string>	
bool CanGenerate2(
	const std::string target, const std::vector<std::string>& stringList
)
{
	std::vector<bool> table(target.length() + 1, false);

	table[0] = true;
	
	for (unsigned int i = 0; i <= target.length(); ++i)
	{
		if (table[i] == true)
		{
			for (auto e : stringList)
			{
				if (target.substr(i, e.length()) == e)
				{
					if (i + e.length() <= target.length())
					{
						table[i + e.length()] = true;
					}
				}
			}
		}
	}

	return table[target.length()];
}

#include <vector>
#include <string>
int HowManyGenerate2(
	const std::string target, const std::vector<std::string>& stringlist
)
{
	std::vector<int> table(target.length() + 1, 0);

	table[0] = 1;

	for (unsigned int i = 0; i <= target.length(); ++i)
	{
		if (table[i] > 0)
		{
			for (auto e : stringlist)
			{
				if (target.substr(i, e.length()) == e)
				{
					if (i + e.length() <= target.length())
					{
						table[i + e.length()] += table[i];
					}
				}
			}
		}
	}

	return table[target.length()];
}

#include <vector>
#include <list>
#include <string>

using string_list = std::list<std::string>;
using result = std::list<string_list>;

result FindGenerate2(
	const std::string target, const string_list& stringlist
)
{
	std::vector<result> table(target.length() + 1);

	table[0] = result{ {} };

	for (unsigned int i = 0; i <= target.length(); ++i)
	{
		for (auto e : stringlist)
		{
			if (target.substr(i, e.length()) == e)
			{
				if (i + e.length() <= target.length())
				{
					if (i + e.length() <= target.length())
					{
						for (auto e2 : table[i])
						{
							e2.push_back(e);

							table[i + e.length()].push_back(e2);
						}
					}
				}
			}
		}
	}

	return table[target.length()];
}

void Print(const result& r)
{
	std::cout << "{ " << std::endl;

	for (auto e1 : r)
	{
		std::cout << "\t{";
		for (auto e2 : e1)
		{
			std::cout << e2 << ", ";
		}
		std::cout << "}," << std::endl;
	}
	std::cout << "}" << std::endl << std::endl;
}



int main()
{
	std::cout << fibonacci1(4) << std::endl;

	std::cout << "-" << std::endl;
	std::cout << FindWays(2, 3) << std::endl;

	std::cout << "--" << std::endl;
	std::cout << CanAccumulate(8, { 2,3,5 });

	std::cout << "---" << std::endl;
	auto ret1 = HowAccumulate(8, { 2,3,5 });
	std::cout << "{ ";
	if (ret1 != nullptr)
	{
		for (auto e : *ret1)
		{
			std::cout << e << ", ";
		}
	}
	std::cout << "}" << std::endl;

	std::cout << "----" << std::endl;
	auto ret2 = OptimizeAccumulate(7, { 2,3,5 });
	std::cout << "{ ";
	if (ret2 != nullptr)
	{
		for (auto e : *ret2)
		{
			std::cout << e << ", ";
		}
	}
	std::cout << " }" << std::endl;

	std::cout << "-----" << std::endl;
	std::cout <<
		CanGenerate2("abcdef", { "ab","abc","cd","def","abcd" }) << std::endl;
	std::cout << CanGenerate2("hello", { "a","b","c","d" }) << std::endl;
	std::cout << CanGenerate2("", { "a","b","c","d" }) << std::endl;

	std::cout << "------" << std::endl;
	std::cout << HowManyGenerate2("abcdef", { "ab","abc","cd","def","abcd" }) << std::endl;
	std::cout << HowManyGenerate2("hello", { "a","b","c","d" }) << std::endl;
	std::cout << HowManyGenerate2("", { "a","b","c","d" }) << std::endl;
	std::cout << HowManyGenerate2("hello", { "he","h","e","llo","hell" }) << std::endl;

	std::cout << "-------" << std::endl;
	Print(FindGenerate2("abcdef", { "ab","abc","cd","def","abcd" }));
	Print(FindGenerate2("hello", { "a","b","c","d" }));
	Print(FindGenerate2("", { "a","b","c","d" }));
	Print(FindGenerate2("hello", { "he","h","e","llo","hell"}));


	return 0;
}