#include <iostream>

class Sword
{
	friend class Warrior;

private:
	int mAttackDamage;
public:
	Sword(int damage) : mAttackDamage{ damage } {}

};

class Warrior
{
public:
	void AttackWith(Sword& sword)
	{
		std::cout << "Į�� �ֵѷ� " << sword.mAttackDamage << "��ŭ ���ظ� �־���!" << std::endl;
	}
};

int main()
{
	Sword shorSword{ 10 };
	Warrior w;

	w.AttackWith(shorSword);
}