#include <iostream>

void BMI()
{
	double height{};
	double weight{};
	double bmi{};

	std::cout << "Ű(cm)�� �Է��ϼ��� : ";
	std::cin >> height;
	std::cout << "ü��(kg)�� �Է��ϼ��� : ";
	std::cin >> weight;

	// bmi = ������ / (Ű * Ű)
	// ������(kg),Ű(m)

	height /= 100;
	bmi = weight / (height * height);

	std::cout << "Ű : " << height << ", ������ : " << weight << "�� ���� BMI : " << bmi << std::endl;

	if (bmi <= 18.5)
	{
		std::cout << "��ü���Դϴ�." << std::endl;
	}
	else if (bmi < 25)
	{
		std::cout << "�����Դϴ�." << std::endl;
	}
	else if (bmi < 30)
	{
		std::cout << "��ü���Դϴ�." << std::endl;
	}
	else
	{
		std::cout << "�������Դϴ�." << std::endl;
	}
}

int main()
{
	BMI();
}
