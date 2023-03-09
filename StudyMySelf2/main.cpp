#include <iostream>

class Developer
{
public:
	std::string	mName;
	int			mAge;

};

class Programmer : public Developer
{
public:
	void Coding();
	void Debugging();
};

class Designer : public Developer
{
public:
	void Documentation();
	void Presentation();
};

class ChiefProgrammer : public Programmer
{
public:
	void Architecture();
	void Scheduling();
};

#include "ClassDog.h"

class ClassA
{
public:
	void func1() { std::cout << "ClassA::func1()" << std::endl; }
	virtual void func2() { std::cout << "ClassA::func2()" << std::endl; }
};

class ClassB : public ClassA
{
public:
	void func1() { std::cout << "ClassB::func1()" << std::endl; }
	void func2() { std::cout << "ClassB::func2()" << std::endl; }
};



int main()
{
	//ClassDog john;

	//john.Sound();
	//john.Roll();

	ClassA* a = new ClassA;
	ClassB* b = new ClassB;

	a->func1();
	a->func2();
	b->func1();
	b->func2();

	std::cout << "-----" << std::endl;
	
	ClassA* p = b;
	p->func1();
	p->func2();

	delete b;
	delete a;
	std::cout << "-----" << std::endl;

	ClassDog john2(1, 1, ClassDog::BREED::HUSKY);
	john2.Sound();
	john2.Roll();

	std::cout << "------------" << std::endl;
	ClassAnimal* clone = john2.Clone();

	std::cout << "Clone's Age is " << clone->GetAge() << std::endl;
	clone->Sound();

	delete clone;
}