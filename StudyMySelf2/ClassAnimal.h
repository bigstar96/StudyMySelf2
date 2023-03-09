#pragma once
#include <iostream>


class ClassAnimal
{
protected:
	int mAge;
	int mWeight;

public:
	ClassAnimal();
	ClassAnimal(int age, int weight);
	virtual ~ClassAnimal();
	virtual ClassAnimal* Clone();

	int GetAge() const;
	void SetAge(int age);
	int GetWeight() const;
	void SetWeight(int weight);

	void Sound();
};

