#pragma once
#include <iostream>
#include <vector>

// { 1, "Kim", 80 },
// { 2, "Lee", 20 },
// { 3, "Park", 50 },
// { 4, "Choi", 30 }

// 1. 학생 추가
// 2. 학생 제거 (번호)
// 3. 전체 학생 출력
// 4. 평균 및 총점 출력
// 5. 평균 이상 학생 출력
// 6. 종료

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
