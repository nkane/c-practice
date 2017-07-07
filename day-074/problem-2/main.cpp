/*
 * Write a C program to input 15 integer numbers into an array named temp. 
 * As each number is input, add the number into the total. After all numbers are
 * input, display the numbers and their average.
 *
 * Locate the maximum and minimum number in the array as the values are being input.
 *
 */

#include <stdio.h>

#define array_size(array)(sizeof(array)/sizeof(array[0]))

#define global_variable static

global_variable const int Size = 15;

int
main()
{
	int Temp[Size];
	int min = 0;
	int max = 0;
	int total = 0;

	for (int i = 0; i < array_size(Temp); ++i)
	{
		printf("Enter in a value [%d]: ", i);
		scanf("%d", &Temp[i]);
		if (max < Temp[i])
		{
			max = Temp[i];
		}

		if (min > Temp[i] || i == 0)
		{
			min = Temp[i];
		}
		total += Temp[i];
	}


	for (int i = 0; i < array_size(Temp); ++i)
	{
		printf("Value [%d]: %d\n", i, Temp[i]);
	}

	printf("\nMax: %d\n", max);
	printf("Min: %d\n", min);

	printf("Average: %d\n", (total / array_size(Temp)));

	return 0;
}
