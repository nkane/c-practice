/*
 * Create a program that generates numbers for an array.
 * Implement the following sorting methods:
 *
 * 	1) Bubble Sort
 * 	2) Selection Sort
 * 	3) Insertion Sort
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "main.h"
#include "sort.h"

int
main()
{
	int TestCase[Size] = { 0 };

	// bubble sort
	GenerateNumbers(TestCase, len(TestCase));
	PrintArray(TestCase, len(TestCase), "Bubble Sort (Before):");
	BubbleSort(TestCase, len(TestCase));
	PrintArray(TestCase, len(TestCase), "Bubble Sort (After):");

	// insertion sort
	GenerateNumbers(TestCase, len(TestCase));
	PrintArray(TestCase, len(TestCase), "Insertion Sort (Before):");
	InsertionSort(TestCase, len(TestCase));
	PrintArray(TestCase, len(TestCase), "Insertion Sort (After):");

	// selection sort
	GenerateNumbers(TestCase, len(TestCase));
	PrintArray(TestCase, len(TestCase), "Selection Sort (Before):");
	SelectionSort(TestCase, len(TestCase));
	PrintArray(TestCase, len(TestCase), "Selection Sort (After):");

	system("pause");

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

