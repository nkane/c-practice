/*
 * The selection and bubble sort both use the same technique for swapping
 * list elements. Replace the code in these two functions that performs the
 * swap by a call to a function named swap. The prototype for swap should be
 * void swap(int *, int *). The swap() function should be constructed using
 * the algorithm presented in section 7.4
 *
 * describe why the function quicksort() does not require the swap algorithm
 * used by the selection and bubble sorts.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define global_variable static

#define len(array)(sizeof(array)/sizeof(array[0]))

global_variable const int Size = 10;

void
GenerateNumbers(int array[], int size);

void
PrintArray(int array[], int size, char *text);

void
Swap(int *x, int *y);

void
BubbleSort(int array[], int size);

void
SelectionSort(int array[], int size);

int
main()
{	
	int TestCase[Size] = { 0 };

	// bubble sort
	{
		GenerateNumbers(TestCase, len(TestCase));
		PrintArray(TestCase, len(TestCase), "bubble sort (before):");
		BubbleSort(TestCase, len(TestCase));
		PrintArray(TestCase, len(TestCase), "bubble sort (after):");
	}

	printf("\n");

	// selection sort
	{
		GenerateNumbers(TestCase, len(TestCase));
		PrintArray(TestCase, len(TestCase), "selection sort (before):");
		SelectionSort(TestCase, len(TestCase));
		PrintArray(TestCase, len(TestCase), "selection sort (after):");
	}

	return 0;
}

void
GenerateNumbers(int array[], int size)
{
	srand(time(NULL));
	for (int i = 0; i < size; ++i)
	{
		array[i] = (1 + (rand() % 100));
	}
}

void
PrintArray(int array[], int size, char *text)
{
	printf("%s { ", text);
	for (int i = 0; i < size; ++i)
	{
		printf("%d, ", array[i]);
	}
	printf("}\n");
}

void
Swap(int *x, int *y)
{
	*x ^= *y;
	*y ^= *x;
	*x ^= *y;
}

void
BubbleSort(int array[], int size)
{
	bool swapped = false;
	for (int i = 0; i < size - 1; ++i)
	{
		for (int j = 0; j < size - (i + 1); ++j)
		{
			if (array[j] > array[j + 1])
			{
				Swap(&array[j], &array[j + 1]);
				swapped = true;
			}
		}
	}
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

