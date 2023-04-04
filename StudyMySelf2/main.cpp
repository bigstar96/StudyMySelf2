#include <iostream>

#include <thread>
#include <mutex>

std::mutex gMutex;

void PrintInt()
{
	/*for (int i = 0; i < 500; ++i)
	{
		gMutex.lock();
		std::cout << "job1 : " << i << std::endl;
		gMutex.unlock();
	}*/

	int i = 0;
	while (i < 500)
	{
		if (gMutex.try_lock())
		{
			std::cout << "job1 : " << i << std::endl;
			++i;
			gMutex.unlock();
		}
		else
		{
			// 대기
		}
	}
}
void PrintAscii()
{
	/*for (int repeat = 0; repeat < 5; ++repeat)
	{
		for (int i = 33; i < 126; ++i)
		{
			gMutex.lock();
			std::cout << "job2 : " << (char)(i) << std::endl;
			gMutex.unlock();
		}
	}*/

	for (int repeat = 0; repeat < 5; ++repeat)
	{
		int i = 33;
		while (i < 126)
		{
			if (gMutex.try_lock())
			{
				std::cout << "job2 : " << (char)(i) << std::endl;
				++i;
				gMutex.unlock();
			}
			else
			{
				// 대기
			}
		}
	}
}

#include <future>
void PrintIntFuture()
{
	for (int i = 0; i < 500; ++i)
	{
		std::cout << "job1 : " << i << std::endl;
	}
}
void PrintAsciiFuture()
{
	for (int repeat = 0; repeat < 5; ++repeat)
	{
		for (int i = 33; i < 126; ++i)
		{
			std::cout << "job2 : " << (char)(i) << std::endl;
		}
	}
}

int main()
{
	/*std::thread job1(PrintInt);
	std::thread job2(PrintAscii);
	job1.join();
	job2.join();

	std::cout << "---모든 작업이 끝났습니다.---" << std::endl;*/

	std::future<void> async1 = std::async(PrintIntFuture);
	std::future<void> async2 = std::async(PrintAsciiFuture);

	std::cout << "---모든 작업이 끝났습니다.---" << std::endl;
	async1.get();
	std::cout << "PrintInt 종료." << std::endl;
	async2.get();
	std::cout << "PrintAscii 종료" << std::endl;


}