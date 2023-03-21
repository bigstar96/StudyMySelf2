#include "STL_vector.h"

void AddvectorStudent(std::vector<vectorStudent>& vector)
{
	std::cout << "번호 이름 점수 : ";
	vectorStudent newStudent;
	if (std::cin >> newStudent.V_mNumber >> newStudent.V_mName >> newStudent.V_mScore)
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
			return elem.V_mNumber == newStudent.V_mNumber;
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
			[&](auto& elem)-> bool { return elem.V_mNumber == num; }));
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
	std::cout << "총점 : " << num << std::endl;
	std::cout << "평균 : " << num / count << std::endl;*/

	int total{ 0 };
	total = std::accumulate(
		vector.begin(),
		vector.end(),
		0,
		[](int accum, auto& elem)
		{return accum += elem.V_mScore; }
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
// vector - 배열 접근이 필요한 경우 (random access), 데이터가 적은 경우
// list - 중간에서 삭제가 자주 일어나는 경우, 데이터가 적은 경우
// map - 많은 데이터를 빠르게 검색할 때, < key, value > 쌍

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
		std::cout << "1. 학생 추가\n";
		std::cout << "2. 학생 제거(번호)\n";
		std::cout << "3. 전체 학생 출력\n";
		std::cout << "4. 평균 및 총점 출력\n";
		std::cout << "5. 평균 이상 학생 출력\n";
		std::cout << "6. 종료\n";

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
				std::cout << "입력된 문자가 오류가 있습니다." << std::endl;
				std::cout << "오류로 인해 프로그램을 종료합니다." << std::endl;
				isExit = true;
				break;
		}
	}
}
*/