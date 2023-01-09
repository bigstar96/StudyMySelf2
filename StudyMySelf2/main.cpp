#include <iostream>

void BMI()
{
	double height{};
	double weight{};
	double bmi{};

	std::cout << "키(cm)를 입력하세요 : ";
	std::cin >> height;
	std::cout << "체중(kg)를 입력하세요 : ";
	std::cin >> weight;

	// bmi = 몸무게 / (키 * 키)
	// 몸무게(kg),키(m)

	height /= 100;
	bmi = weight / (height * height);

	std::cout << "키 : " << height << ", 몸무게 : " << weight << "에 대한 BMI : " << bmi << std::endl;

	if (bmi <= 18.5)
	{
		std::cout << "저체중입니다." << std::endl;
	}
	else if (bmi < 25)
	{
		std::cout << "정상입니다." << std::endl;
	}
	else if (bmi < 30)
	{
		std::cout << "과체중입니다." << std::endl;
	}
	else
	{
		std::cout << "비정상입니다." << std::endl;
	}
}

int main()
{
	BMI();
}
