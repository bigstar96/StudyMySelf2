#pragma once
#include <iostream>

template<typename T>
class ClassMyClass
{
	T mValue;

public:
	void TypeFunction(T arg);
};

// ����� ������ ������ �и��ؾߵɶ� .hpp �� ����� �ű��.
#include "ClassMyClass.hpp"
