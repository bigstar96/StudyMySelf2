#include <iostream>

class MyClass
{
public:
	int mValue1;
	int mValue2;

	MyClass() : MyClass(1, 1)
	{}
	MyClass(int v1, int v2) : mValue1{ v1 }, mValue2{ v2 }
	{}

	void SetValue(int x)
	{
		mValue1 = x;
	}

	void DoNothing()
	{

	}
};



int main()
{
	MyClass c1;
	MyClass c2(2, 2);
	MyClass c3{ 3,3 };

	c1.mValue1 = 10;
}