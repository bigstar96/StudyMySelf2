#pragma once
#include "ClassAnimal.h"

class ClassDog : public ClassAnimal
{
public:
	enum BREED
	{
		BEAGLE, DOBERMAN, BERNARD, CHIHUAHUA, HUSKY, RETRIEVER
	};
private:
	BREED mBreed;

public:
	ClassDog();
	ClassDog(int age, int weight, ClassDog::BREED breed);
	~ClassDog();

	ClassDog::BREED GetBreed() const;
	void SetBreed(ClassDog::BREED breed);

	void Sound();
	void Roll();
};

