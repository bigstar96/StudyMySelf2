#include "Student.h"

Student::Student(std::string name, int score = 0) :
	mName{ name }, mScore{ score }
{
}

void Student::Print()
{
	std::cout << mName << " : " << mScore << std::endl;
}
