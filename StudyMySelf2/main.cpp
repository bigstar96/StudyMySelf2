#include <iostream>

int Square(int);

using namespace std;

int main()
{
	std::cout << Square(2) << std::endl;

	cout << pow(3, 4) << endl;
}

int Square(int x)
{
	return x * x;
}