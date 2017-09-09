/*
 * Generate numbers in to an array and implement 
 * the following sorting algorithms:
 *
 * 	- Bubble Sort
 * 	- Insertion Sort
 * 	- Selection Sort
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "main.h"
#include "sort.h"

void
GenerateNumbers(int array[], int size);

void
PrintArray(int array[], int size, char *text);

int
main()
{	
	int TestCase[Size] = { 0 };

	// bubble sort
	GenerateNumbers(TestCase, len(TestCase));
	PrintArray(TestCase, len(TestCase), "Bubble Sort (before):");
	BubbleSort(TestCase, len(TestCase));
	PrintArray(TestCase, len(TestCase), "Bubble Sort (after):");

	// insertion sort
	GenerateNumbers(TestCase, len(TestCase));
	PrintArray(TestCase, len(TestCase), "Bubble Sort (before):");
	InsertionSort(TestCase, len(TestCase));
	PrintArray(TestCase, len(TestCase), "Bubble Sort (after):");

	// selection sort
	GenerateNumbers(TestCase, len(TestCase));
	PrintArray(TestCase, len(TestCase), "Bubble Sort (before):");
	SelectionSort(TestCase, len(TestCase));
	PrintArray(TestCase, len(TestCase), "Bubble Sort (after):");

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

