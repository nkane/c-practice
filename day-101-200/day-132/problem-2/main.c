/*
 * Write a C program that stores the following numbers in an array named
 * rates: 6.25, 6.50, 7.2, 7.35, 7.5, 7.65, 7.8, 9.2, 9.6, 9.8, 9.0. Display
 * the values in the array by changing the address in a pointer called dispPt.
 * Use a for statement in your program
 *
 * Modify the program to use a while statement.
 *
 */

#include <stdio.h>

#define len(array)(sizeof(array)/sizeof(array[0]))

int
main()
{
	float rates[] = { 6.25f, 6.50f, 7.2f, 7.35f, 7.5f, 7.65f, 7.8f, 9.2f, 9.6f, 9.8f, 9.0f, };
	float *dispPtr;

	printf("For loop\n");

	for (dispPtr = rates; dispPtr < (rates + len(rates)); ++dispPtr)
	{
		printf("Current Value: %6.2f\n", *dispPtr);
	}

	printf("\nWhile loop\n");

 	dispPtr = rates;
	while (dispPtr < (rates + len(rates)))
	{
		printf("Current Value: %6.2f\n", *dispPtr);
		++dispPtr;
	}
	
	return 0;
}
