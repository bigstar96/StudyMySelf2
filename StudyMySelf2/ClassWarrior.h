#pragma once
#include "ClassCharacter.h"

class ClassWarrior : public ClassCharacter
{
public:
	ClassWarrior();
	~ClassWarrior();
	void Attack() const;
	void DoubleSlash() const;
	void Dead() const;
};

