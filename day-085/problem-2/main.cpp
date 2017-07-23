/*
 * Define an array with a maximum of 20 integer values and fill
 * the array with numbers either input from the keyboard or assigned
 * by the program. Then write a function named split() that reads
 * the array and places all 0 or positive numbers into an array
 * named positive and all negative numbers into an array named negative.
 * Finally, have your program call a function that displays the value in
 * both the positive and negative arrays.
 *
 * Extend the program written, to sort the positive and negative arrays
 * into ascending order before they are displayed.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define len(array)(sizeof(array)/sizeof(array[0]))

#define global_variable static

global_variable const int Size = 20;

void
GenerateNumbers(int array[], int size);

void
PrintArray(int array[], int size, char *text);

void
Swap(int *x, int *y)

void
SelectionSort(int array[], int size);

int
main()
{
	int TestCase[Size] = { 0 };
	int Positive[Size] = { 0 };
	int Negative[Size] = { 0 };

	GenerateNumbers(TestCase, len(TestCase));
	PrintArray(TestCase, len(TestCase), "Init ");

	int pIndex = 0;
	int nIndex = 0;
	for (int i = 0; i < len(TestCase); ++i)
	{
		if (TestCase[i] > 0)
		{
			Positive[pIndex] = TestCase[i];
			++pIndex;
		}
		else
		{
			Negative[nIndex] = TestCase[i];
			++nIndex;
		}
	}

	printf("\n");

	PrintArray(Positive, pIndex, "Positive (pre-sorted) ");
	PrintArray(Negative, nIndex, "Negative (pre-sorted) ");

	printf("\n");

	SelectionSort(Positive, pIndex);
	SelectionSort(Negative, nIndex);

	PrintArray(Positive, pIndex, "Positive (sorted) ");
	PrintArray(Negative, nIndex, "Negative (sorted) ");

	return 0;
}


void
GenerateNumbers(int array[], int size)
{
	srand(time(NULL));
	for (int i = 0; i < size; ++i)
	{
		array[i] = (1 + (rand() % 100));
		if (i % 3)
		{
			array[i] -= 50;
		}
	}
}

void
PrintArray(int array[], int size, char *text)
{
	printf("%sArray: { ", text);
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
SelectionSort(int array[], int size)
{
	int i = 0;
	int j = 0;
	int min_index = 0;

	for (i = 0; i < size - 1; ++i)
	{
		min_index = i;
		for (j = i + 1; j < size; ++j)
		{
			if (array[min_index] > array[j])
			{
				min_index = j;
			}
		}
		if (min_index != i)
		{
			Swap(&array[i], &array[min_index]);
		}
	}
}

