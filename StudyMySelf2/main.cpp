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
	std::cout << "Į�� �ֵѷ� " << sword.attackDamage << "��ŭ ���ظ� �־���!" << std::endl;
}

int main()
{
	Sword s(10);
	Warrior w;

	w.AttackWith(s);
}

