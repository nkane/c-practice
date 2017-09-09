/*
 * Write a program that inputs 10 double-percision numbers into an array named raw.
 * After 10 user-input numbers are entered into the array, your program should cycle
 * through raw 10 times. During each pass through the array, your program should
 * select the lowest value in raw and place the selected value in the next available
 * slot in an array named sorted. Thus, when your program is complete, the sorted
 * array should contain the numbers in raw in sorted order from lowest to highest.
 * (Hint: make sure to reset the lowest value selected during each pass to a very high
 * number so that it is not selected again. You will need a second for loop within
 * the first for loop to locate the minimum value for each pass.)
 *
 * The method used for sorting in this program is inefficient. Can you determine
 * why? What might be a better method of sorting the numbers in an array?
 *
 */

#include <stdio.h>

#define array_size(array)(sizeof(array)/sizeof(array[0]))

#define global_variable static

global_variable const int Size = 3;

global_variable const double Large = 1000000.0;

int
main()
{
	double raw[Size];
	double sorted[Size];
	int min = 0;
	int lastIndex = 0;

	for (int i = 0; i < array_size(raw); ++i)
	{
		printf("Enter in value [%d]: ", i);
		scanf("%lf", &raw[i]);
	}

	// O(n^2)
	for (int i = 0; i < array_size(raw); ++i)
	{
		lastIndex = 0;
		min = Large;
		for (int i = 0; i < array_size(raw); ++i)
		{
			if (min > raw[i])
			{
				min = raw[i];
				lastIndex = i;
			}
		}
		raw[lastIndex] = Large;
		sorted[i] = min;
	}

	for (int i = 0; i < array_size(sorted); ++i)
	{
		printf("Sort[%d]: %lf\n", i, sorted[i]);
	}

	return 0;
}

