#include <iostream>

#include "STL_map.h"


int main()
{
	std::map<int, STL_mapStudent> students = {
		{1, {"Kim", 80}},
		{2, {"Lee", 20}},
		{3, {"Park", 50}},
		{4, {"Choi", 30}}
	};
	int command = -1;
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
				mapAddStudent(students);
				break;

			case 2:
				mapDeleteStudent(students);
				break;

			case 3:
				mapAllStudentPrint(students);
				break;

			case 4:
				mapAverageTotalPrint(students);
				break;

			case 5:
				mapAboveAveragePrint(students);
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

	return 0;
}