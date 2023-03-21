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