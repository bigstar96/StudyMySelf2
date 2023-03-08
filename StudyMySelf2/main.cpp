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

int main()
{
	ClassDog john;

	john.Sound();
	john.Roll();
}