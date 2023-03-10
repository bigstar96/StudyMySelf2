#pragma once
#include <iostream>

class ClassCharacter
{
protected:
	int mHP;

public:
	ClassCharacter();
	virtual ~ClassCharacter();

public:
	virtual void Attack() const = 0;
	virtual void Dead() const = 0;
};

