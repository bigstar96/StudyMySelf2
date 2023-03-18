#include "STLvector.h"

void AddvectorStudent(std::vector<vectorStudent>& vector)
{
	std::cout << "번호 이름 점수 : ";
	vectorStudent newStudent;
	if (std::cin >> newStudent.mNumber >> newStudent.mName >> newStudent.mScore)
	{
		for (auto& elem : vector)
		{
			if (elem.mNumber == newStudent.mNumber)
			{
				std::cout << "중복된 학생 번호입니다.\n";
				return;
			}
		}
		vector.push_back(newStudent);
	}
	else
	{
		std::cout << "잘못된 입력입니다.\n";
	}
}

void DeletevectorStudent(std::vector<vectorStudent>& vector)
{
	std::cout << "삭제할 번호를 입력하세요 : ";
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
		std::cout << "잘못된 번호입니다.\n";
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
	std::cout << "총점 : " << num << std::endl;
	std::cout << "평균 : " << num / count << std::endl;
}

void VectorAboveAveragePrint(std::vector<vectorStudent>& vector)
{
	int num{}, count{};

	for (auto itr = vector.begin(); itr != vector.end(); ++itr)
	{
		num += itr->mScore;
		++count;
	}

	std::cout << "- 평균 이상 -\t" << "평균 : " << num / count << std::endl;
	for (auto itr = vector.begin(); itr != vector.end(); ++itr)
	{
		if (itr->mScore >= num / count)
		{
			std::cout << itr->mNumber << " - " << itr->mName << " : " << itr->mScore << std::endl;
		}
	}
}
