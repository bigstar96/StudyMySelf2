#include "ClassWarrior.h"

ClassWarrior::ClassWarrior() : ClassCharacter()
{
	std::cout << "+[Warrior] created" << std::endl;
}

ClassWarrior::~ClassWarrior()
{
	std::cout << "-[Warrior] destroyed" << std::endl;
}

void ClassWarrior::Attack() const
{
	std::cout << "\t전사는 검을 휘둘렀다! " << std::endl;
}

void ClassWarrior::DoubleSlash() const
{
	std::cout << "\t전사는 검을 두번 휘둘렀다!" << std::endl;
}

void ClassWarrior::Dead() const
{
	ClassCharacter::Dead();
	std::cout << "\t전사는 죽었습니다." << std::endl;
}
