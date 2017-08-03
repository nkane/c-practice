/*
 * Create a program that generates numbers and
 * implements the following sort algorithms:
 *
 * 	1) Bubble Sort
 * 	2) Insertion Sort
 * 	3) Selection Sort
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "sort.h"

#define len(array)(sizeof(array)/sizeof(array[0]))

#define global_variable static

void
GenerateNumbers(int array[], int size);

void
PrintArray(int array[], int size, char *text);

global_variable const int Size = 10;

int
main()
{
	int TestCase[Size] = { 0 };

	// bubble sort
	GenerateNumbers(TestCase, len(TestCase));
	PrintArray(TestCase, len(TestCase), "bubble sort (before)");
	BubbleSort(TestCase, len(TestCase));
	PrintArray(TestCase, len(TestCase), "bubble sort (after)");
	printf("\n");

	// insertion sort
	GenerateNumbers(TestCase, len(TestCase));
	PrintArray(TestCase, len(TestCase), "insertion sort (before)");
	InsertionSort(TestCase, len(TestCase));
	PrintArray(TestCase, len(TestCase), "insertion sort (after)");
	printf("\n");

	// selection sort
	GenerateNumbers(TestCase, len(TestCase));
	PrintArray(TestCase, len(TestCase), "selection sort (before)");
	SelectionSort(TestCase, len(TestCase));
	PrintArray(TestCase, len(TestCase), "selection sort (after)");
	
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

