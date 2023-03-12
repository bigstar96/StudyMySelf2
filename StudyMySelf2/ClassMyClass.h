#pragma once
#include <iostream>

template<typename T>
class ClassMyClass
{
	T mValue;

public:
	void TypeFunction(T arg);
};

// 선언과 구현을 무조건 분리해야될때 .hpp 를 만들어 옮긴다.
#include "ClassMyClass.hpp"
