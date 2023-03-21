#include "STL_vector.h"

void AddvectorStudent(std::vector<vectorStudent>& vector)
{
	std::cout << "��ȣ �̸� ���� : ";
	vectorStudent newStudent;
	if (std::cin >> newStudent.V_mNumber >> newStudent.V_mName >> newStudent.V_mScore)
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
			return elem.V_mNumber == newStudent.V_mNumber;
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
			[&](auto& elem)-> bool { return elem.V_mNumber == num; }));
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
		std::cout << itr->V_mNumber << " - " << itr->V_mName << " : " << itr->V_mScore << std::endl;
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
		{return accum += elem.V_mScore; }
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
		average += elem.V_mScore;
	}
	average /= vector.size();
	std::for_each(vector.begin(), vector.end(),
		[&](auto& elem) {
			if (elem.V_mScore >= average)
			{
				elem.Print();
			}
		});
}

/*
#include <iostream>

// vector vs list vs map
// vector - �迭 ������ �ʿ��� ��� (random access), �����Ͱ� ���� ���
// list - �߰����� ������ ���� �Ͼ�� ���, �����Ͱ� ���� ���
// map - ���� �����͸� ������ �˻��� ��, < key, value > ��

// { 1, "Kim", 80 },
// { 2, "Lee", 20 },
// { 3, "Park", 50 },
// { 4, "Choi", 30 }

// 1. �л� �߰�
// 2. �л� ���� (��ȣ)
// 3. ��ü �л� ���
// 4. ��� �� ���� ���
// 5. ��� �̻� �л� ���
// 6. ����

#include "STL_vector.h"

int main()
{
	std::vector<vectorStudent> students = {
		{1, "Kim", 80},
		{2, "Lee", 20},
		{3, "Park", 50},
		{4, "Choi", 30}
	};

	bool isExit{ false };
	while (!isExit)
	{
		std::cout << "1. �л� �߰�\n";
		std::cout << "2. �л� ����(��ȣ)\n";
		std::cout << "3. ��ü �л� ���\n";
		std::cout << "4. ��� �� ���� ���\n";
		std::cout << "5. ��� �̻� �л� ���\n";
		std::cout << "6. ����\n";

		std::cout << std::endl;
		std::cout << " > ";
		int command;
		std::cin >> command;
		switch (command)
		{
			case 1:
				AddvectorStudent(students);
				break;

			case 2:
				DeletevectorStudent(students);
				break;

			case 3:
				VectorAllStudentPrint(students);
				break;

			case 4:
				VectorAverageTotalPrint(students);
				break;

			case 5:
				VectorAboveAveragePrint(students);
				break;

			case 6:
				isExit = true;
				break;
			default:
				std::cout << "�Էµ� ���ڰ� ������ �ֽ��ϴ�." << std::endl;
				std::cout << "������ ���� ���α׷��� �����մϴ�." << std::endl;
				isExit = true;
				break;
		}
	}
}
*/