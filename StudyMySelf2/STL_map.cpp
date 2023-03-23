#include "STL_map.h"

std::ostream& operator<< (std::ostream& os, const STL_mapStudent student)
{
	os << student.M_mName << " : " << student.M_mScore << std::endl;
	return os;
}

using Students = std::map<int, STL_mapStudent>;

void mapAddStudent(std::map<int, STL_mapStudent>& container)
{
	std::cout << "��ȣ �̸� ���� : ";
	int number{};
	STL_mapStudent newStudent;
	
	if (std::cin >> number >> newStudent.M_mName >> newStudent.M_mScore)
	{
		auto result = container.insert({ number, newStudent });
		if (!result.second)
		{
			std::cout << "�ߺ��� �л� ��ȣ�Դϴ�.\n";
			return;
		}
	}
	else
	{
		std::cout << "�߸��� �Է��Դϴ�.\n";
	}
}

void mapDeleteStudent(std::map<int, STL_mapStudent>& student)
{
	std::cout << "���� �л��� ��ȣ�� �Է��ϼ��� : ";
	int num;
	if (std::cin >> num)
	{
		student.erase(num);
	}
	else
	{
		std::cout << "�Է��� ���ڰ� �߸��Ǿ����ϴ�. ( �л� ��ȣ�� ���ų�, �߸� �Է��Ͽ����ϴ�.)\n";
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
	std::cout << "��� : " << total/container.size() << "\n" << "���� : " << total << std::endl;
}

void mapAboveAveragePrint(std::map<int, STL_mapStudent>& container)
{
	int average{};
	for (auto& elem : container)
	{
		average += elem.second.M_mScore;
	}

	average /= container.size();
	std::cout << "��� : " << average << std::endl;

	for (auto& elem : container)
	{
		if (average <= elem.second.M_mScore)
		{
			std::cout << "(" << elem.first << ")" << elem.second;
		}
	}
}

