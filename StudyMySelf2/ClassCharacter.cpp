#include "ClassCharacter.h"

ClassCharacter::ClassCharacter() : mHP{ 0 }
{
	std::cout << "+[Character] created" << std::endl;
}

ClassCharacter::~ClassCharacter()
{
	std::cout << "-[Character] destroyed" << std::endl;
}

void ClassCharacter::Attack() const
{
	std::cout << "\tUnknown Attack!" << std::endl;
}

void ClassCharacter::Dead() const
{
	std::cout << "Abstract dead~" << std::endl;
}
