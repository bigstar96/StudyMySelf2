#include "STL_vector.h"

void AddvectorStudent(std::vector<vectorStudent>& vector)
{
	std::cout << "번호 이름 점수 : ";
	vectorStudent newStudent;
	if (std::cin >> newStudent.mNumber >> newStudent.mName >> newStudent.mScore)
	{
		/*for (auto& elem : vector)
		{
			if (elem.mNumber == newStudent.mNumber)
			{
				std::cout << "중복된 학생 번호입니다.\n";
				return;
			}
		}*/
		[&](auto& elem)-> bool {
			return elem.mNumber == newStudent.mNumber;
		};
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
		/*for (auto itr = vector.begin(); itr != vector.end(); ++itr)
		{
			if (itr->mNumber == num)
			{
				vector.erase(itr);
				break;
			}
		}*/

		vector.erase(std::remove_if(vector.begin(), vector.end(),
			[&](auto& elem)-> bool { return elem.mNumber == num; }));
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

#include <numeric>
void VectorAverageTotalPrint(std::vector<vectorStudent>& vector)
{
	/*int num{}, count{};

	for (auto itr = vector.begin(); itr != vector.end(); ++itr)
	{
		num += itr->mScore;
		++count;
	}
	std::cout << "총점 : " << num << std::endl;
	std::cout << "평균 : " << num / count << std::endl;*/

	int total{ 0 };
	total = std::accumulate(
		vector.begin(),
		vector.end(),
		0,
		[](int accum, auto& elem)
		{return accum += elem.mScore; }
	);
	std::cout << "총점 : " << total <<
		"\n평균 : " << total / vector.size() << std::endl;
}

#include <algorithm>

void VectorAboveAveragePrint(std::vector<vectorStudent>& vector)
{
	/*int num{}, count{};

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
	}*/

	int average{ 0 };
	for (auto& elem : vector)
	{
		average += elem.mScore;
	}
	average /= vector.size();
	std::for_each(vector.begin(), vector.end(),
		[&](auto& elem) {
			if (elem.mScore >= average)
			{
				elem.Print();
			}
		});
}
