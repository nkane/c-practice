/*
 * Today, we are going over different types of sorting methods.
 * We are going to implement the following sorting methods:
 *
 *	1) Bubble sort
 *	2) Insertion sort
 *	3) Selection sort (not able to get done)
 *	4) Merge Sort 	  (not able to get done)
 *	5) Quick Sort	  (not able to get done)
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "sort.h"

#define global_variable static

#define array_size(array)(sizeof(array)/sizeof(array[0]))

global_variable const int Size = 5;

void
GenerateNumber(int array[], int size);

void
PrintArray(int array[], int size, char *arrayName);

int
main()
{
	int TestCase[Size] = { 0 };

	// bubble sort test case
	GenerateNumber(TestCase, array_size(TestCase));
	PrintArray(TestCase, array_size(TestCase), "TestCase BubbleSort\0");
	BubbleSort(TestCase, array_size(TestCase));
	PrintArray(TestCase, array_size(TestCase), "After BubbleSort\0");

	// insertion sort test case
	GenerateNumber(TestCase, array_size(TestCase));
	PrintArray(TestCase, array_size(TestCase), "TestCase InsertionSort\0");
	InsertionSort(TestCase, array_size(TestCase));
	PrintArray(TestCase, array_size(TestCase), "After InsertionSort\0");

	return 0;
}

void
GenerateNumber(int array[], int size)
{
	srand(time(NULL));
	for (int i =0; i < size; ++i)
	{
		array[i] = (1 + (rand() % 100));
	}
}

void
PrintArray(int array[], int size, char *arrayName)
{
	printf("Array: %s\n{ ", arrayName);
	for (int i = 0; i < size; ++i)
	{
		printf("%d, ", array[i]);
	}
	printf("}\n");
	system("pause");
}

