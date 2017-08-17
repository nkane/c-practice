/*
 * A company currently maintains two lists of part numbers,
 * where each part number is an integer. Write a C program that
 * compares these lists of numbers and displays the numbers, if any,
 * that are common to both. (Hint: Sort each list prior to making the
 * comparison).
 * 
 */

#include <stdio.h>

#define global_variable static
#define len(array)(sizeof(array)/sizeof(array[0]))

global_variable const int Size = 5;

void
Swap(int *x, int *y);

void
SelectionSort(int array[], int size);

bool
BinarySearch(int array[], int size, int key);

int
main()
{
	int TestListOne[Size] = { 20, 14, 11, 45, 51, };
	int TestListTwo[Size] = { 2, 9, 11, 102, 20, };

	SelectionSort(TestListOne, len(TestListOne));
	SelectionSort(TestListTwo, len(TestListTwo));

	// check to see if current TestListOne value is
	// in TestListTwo
	for (int i = 0; i < len(TestListOne); ++i)
	{
		if (BinarySearch(TestListTwo, len(TestListTwo), TestListOne[i]))
		{
			printf("Found: %d in both list!\n", TestListOne[i]);
		}
	}

	return 0;
}

void
Swap(int *x, int *y)
{
	*x ^= *y;
	*y ^= *x;
	*x ^= *y;
}

void
SelectionSort(int array[], int size)
{
	int min_index = 0;
	for (int i = 0; i < size - 1; ++i)
	{
		min_index = i;
		for (int j = i + 1; j < size; ++j)
		{
			if (array[min_index] > array[j])
			{
				min_index = j;
			}
		}
		if (min_index != i)
		{
			Swap(&array[min_index], &array[i]);
		}
	}
}

bool
BinarySearch(int array[], int size, int key)
{
	bool found = false;
	int left, right, mid;
	left = 0;
	right = size - 1;
	while (left <= right && !found)
	{
		mid = (int)((left + right) / 2);
		if (key == array[mid])
		{
			found = true;
		}
		else if (key > array[mid])
		{
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}
	return found;
}

