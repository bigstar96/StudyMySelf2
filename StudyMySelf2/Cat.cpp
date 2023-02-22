#include "Cat.h"
#include <iostream>

void Cat::Meow()
{
    std::cout << "Meow..." << std::endl;
}

int Cat::GetAge()
{
    return mAge;
}
