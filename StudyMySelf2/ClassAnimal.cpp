#include "ClassAnimal.h"

ClassAnimal::ClassAnimal() : mAge{ 1 }, mWeight{ 1 }
{
	std::cout << "[Animal] Created!" << std::endl;
}

ClassAnimal::ClassAnimal(int age, int weight) : mAge{ age }, mWeight{ weight }
{
	std::cout << "[Animal(int, int)] Created!" << std::endl;
}

ClassAnimal::~ClassAnimal()
{
	std::cout << "[Animal] Destoyed!" << std::endl;
}

int ClassAnimal::GetAge() const
{
	return mAge;
}

void ClassAnimal::SetAge(int age)
{
	mAge = age;
}

int ClassAnimal::GetWeight() const
{
	return mWeight;
}

void ClassAnimal::SetWeight(int weight)
{
	mWeight = weight;
}

void ClassAnimal::Sound()
{
	std::cout << "Make a noise..." << std::endl;
}
