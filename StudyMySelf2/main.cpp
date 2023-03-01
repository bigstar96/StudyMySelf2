#include <iostream>

class Sword
{
private:
	int mAttackDamage;

public:
	Sword(int damage) : mAttackDamage{ damage } {}
	friend void DamageBuff(Sword& sword);
};

void DamageBuff(Sword& sword)
{
	int oldDamage = sword.mAttackDamage;
	sword.mAttackDamage = oldDamage * 2;
	std::cout << "검을 강화했다." << oldDamage << "->" << sword.mAttackDamage << std::endl;
}



int main()
{
	Sword shortSword(10);
	DamageBuff(shortSword);
}


