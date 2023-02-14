#pragma once
#include <iostream>

void PrintArray(int input[], int size);
void Swap(int& value1, int& value2);

void SequentialSort(int input[], int size);

void SelectionSort(int input[], int size);

void BubbleSort(int input[], int size);

void InsertionSort(int input[], int size);

void MergeSort(int input[], int start, int end, int temp[]);
void Merge(int input[], int start, int half, int end, int temp[]);

void QuickSort(int input[], int left, int right);

