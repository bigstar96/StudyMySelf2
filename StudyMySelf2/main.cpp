#include <iostream>	



int main()
{
	int* (*(*fp1)(int))[10];

	// �켱 �ĺ���(Identifier : ������, �Լ���)�� ã���ϴ�.
	// �������� �츥������ �б�
	//	�� ��ȣ )�� �ִٸ� �켱 ������ ������ ������ �н��ϴ�.
	//	���������� ���� ���� ���ٸ� ��
	// ���� ������ �д´�.
	// �⺻�� ����� �����ô°� ���մϴ�.
	//	* : pointer to
	//	[] : array of
	//	() : function returning

	// ����
	int nums1[3]{ 1, 2, 3 };
	// 1 : nums
	// 2 : [3]
	// 3 : int
	// 
	// nums is 3-array of integer
	// nums�� 3�� ũ�⸦ ���� �迭�� ������ ���Ҹ� �����ϴ�.

	int x, y, z;
	int* nums2[3]{ &x, &y, &z };
	// 1 : nums
	// 2 : [3]
	// 3 : *
	// 4 : int
	// 
	// nums is 3-array of pointer to integer
	// nums�� 3�� ũ�⸦ ���� �迭�� ������ �����͸� ���ҷ� �����ϴ�.

	int (*nums3)[3] { array1 };
	// 1 : nums
	// 2 : *
	// 3 : [3]
	// 4 : int
	// 
	// nums is pointer to 3-array of integer
	// nums�� 3���� ���� ���Ҹ� ������ �迭 �������Դϴ�.

	int* (*(*fp1)(int))[10];
	//	�ĺ���			fp1		fp1
	//	)�߰� -> ����	*		is a pointer to
	//	������			(int)	function has int parameter return
	//	)�߰� -> ����	*		a pointer to
	//	������			[10]		array of 10
	//	�� -> ����		*		pointers to
	//	����			int		integer
	//	fp�� �Լ��� ���� �����ͷ� int�� �Ű������� ������ ������ ���� �����͵� 10���� �迭�� ���� �����͸� ��ȯ�ϴ� �Լ��Դϴ�.
	
	int* (*(*arr[5])())();
	//	�ĺ���	arr		arr is
	//	������	[5]		array of 5
	//	)->����	*		pointer to
	//	������	()		functions return
	//	����	*		pointer to
	//	������	()		function return
	//	����	*		pointer to
	//	����	int		int
	// arr�� �Լ� ������ 5���� �迭��, �ش� �Լ��� �ٸ� �Լ� �����͸� ��ȯ�ϴµ�
	// �� �Լ��� ������ ���� �����͸� ��ȯ�ϴ� �Լ��Դϴ�.

}