#include <iostream>

int Square(int);

int main()
{
	std::cout << Square(2) << std::endl;

}

int Square(int x)
{
	return x * x;
}