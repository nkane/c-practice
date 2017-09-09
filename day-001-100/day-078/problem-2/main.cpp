/*
 * Create a program that generates random numbers for
 * an array of n size and does the following sorting
 * algorithms:
 *
 * 	1) Bubble sort
 * 	2) Insertion sort
 * 	3) Selection sort
 *
 * This exercise is for reviewing and to help promote
 * memorizing these sorting algorithms.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "sort.h"

#define array_size(array)(sizeof(array)/sizeof(array[0]))

#define global_variable static

global_variable const int Size = 5;

void
GenerateRandomNumbers(int array[], int size);

void
PrintArray(int array[], int size, char *text);

int
main()
{
	int TestCase[Size] = { 0 };

	// bubble sort
	GenerateRandomNumbers(TestCase, array_size(TestCase));
	PrintArray(TestCase, array_size(TestCase), "Bubble Sort (Before)\0");
	BubbleSort(TestCase, array_size(TestCase));
	PrintArray(TestCase, array_size(TestCase), "Bubble Sort (After)\0");

	// insertion sort
	GenerateRandomNumbers(TestCase, array_size(TestCase));
	PrintArray(TestCase, array_size(TestCase), "Insertion Sort (Before)\0");
	InsertionSort(TestCase, array_size(TestCase));
	PrintArray(TestCase, array_size(TestCase), "Insertion Sort (After)\0");

	// selection sort
	GenerateRandomNumbers(TestCase, array_size(TestCase));
	PrintArray(TestCase, array_size(TestCase), "Selection Sort (Before)\0");
	SelectionSort(TestCase, array_size(TestCase));
	PrintArray(TestCase, array_size(TestCase), "Selection Sort (After)\0");

	return 0;
}

void
GenerateRandomNumbers(int array[], int size)
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
	for(int i = 0; i < size; ++i)
	{
		printf("%d, ", array[i]);
	}
	printf("}\n");
	system("pause");
}

