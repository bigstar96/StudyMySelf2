#include "STL_map.h"

std::ostream& operator<< (std::ostream& os, const STL_mapStudent student)
{
	os << student.M_mName << " : " << student.M_mScore << std::endl;
	return os;
}

using Students = std::map<int, STL_mapStudent>;

void mapAddStudent(std::map<int, STL_mapStudent>& container)
{
	std::cout << "번호 이름 점수 : ";
	int number{};
	STL_mapStudent newStudent;
	
	if (std::cin >> number >> newStudent.M_mName >> newStudent.M_mScore)
	{
		auto result = container.insert({ number, newStudent });
		if (!result.second)
		{
			std::cout << "중복된 학생 번호입니다.\n";
			return;
		}
	}
	else
	{
		std::cout << "잘못된 입력입니다.\n";
	}
}

void mapDeleteStudent(std::map<int, STL_mapStudent>& student)
{
	std::cout << "지울 학생의 번호를 입력하세요 : ";
	int num;
	if (std::cin >> num)
	{
		student.erase(num);
	}
	else
	{
		std::cout << "입력한 숫자가 잘못되었습니다. ( 학생 번호가 없거나, 잘못 입력하였습니다.)\n";
	}
}

void mapStudentPrint(std::map<int, STL_mapStudent>::value_type& pair)
{
	std::cout << "(" << pair.first << ")" << pair.second;
}

void mapAllStudentPrint(std::map<int, STL_mapStudent>& container)
{
	for (auto& elem : container)
	{
		mapStudentPrint(elem);
	}
}

void mapAverageTotalPrint(std::map<int, STL_mapStudent>& container)
{
	int total{};
	for (auto& elem : container)
	{
		total += elem.second.M_mScore;
	}
	std::cout << "평균 : " << total/container.size() << "\n" << "총합 : " << total << std::endl;
}

void mapAboveAveragePrint(std::map<int, STL_mapStudent>& container)
{
	int average{};
	for (auto& elem : container)
	{
		average += elem.second.M_mScore;
	}

	average /= container.size();
	std::cout << "평균 : " << average << std::endl;

	for (auto& elem : container)
	{
		if (average <= elem.second.M_mScore)
		{
			std::cout << "(" << elem.first << ")" << elem.second;
		}
	}
}

