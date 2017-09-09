/*
 * Generate numbers into an array and implement the 
 * following sortin algorithms:
 * 
 * 	1) Bubble Sort
 * 	2) Insertion Sort
 * 	3) Selection Sort
 *
 */

#include <math.h>
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
	PrintArray(TestCase, len(TestCase), "Bubble Sort (before):");
	BubbleSort(TestCase, len(TestCase));
	PrintArray(TestCase, len(TestCase), "Bubble Sort (after):");
	printf("\n");

	// insertion sort
	GenerateNumbers(TestCase, len(TestCase));
	PrintArray(TestCase, len(TestCase), "Insertion Sort (before):");
	InsertionSort(TestCase, len(TestCase));
	PrintArray(TestCase, len(TestCase), "Insertion Sort (after):");
	printf("\n");

	// selection sort
	GenerateNumbers(TestCase, len(TestCase));
	PrintArray(TestCase, len(TestCase), "Selection Sort (before):");
	SelectionSort(TestCase, len(TestCase));
	PrintArray(TestCase, len(TestCase), "Selection Sort (after):");
	printf("\n");

	return 0;
}

