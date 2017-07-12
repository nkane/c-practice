/*
 * Write a declaration to store the following values in an array named prices:
 *
 *	- 16.24, 18.98, 23.75, 16.29, 19.54, 14.22, 11.13, 15.39
 *
 * Include the declaration in a program that displays the values in the array.
 *
 */

#include <stdio.h>

#define array_size(array)(sizeof(array)/sizeof(array[0]))

int
main()
{
	float prices[] =
	{
		16.24f,
		18.98f,
		23.75f,
		16.29f,
		19.54f,
		14.22f,
		11.13f,
		15.39f,
	};

	for (int i = 0; i < array_size(prices); ++i)
	{
		printf("%.2f\n", prices[i]);
	}

	return 0;
}

