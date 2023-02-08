#include <iostream>	



int main()
{
	int* (*(*fp1)(int))[10];

	// 우선 식별자(Identifier : 변수명, 함수명)을 찾습니다.
	// 변수명의 우른쪽으로 읽기
	//	단 괄호 )가 있다면 우선 순위가 있으니 왼쪽을 읽습니다.
	//	오른쪽으로 읽을 것이 없다면 끝
	// 이제 왼쪽을 읽는다.
	// 기본은 영어로 읽으시는게 편합니다.
	//	* : pointer to
	//	[] : array of
	//	() : function returning

	// 연습
	int nums1[3]{ 1, 2, 3 };
	// 1 : nums
	// 2 : [3]
	// 3 : int
	// 
	// nums is 3-array of integer
	// nums는 3의 크기를 가진 배열로 정수형 원소를 가집니다.

	int x, y, z;
	int* nums2[3]{ &x, &y, &z };
	// 1 : nums
	// 2 : [3]
	// 3 : *
	// 4 : int
	// 
	// nums is 3-array of pointer to integer
	// nums는 3의 크기를 가진 배열로 정수의 포인터를 원소로 가집니다.

	int (*nums3)[3] { array1 };
	// 1 : nums
	// 2 : *
	// 3 : [3]
	// 4 : int
	// 
	// nums is pointer to 3-array of integer
	// nums는 3개의 정수 원소를 가지는 배열 포인터입니다.

	int* (*(*fp1)(int))[10];
	//	식별자			fp1		fp1
	//	)발견 -> 왼쪽	*		is a pointer to
	//	오른쪽			(int)	function has int parameter return
	//	)발견 -> 왼쪽	*		a pointer to
	//	오른쪽			[10]		array of 10
	//	끝 -> 왼쪽		*		pointers to
	//	왼쪽			int		integer
	//	fp는 함수에 대한 포인터로 int를 매개변수로 가지고 정수에 대한 포인터들 10개의 배열에 대한 포인터를 반환하는 함수입니다.
	
	int* (*(*arr[5])())();
	//	식별자	arr		arr is
	//	오른쪽	[5]		array of 5
	//	)->왼쪽	*		pointer to
	//	오른쪽	()		functions return
	//	왼쪽	*		pointer to
	//	오른쪽	()		function return
	//	왼쪽	*		pointer to
	//	왼쪽	int		int
	// arr은 함수 포인터 5개의 배열로, 해당 함수는 다른 함수 포인터를 반환하는데
	// 그 함수는 정수에 대한 포인터를 반환하는 함수입니다.

}