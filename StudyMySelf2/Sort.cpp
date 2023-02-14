#include "Sort.h"

void PrintArray(int input[], int size)
{
	for (int i = 0; i < size; ++i)
	{
		std::cout << input[i] << " ";
	}
}



void Swap(int& value1, int& value2)
{
	int temp = value1;
	value1 = temp;
	value1 = value2;
	value2 = temp;
}


void SequentialSort(int input[], int size)
{
	for (int i = 0; i < size; ++i)
	{
		for (int j = i + 1; j < size; ++j)
		{
			if (input[i] > input[j])
			{
				Swap(input[i], input[j]);
			}
		}
	}
}


void SelectionSort(int input[], int size)
{
	for (int i = 0; i < size; ++i)
	{
		int minIndex = i;
		for (int j = i; j < size; ++j)
		{
			if (input[minIndex] > input[j])
			{
				minIndex = j;
			}
		}
		if (minIndex != i)
		{
			Swap(input[i], input[minIndex]);
		}
	}
}


void BubbleSort(int input[], int size)
{
	for (int phase = 0; phase < size - 1; ++phase)
	{
		for (int k = 0; k < size - phase - 1; ++k)
		{
			if (input[k] > input[k + 1])
			{
				Swap(input[k], input[k + 1]);
			}
		}
	}
}


void InsertionSort(int input[], int size)
{
	for (int i = 1; i < size; ++i)
	{
		int j = i;
		int target = input[i];

		while (--j >= 0 && target < input[j])
		{
			input[j + 1] = input[j];
			input[j] = target;
		}
	}
}


void MergeSort(int input[], int start, int end, int temp[])
{
	if (start >= end)
		return;

	int half = (start + end) / 2;

	MergeSort(input, start, half, temp);
	MergeSort(input, half + 1, end, temp);
	Merge(input, start, half, end, temp);
}

void Merge(int input[], int start, int half, int end, int temp[])
{
	int i = start;
	int j = half + 1;
	int tempIndex = 0;

	// 왼쪽 블럭과 오른쪽 블럭을 정렬 합병
	while (i <= half && j <= end)
	{
		if (input[i] < input[j])
		{
			temp[tempIndex++] = input[i++];
		}
		else
		{
			temp[tempIndex++] = input[j++];
		}
	}
	
	// 남은 인덱스들을 병합
	// 왼쪽 or 오른쪽 블럭이 남아 있을결우 대비해서 각각 병합
	while (i <= half)
	{
		temp[tempIndex++] = input[i++];
	}
	while (j <= end)
	{
		temp[tempIndex++] = input[j++];
	}

	// 원래 배열로 복사
	tempIndex = 0;
	for (int a = start; a <= end; ++a)
	{
		input[a] = temp[tempIndex++];
	}
}


void QuickSort(int input[], int left, int right)
{
	int i = left;
	int j = right;
	int pivot = input[(left + right) / 2];
	int tmep;

	do
	{
		while (input[i] < pivot)
		{
			i++;
		}
	
		while (input[j] > pivot)
		{
			j--;
		}

		if (i <= j)
		{
			Swap(input[i], input[j]);
			i++;
			j--;
		}
	} while (i <= j);

	if (left < j)
		QuickSort(input, left, j);

	if (i < right)
		QuickSort(input, i, right);
}

