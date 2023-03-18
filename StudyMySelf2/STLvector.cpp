#include "STLvector.h"

void AddvectorStudent(std::vector<vectorStudent>& vector)
{
	std::cout << "��ȣ �̸� ���� : ";
	vectorStudent newStudent;
	if (std::cin >> newStudent.mNumber >> newStudent.mName >> newStudent.mScore)
	{
		for (auto& elem : vector)
		{
			if (elem.mNumber == newStudent.mNumber)
			{
				std::cout << "�ߺ��� �л� ��ȣ�Դϴ�.\n";
				return;
			}
		}
		vector.push_back(newStudent);
	}
	else
	{
		std::cout << "�߸��� �Է��Դϴ�.\n";
	}
}

void DeletevectorStudent(std::vector<vectorStudent>& vector)
{
	std::cout << "������ ��ȣ�� �Է��ϼ��� : ";
	int num;
	if (std::cin >> num)
	{
		for (auto itr = vector.begin(); itr != vector.end(); ++itr)
		{
			if (itr->mNumber == num)
			{
				vector.erase(itr);
				break;
			}
		}
	}
	else
	{
		std::cout << "�߸��� ��ȣ�Դϴ�.\n";
	}
}

void VectorAllStudentPrint(std::vector<vectorStudent>& vector)
{
	for (auto itr = vector.begin(); itr != vector.end(); ++itr)
	{
		std::cout << itr->mNumber << " - " << itr->mName << " : " << itr->mScore << std::endl;
	}
	std::cout << std::endl;
}

void VectorAverageTotalPrint(std::vector<vectorStudent>& vector)
{
	int num{}, count{};

	for (auto itr = vector.begin(); itr != vector.end(); ++itr)
	{
		num += itr->mScore;
		++count;
	}
	std::cout << "���� : " << num << std::endl;
	std::cout << "��� : " << num / count << std::endl;
}

void VectorAboveAveragePrint(std::vector<vectorStudent>& vector)
{
	int num{}, count{};

	for (auto itr = vector.begin(); itr != vector.end(); ++itr)
	{
		num += itr->mScore;
		++count;
	}

	std::cout << "- ��� �̻� -\t" << "��� : " << num / count << std::endl;
	for (auto itr = vector.begin(); itr != vector.end(); ++itr)
	{
		if (itr->mScore >= num / count)
		{
			std::cout << itr->mNumber << " - " << itr->mName << " : " << itr->mScore << std::endl;
		}
	}
}
