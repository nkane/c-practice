/*
 * Write a C program that stores the following numbers in an array named miles:
 * 15, 22, 16, 18, 27, 23, 30. Have your program copy the data stored in miles to
 * another array named dist and then display the values in the dist array.
 *
 */

#include <stdio.h>

#define len(array)(sizeof(array)/sizeof(array[0]))

int
main()
{
	int miles[7] = { 15, 22, 16, 18, 27, 23, 30, };
	int dist[7] = { 0 };
	int *srcPtr;
	int *destPtr;

	for (srcPtr = miles, destPtr = dist; srcPtr < (miles + len(miles)); ++srcPtr, ++destPtr)
	{
		*destPtr = *srcPtr;
	}

	for (srcPtr = dist; srcPtr < (dist + len(dist)); ++srcPtr)
	{
		printf("%d, ", *srcPtr);
	}
	
	return 0;
}
