#include <iostream>

// �ڵ� �޸� �Ҵ� (Autmatic Memory Allocation)
// ���� ����(Local Variable), �Լ� �Ű�����(Parameter)���� Ÿ������ ��ü�� ����� �ڵ����� Ÿ���� ũ�⸸ŭ �޸𸮰� �����˴ϴ�.
// �� ģ������ �����ֱ�(Life Cycle)�� ���{���� ���۵ǰ� }���� �����ϴ�. ������ ����(Scope)������ ���

// ���� �޸� �Ҵ�(Static Memory Allocation)
// �ѹ� ��������� ������ ��Ƴ��´ٴ� �ǹ̷� ����(static)�̶�� �θ��ϴ�. �� �������� �� ������������ �̷� ���°� �˴ϴ�.

// ���� �޸� �Ҵ�(Dynamic Memory Allocation)
// ���� ��, ���α׷��Ӱ� �ʿ��� �� ����� ������ �� �ִ� ���¸� ���մϴ�.
// �� ���� �ٷ� �������� �ٽ� �������, �� ��� ������ C ��� �� �������� �α� ���α׷��� �� �ɼ� �־����ϴ�.
// ������ ������ ��� �̷��� ���� ������ ����Ǿ� �ֽ��ϴ�.



int main()
{
	int* buffer1, * buffer2;
	buffer1 = (int*)calloc(100, sizeof(int));
	buffer2 = (int*)malloc(100 * sizeof(int));
	if (buffer1 && buffer2)
	{
		std::cout << buffer1[2] << ", " << *buffer2 << std::endl;

		free(buffer1);
		free(buffer2);
	}
}