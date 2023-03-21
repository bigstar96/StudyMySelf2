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
				std::cout << "�Էµ� ���ڰ� ������ �ֽ��ϴ�." << std::endl;
				std::cout << "������ ���� ���α׷��� �����մϴ�." << std::endl;
				isExit = true;
				break;
		}
	}

	return 0;
}