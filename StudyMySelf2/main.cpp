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
		std::cout << "칼을 휘둘러 " << sword.mAttackDamage << "만큼 피해를 주었다!" << std::endl;
	}
};

int main()
{
	Sword shorSword{ 10 };
	Warrior w;

	w.AttackWith(shorSword);
}