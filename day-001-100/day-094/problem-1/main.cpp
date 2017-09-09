/*
 * Exercise 6:
 * A company currently maintains two lists of part numbers, where each
 * part number is an integer. Write a C program that compares these lists
 * of numbers and displays the numbers, if any, that are common to both.
 * (Hint: sort each list prior to making the comparison).
 *
 * Redo exercise 6, but display a list of part numebers that are only
 * on one list, but not both.
 *
 */

#include <stdio.h>
#include <stdlib.h>

#define len(array)(sizeof(array)/sizeof(array[0]))

#define global_variable static

global_variable const int Size = 5;

void
SelectionSort(int list[], int size);

void 
XorSwap(int *x, int *y);

bool
BinarySearch(int list[], int low, int high);

int
main()
{
	int TestCase_1[Size] = { 20, 45, 63, 90, 15, };
	int TestCase_2[Size] = { 21, 45, 74, 90, 15, };

	SelectionSort(TestCase_1, len(TestCase_1));
	SelectionSort(TestCase_2, len(TestCase_2));

	for (int i = 0; i < len(TestCase_1); ++i)
	{
		if(!BinarySearch(TestCase_2, len(TestCase_2), TestCase_1[i]))
		{
			printf("Not found: %d\n", TestCase_1[i]);
		}
	}

	
	return 0;
}

void 
XorSwap(int *x, int *y)
{
	*x ^= *y;
	*y ^= *x;
	*x ^= *y;
}

void
SelectionSort(int list[], int size)
{
	int min_index = 0;
	for (int i = 0; i < size - 1; ++i)
	{
		min_index = i;
		for (int j = i + 1; j < size; ++j)
		{
			if (list[j] < list[min_index])
			{
				min_index = j;
			}
		}
		if (min_index != i)
		{
			XorSwap(&list[min_index], &list[i]);
		}
	}
}

bool
BinarySearch(int list[], int size, int searchKey)
{
	bool found = false;

	// starting positions
	int high = size - 1;
	int low = 0;
	int mid = 0;

	while (low <= high && !found)
	{
		mid = (int)((high + low) / 2);
		// search key matches - found!
		if (searchKey == list[mid])
		{
			found = true;
		}
		// search key is greater than mid position
		// drop lower half of search
		else if (searchKey > list[mid])
		{
			low = mid + 1;
		}
		// search key is less than mid position
		// drop upper half of search
		else
		{
			high = mid - 1;
		}
	}
	return found;
}

