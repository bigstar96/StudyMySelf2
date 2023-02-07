#include <iostream>

// 자동 메모리 할당 (Autmatic Memory Allocation)
// 지역 변수(Local Variable), 함수 매개변수(Parameter)등은 타입으로 객체를 만들면 자동으로 타입의 크기만큼 메모리가 배정됩니다.
// 이 친구들의 생존주기(Life Cycle)는 블록{에서 시작되고 }에서 끝납니다. 변수의 범위(Scope)에서도 언급

// 정적 메모리 할당(Static Memory Allocation)
// 한번 만들어지면 끝까지 살아남는다는 의미로 정적(static)이라고 부릅니다. 즉 전역변수 및 정적변수들이 이런 형태가 됩니다.

// 동적 메모리 할당(Dynamic Memory Allocation)
// 동적 즉, 프로그래머가 필요할 때 만들고 제거할 수 있는 형태를 말합니다.
// 이 것이 바로 포인터의 핵심 기능으로, 이 기능 때문에 C 라는 언어가 오랫동안 인기 프로그래밍 언어가 될수 있었습니다.
// 이후의 언어들은 모두 이러한 컨셉 위에서 설계되어 있습니다.



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