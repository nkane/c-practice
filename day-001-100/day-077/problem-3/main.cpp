/*
 * Create a function that generates pseudo random numbers
 * between 1 to 100 to populate an array. Review and write
 * the following sorting algorithms:
 *
 * 	- bubble sort
 *	- insertion sort
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "sort.h"

#define array_size(array)(sizeof(array)/sizeof(array[0]))

#define global_variable static
#define local_persist static

global_variable const int Size = 5;

void
GenerateNumbers(int array[], int size);

void
PrintArray(int array[], int size, char *message);

int
main()
{
 	local_persist int TestCase[Size] = { 0 };

	// bubble sort test case
	GenerateNumbers(TestCase, array_size(TestCase));
	PrintArray(TestCase, array_size(TestCase), "BubbleSort Array (Before):\0");
	BubbleSort(TestCase, array_size(TestCase));
	PrintArray(TestCase, array_size(TestCase), "BubbleSort Array (After):\0");

	// insertion sort test case
	GenerateNumbers(TestCase, array_size(TestCase));
	PrintArray(TestCase, array_size(TestCase), "InsertionSort Array (Before):\0");
	InsertionSort(TestCase, array_size(TestCase));
	PrintArray(TestCase, array_size(TestCase), "InsertionSort Array (After):\0");

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
PrintArray(int array[], int size, char *message)
{
	printf("%s\n { " , message);
	for (int i = 0; i < size; ++i)
	{
		printf("%d, ", array[i]);
	}
	printf("}\n");
	system("pause");
}

