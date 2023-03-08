#include "ClassDog.h"

ClassDog::ClassDog() : mBreed{ BREED::RETRIEVER }
{
	std::cout << "[Dog] Created!" << std::endl;
}

ClassDog::ClassDog(int age, int weight, ClassDog::BREED breed) :
	ClassAnimal(age, weight),
	mBreed{ breed }
{
	std::cout << "[Dog(int, int, BREED)] Created!" << std::endl;
}

ClassDog::~ClassDog()
{
	std::cout << "[Dog] Destroyed!" << std::endl;
}

ClassDog::BREED ClassDog::GetBreed() const
{
	return mBreed;
}

void ClassDog::SetBreed(ClassDog::BREED breed)
{
	mBreed = breed;
}

void ClassDog::Sound()
{
	ClassAnimal::Sound();
	std::cout << "Woof Woof..." << std::endl;
}

void ClassDog::Roll()
{
	std::cout << "Rolling..." << std::endl;
}
