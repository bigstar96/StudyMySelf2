#include <iostream>

class Sword;

class Warrior
{
public:
	void AttackWith(Sword& sword);
	
};

class Sword
{
private:
	int attackDamage;
	
public:
	Sword(int damage) : attackDamage{ damage } {}

	friend void Warrior::AttackWith(Sword& sword);
};

void Warrior::AttackWith(Sword& sword)
{
	std::cout << "칼을 휘둘러 " << sword.attackDamage << "만큼 피해를 주었다!" << std::endl;
}

int main()
{
	Sword s(10);
	Warrior w;

	w.AttackWith(s);
}

