#pragma once
#include <iostream>

class Student
{
	std::string mName;
	int V_mScore;

public:
	Student(std::string name, int score);
	void Print();
};

