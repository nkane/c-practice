/*
 * Create a program that generates unsorted numbers for an array.
 * Next review / implement the following sorting algorithms:
 *
 * 	1) Bubble Sort
 * 	2) Insertion Sort
 * 	3) Selection Sort
 * 	4) Merge Sort
 *
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "sort.h"

#define len(array)(sizeof(array)/sizeof(array[0]))

#define global_variable static

global_variable const int Size = 5;

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
	PrintArray(TestCase, len(TestCase), "Bubble Sort (Before)\0");
	BubbleSort(TestCase, len(TestCase));
	PrintArray(TestCase, len(TestCase), "Bubble Sort (After)\0");
	//system("pause");

	// insertion sort
	GenerateNumbers(TestCase, len(TestCase));
	PrintArray(TestCase, len(TestCase), "Insertion Sort (Before)\0");
	InsertionSort(TestCase, len(TestCase));
	PrintArray(TestCase, len(TestCase), "Insertion Sort (After)\0");
	//system("pause");

	// selection sort
	GenerateNumbers(TestCase, len(TestCase));
	PrintArray(TestCase, len(TestCase), "Selection Sort (Before)\0");
	SelectionSort(TestCase, len(TestCase));
	PrintArray(TestCase, len(TestCase), "Selection Sort (After)\0");
	//system("pause");

	// merge sort
	GenerateNumbers(TestCase, len(TestCase));
	PrintArray(TestCase, len(TestCase), "Merge Sort (Before)\0");
	MergeSort(TestCase, 0, len(TestCase) - 1);
	PrintArray(TestCase, len(TestCase), "Merge Sort (After)\0");
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
	printf("%s\n{ ", text);
	for (int i = 0; i < size; ++i)
	{
		printf("%d, ", array[i]);
	}
	printf("}\n\n");
}

