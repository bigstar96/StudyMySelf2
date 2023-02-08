#include <iostream>	



int main()
{
	const int a;	// a is int which is constant
					// a는 정수이며 상수형입니다.
	int const b;	// b is constant int
					// b는 상수형 정수입니다.

	const int* pa;	// pa is pointer to int which is constant
					// pa는 포인터로 정수를 가리키며 그 정수는 상수입니다.
	int* const pb;	// pb is constant pointer to int
					// pb는 상수 포인터로 정수를 가리킵니다.
	int const* pc;	// pc is pointer to constant int
					// pb는 상수 정수를 가리키는 포인터입니다.


	*pa = 1;		// pa가 가리키는 정수는 상수이므로 값을 변경할 수 없습니다.
	pa++;			// pa는 일반 포인터이므로 이동 가능합니다.
	*pb = 1;		// pb는 일반 정수를 가리키므로 값을 변경할 수 있습니다.
	pb++;			// pb는 상수 포인터이므로 이동 불가능합니다.
	*pc = 1;		// pc는 상수 정수를 가리키므로 값을 변경할 수 없습니다.
	pc++;			// pc는 일반 포인터이므로 이동 가능합니다.
}