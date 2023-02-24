#include "Cat.h"
#include <iostream>

void Cat::Meow() const
{
    std::cout << "Meow..." << std::endl;
}

int Cat::GetAge()
{
    return mAge;
}

void Cat::SetAge(int age)
{
    mAge = age;
}
