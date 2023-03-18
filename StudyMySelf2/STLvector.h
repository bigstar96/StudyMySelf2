#pragma once
#include <iostream>
#include <vector>

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

class vectorStudent
{
public:
	int mNumber;
	std::string mName;
	int mScore;

	void Print()
	{
		std::cout <<
			"(" << mNumber << ") " <<
			mName << " : " <<
			mScore << std::endl;
	}
};

void AddvectorStudent(std::vector<vectorStudent>& vector);
void DeletevectorStudent(std::vector<vectorStudent>& vector);
void VectorAllStudentPrint(std::vector<vectorStudent>& vector);
void VectorAverageTotalPrint(std::vector<vectorStudent>& vector);
void VectorAboveAveragePrint(std::vector<vectorStudent>& vector);
