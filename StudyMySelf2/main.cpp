#include <iostream>

int Sigma(int (*f)(int x), int m, int n)
{
	int sum = 0;
	for (int k = m; k <= n; ++k)
	{
		sum += f(k);
	}

	return sum;
}

int NormalFunction(int x)
{
	return x;
}

int SquareFunction(int x)
{
	return x * x;
}


class MyFunctions
{
public:
	static int NormalFunction2(int x)
	{
		return x;
	}
	static int SquareFunction2(int x)
	{
		return x * x;
	}
};


using FunctionPtr = int (*)(int);
int Sigma2(FunctionPtr f, int m, int n)
{
	int sum{};
	for (int k = m; k <= n; ++k)
	{
		sum += f(k);
	}
	return sum;
}


using FunctionPtr2 = int (MyFunctions::*)(int);
int Sigma3(MyFunctions& instance, FunctionPtr f, int m, int n)
{
	int sum{};
	for (int k = m; k <= n; ++k)
	{
		sum += f(k);
	}
	return sum;
}


#include "namespaceGame.h"


enum Type { INT, FLOAT, DOUBLE, CHAR };
void TypeSequentialSort(void*, Type type)
{
	switch (type)
	{
		case INT:
			break;
		case FLOAT:
			break;
		case DOUBLE:
			break;
		case CHAR:
			break;
		default:
			break;
	}
}


template <typename T>
T Function(T arg1, T arg2)
{
	T result = arg1 + arg2;
	return result;
}
template<typename S>
void TypeSequentialSort2(S input[], int size)
{
	for (int i = 0; i < size - 1; ++i)
	{
		for (int j = i; j < size; ++j)
		{
			if (input[i] > input[j])
			{
				S temp = input[i];
				input[i] = input[j];
				input[j] = temp;
			}
		}
	}
}
template<typename S>
void TypePrint(S input[], int size)
{
	for (int i = 0; i < size; ++i)
	{
		std::cout << input[i] << " ";
	}
	std::cout << std::endl;
}


struct MonsterList
{

};

int main()
{
	std::cout << Sigma(NormalFunction, 1, 8) << std::endl;
	std::cout << Sigma(SquareFunction, 1, 8) << std::endl;
	std::cout << std::endl;

	std::cout << Sigma2(&MyFunctions::NormalFunction2, 1, 9) << std::endl;
	std::cout << Sigma2(&MyFunctions::SquareFunction2, 1, 9) << std::endl;
	std::cout << std::endl;

	MyFunctions mf;
	std::cout << Sigma3(mf, &MyFunctions::NormalFunction2, 1, 10) << std::endl;
	std::cout << Sigma3(mf, &MyFunctions::SquareFunction2, 1, 10) << std::endl;
	std::cout << std::endl;

	Game::namespacePrint();
	std::cout << std::endl;

	std::cout << Function(2, 3) << std::endl;
	std::cout << Function<float>(2.2f, 3.3f) << std::endl;
	std::cout << std::endl;

	int integerArray[] = { 3,2,1,5,3 };
	float floatArray[] = { 1.0f, 0.3f, 1.1f, 4.f };
	TypeSequentialSort2<int>(integerArray, 5);
	TypePrint<int>(integerArray, 5);
	TypeSequentialSort2<float>(floatArray, 4);
	TypePrint<float>(floatArray, 4);
	std::cout << std::endl;



	return 0;
}