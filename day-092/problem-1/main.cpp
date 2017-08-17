/*
 * For the functions selectionSort(), bubbleSort(), and quickSort(), the sorting 
 * can be done in decreasing order by a simple modification. In each case
 * identify the required changes and then rewrite each function to accept
 * a flag indicating whether the sort should be in increasing or decreasing
 * order. Modify each routine to receive and use this flag argument correctly.
 *
 */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define len(array)(sizeof(array)/sizeof(array[0]))

#define global_variable static

global_variable const int Size = 10;

void
GenerateNumbers(int array[], int size);

void
PrintArray(int array[], int size, char *text);

void
Swap(int *x, int *y);

void
BubbleSort(int array[], int size, char sortOrder);

void
SelectionSort(int array[], int size,char sortOrder);

int
Partition(int array[], int left, int right, char sortOrder);

void
QuickSort(int array[], int lower, int upper, char sortOrder);

int
main()
{
	int TestCase[Size] = { 0 };
	char sortOrder = ' ';

	while (sortOrder != 'a' && sortOrder != 'd') 
	{
		printf("Enter sort order (a / d): ");
		scanf("\n%c", &sortOrder);
		sortOrder = tolower(sortOrder);
	}

	// bubble sort
	GenerateNumbers(TestCase, len(TestCase));
	PrintArray(TestCase, len(TestCase), "bubble sort (before)");
	BubbleSort(TestCase, len(TestCase), sortOrder);
	PrintArray(TestCase, len(TestCase), "bubble sort (after)");
	printf("\n");

	// selection sort
	GenerateNumbers(TestCase, len(TestCase));
	PrintArray(TestCase, len(TestCase), "selection sort (before)");
	SelectionSort(TestCase, len(TestCase), sortOrder);
	PrintArray(TestCase, len(TestCase), "selection sort (after)");
	printf("\n");

	// quick sort
	GenerateNumbers(TestCase, len(TestCase));
	PrintArray(TestCase, len(TestCase), "quick sort (before)");
	QuickSort(TestCase, 0, (len(TestCase) - 1), sortOrder);
	PrintArray(TestCase, len(TestCase), "quick sort (after)");
	printf("\n");

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
	printf("%s: { ", text);
	for (int i = 0; i < size; ++i)
	{
		printf("%d, ", array[i]);
	}
	printf("}\n");
}

void
Swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

void
BubbleSort(int array[], int size, char sortOrder)
{
	bool swapped = false;
	for (int i = 0; i < size - 1; ++i)
	{
		for (int j = 0; j < size - (i + 1); ++j)
		{
			// NOTE(nick): logic switch here to determine asc or desc
			if (sortOrder == 'a')
			{
				if (array[j] > array[j + 1])
				{
					Swap(&array[j], &array[j + 1]);
					swapped = true;
				}
			}
			else if (sortOrder == 'd')
			{
				if (array[j] < array[j + 1])
				{
					Swap(&array[j], &array[j + 1]);
					swapped = true;
				}
			}
		}
		if (!swapped)
		{
			break;
		}
	}
}

void
SelectionSort(int array[], int size, char sortOrder)
{
	int index = 0;
	for (int i = 0; i < size - 1; ++i)
	{
		index = i;
		for (int j = i + 1; j < size; ++j)
		{
			if (sortOrder == 'a')
			{
				if (array[j] < array[index])
				{
					index = j;
				}
			}
			else if (sortOrder == 'd')
			{
				if (array[j] > array[index])
				{
					index = j;
				}
			}
			
		}
		if (index != i)
		{
			Swap(&array[i], &array[index]);
		}
	}
}

int
Partition(int array[], int left, int right, char sortOrder)
{
	int pivot, temp;
	pivot = array[left];
	while (left < right)
	{
		// scan from right to left
		if (sortOrder == 'a')
		{
			while (array[right] >= pivot && left < right)
			{
				// skip over larger or equal values
				--right;
			}
		}
		else if (sortOrder == 'd')
		{
			while (array[right] <= pivot && left < right)
			{
				// skip over larger or equal values
				--right;
			}
		}
		if (right != left)
		{
			// move the higher value into the available slot
			array[left] = array[right];
			++left;
		}
		if (sortOrder == 'a')
		{
			// scan from left to right
			while (array[left] <= pivot && left < right)
			{
				// skip over smaller or equal values
				++left;
			}
		}
		else if (sortOrder == 'd')
		{
			while (array[left] >= pivot && left < right)
			{
				// skip over smaller or equal values
				++left;
			}
		}
		if (right != left)
		{
			// move lower value into the available slot
			array[right] = array[left];
			--right;
		}
	}
	array[left] = pivot;
	return left;
}

void
QuickSort(int array[], int lower, int upper, char sortOrder)
{
	int pivot;
	pivot = Partition(array, lower, upper, sortOrder);
	if (lower < pivot)
	{
		QuickSort(array, lower, (pivot - 1), sortOrder);
	}
	if (upper > pivot)
	{
		QuickSort(array, (pivot + 1), upper, sortOrder);
	}
}

