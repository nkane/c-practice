/*
 * Write a C program to input the following values into an array named prices:
 *
 * 	10.95, 16.32, 12.15, 8.22, 15.98, 26.22, 13.54, 6.45, 18.59. 
 *
 * After the data is entered, your program should output the values.
 *
 */

#include <stdio.h>

#define array_size(array)(sizeof(array)/sizeof(array[0]))

#define global_variable static

global_variable const int Size = 9;

int
main()
{
	float PriceArray[Size];

	for (int i = 0; i < array_size(PriceArray); ++i)
	{
		printf("Enter value for [%d]: ", i);
		scanf("%f", &PriceArray[i]);
	}

	for (int i = 0; i < array_size(PriceArray); ++i)
	{
		printf("Value at [%d] := %.2f\n", i, PriceArray[i]);
	}

	return 0;
}
