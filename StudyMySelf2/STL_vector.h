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
	int V_mNumber;
	std::string V_mName;
	int V_mScore;

	void Print()
	{
		std::cout <<
			"(" << V_mNumber << ") " <<
			V_mName << " : " <<
			V_mScore << std::endl;
	}
	vectorStudent(){}
};


void AddvectorStudent(std::vector<vectorStudent>& vector);
void DeletevectorStudent(std::vector<vectorStudent>& vector);
void VectorAllStudentPrint(std::vector<vectorStudent>& vector);
void VectorAverageTotalPrint(std::vector<vectorStudent>& vector);
void VectorAboveAveragePrint(std::vector<vectorStudent>& vector);
