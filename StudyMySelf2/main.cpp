#include <iostream>
#include "Sort.h"


int main()
{
	const int size = 5;
	int array1[size]{ 1,7,2,3,8 };


	SequentialSort(array1, size);
	PrintArray(array1, size);
	std::cout << std::endl;

	int array2[size]{ 1,8,2,7,2 };
	SelectionSort(array2, size);
	PrintArray(array2, size);
	std::cout << std::endl;

	int array3[size]{ 3,5,6,2,1 };
	BubbleSort(array3, size);
	PrintArray(array3, size);
	std::cout << std::endl;

	int array4[size]{ 2,5,6,4,1 };
	InsertionSort(array4, size);
	PrintArray(array4, size);
	std::cout << std::endl;

	int array5[size]{ 7,9,3,4,1 };
	int tempArray5[size]{};
	MergeSort(array5, 0, size - 1, tempArray5);
	PrintArray(array5, size);
	std::cout << std::endl;

	int array6[size]{ 5,3,7,8,2 };
	QuickSort(array6, 0, size - 1);
	PrintArray(array6, size);
	std::cout << std::endl;


}