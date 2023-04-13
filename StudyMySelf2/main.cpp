#include <iostream>
#include <vector>
#include <algorithm>

class Heap
{
	std::vector<int> mHeap;

public:
	void Insert(int value)
	{
		mHeap.push_back(value);

		unsigned long i = mHeap.size() - 1;
		unsigned long half = (i - 1) / 2;

		while (i != 0 && value > mHeap[half])
		{
			mHeap[i] = mHeap[half];
			mHeap[half] = value;
			i = half;

			half = (i - 1) / 2;
		}
	}

	int Pop()
	{
		if (mHeap.size() == 0)
		{
			return 0;
		}

		int item = mHeap.front();
		mHeap[0] = mHeap.back();
		mHeap.pop_back();

		int i{ 0 };

		while (i < mHeap.size())
		{
			unsigned long big_child = (i * 2) + 1;

			if (big_child >= mHeap.size())
			{
				break;
			}

			if (big_child + 1 < mHeap.size() &&
				mHeap[big_child] < mHeap[big_child + 1])
			{
				big_child++;
			}

			if (mHeap[i] >= mHeap[big_child])
			{
				break;
			}

			std::swap(mHeap[i], mHeap[big_child]);

			i = big_child;
		}
		return item;
	}

	void Print()
	{
		for (auto& e : mHeap)
		{
			std::cout << e << " ";
		}
	}
};


int main()
{
	Heap h;

	h.Insert(1);
	h.Insert(2);
	h.Insert(3);
	h.Insert(4);
	h.Insert(5);

	std::cout << std::endl << "---------------" << std::endl;
	std::cout << h.Pop();
	std::cout << h.Pop();
	std::cout << h.Pop();
	std::cout << h.Pop();
	std::cout << h.Pop();

	h.Print();

	std::cout << std::endl;
	std::cout << std::endl;

	std::vector<int> v{ 1,2,3,4,5 };

	// Max Heap
	std::make_heap(v.begin(), v.end());
	for (auto& e : v)
	{
		std::cout << e << std::endl;
	}
	std::cout << "---------------" << std::endl;

	// 삭제 및 출력( 정렬 )
	while (!v.empty())
	{
		std::cout << v.front() << std::endl;
		std::pop_heap(v.begin(), v.end());
		v.pop_back();
	}
	std::cout << "---------------" << std::endl;
	
	// Min Heap
	v = { 4,2,5,1,3 };
	std::make_heap(v.begin(), v.end(), std::greater<>());
	for (auto& e : v)
	{
		std::cout << e << std::endl;
	}
}