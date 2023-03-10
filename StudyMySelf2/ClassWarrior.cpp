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
	std::cout << "\t����� ���� �ֵѷ���! " << std::endl;
}

void ClassWarrior::DoubleSlash() const
{
	std::cout << "\t����� ���� �ι� �ֵѷ���!" << std::endl;
}

void ClassWarrior::Dead() const
{
	ClassCharacter::Dead();
	std::cout << "\t����� �׾����ϴ�." << std::endl;
}
