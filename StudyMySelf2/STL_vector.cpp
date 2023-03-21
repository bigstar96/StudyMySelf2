#include "STL_vector.h"

void AddvectorStudent(std::vector<vectorStudent>& vector)
{
	std::cout << "��ȣ �̸� ���� : ";
	vectorStudent newStudent;
	if (std::cin >> newStudent.mNumber >> newStudent.mName >> newStudent.mScore)
	{
		/*for (auto& elem : vector)
		{
			if (elem.mNumber == newStudent.mNumber)
			{
				std::cout << "�ߺ��� �л� ��ȣ�Դϴ�.\n";
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
		std::cout << "�߸��� �Է��Դϴ�.\n";
	}
}

void DeletevectorStudent(std::vector<vectorStudent>& vector)
{
	std::cout << "������ ��ȣ�� �Է��ϼ��� : ";
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

#include <numeric>
void VectorAverageTotalPrint(std::vector<vectorStudent>& vector)
{
	/*int num{}, count{};

	for (auto itr = vector.begin(); itr != vector.end(); ++itr)
	{
		num += itr->mScore;
		++count;
	}
	std::cout << "���� : " << num << std::endl;
	std::cout << "��� : " << num / count << std::endl;*/

	int total{ 0 };
	total = std::accumulate(
		vector.begin(),
		vector.end(),
		0,
		[](int accum, auto& elem)
		{return accum += elem.mScore; }
	);
	std::cout << "���� : " << total <<
		"\n��� : " << total / vector.size() << std::endl;
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

	std::cout << "- ��� �̻� -\t" << "��� : " << num / count << std::endl;
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
