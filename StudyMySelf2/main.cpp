#include <iostream>
#include "DateClass.h"
#include "Student.h"

class MyClass
{
public:
	MyClass()
	{
		std::cout << "[Constructor]" << std::endl;
	}
	~MyClass()
	{
		std::cout << "[Destructor]" << std::endl;
	}
};

class Quest
{
private:
	int mID;
	int mExp;

public:
	Quest(int id = 1, int exp = 1) :
		mID{ id }, mExp{ exp }
	{
	}

	void Print()
	{
		std::cout << "QuestID : " << mID << std::endl;
		std::cout << "EXP : " << mExp << std::endl;
	}
};

int main()
{
	DateClass dc{ 2023,02,24 };
	dc.Print();

	Student student{ "Hello World" };
	student.Print();
}

