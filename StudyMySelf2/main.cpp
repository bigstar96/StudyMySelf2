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