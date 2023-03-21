#include "Student.h"

Student::Student(std::string name, int score = 0) :
	mName{ name }, V_mScore{ score }
{
}

void Student::Print()
{
	std::cout << mName << " : " << V_mScore << std::endl;
}
