#include <iostream>	



int main()
{
	const int a;	// a is int which is constant
					// a�� �����̸� ������Դϴ�.
	int const b;	// b is constant int
					// b�� ����� �����Դϴ�.

	const int* pa;	// pa is pointer to int which is constant
					// pa�� �����ͷ� ������ ����Ű�� �� ������ ����Դϴ�.
	int* const pb;	// pb is constant pointer to int
					// pb�� ��� �����ͷ� ������ ����ŵ�ϴ�.
	int const* pc;	// pc is pointer to constant int
					// pb�� ��� ������ ����Ű�� �������Դϴ�.


	*pa = 1;		// pa�� ����Ű�� ������ ����̹Ƿ� ���� ������ �� �����ϴ�.
	pa++;			// pa�� �Ϲ� �������̹Ƿ� �̵� �����մϴ�.
	*pb = 1;		// pb�� �Ϲ� ������ ����Ű�Ƿ� ���� ������ �� �ֽ��ϴ�.
	pb++;			// pb�� ��� �������̹Ƿ� �̵� �Ұ����մϴ�.
	*pc = 1;		// pc�� ��� ������ ����Ű�Ƿ� ���� ������ �� �����ϴ�.
	pc++;			// pc�� �Ϲ� �������̹Ƿ� �̵� �����մϴ�.
}