/*
 * Write a declaration to store the following values in a static array
 * named rates: 12.9, 19.6, 11.4, 13.7, 9.5, 15.2, 17.6. Include the
 * declaration in a program that displays the values in the array
 * using pointer notation.
 *
 */

#include <stdio.h>

#define local_persist static
#define len(array)(sizeof(array)/sizeof(array[0]))

int
main()
{
	local_persist float rates[] = { 12.9f, 19.6f, 11.4f, 13.7f, 9.5f, 15.2f, 17.6f, };
	int i;

	printf("Rates (using pointer notation):\n");

	for (i = 0; i < len(rates); ++i)
	{
		printf("%6.2f\n", *(rates + i));
	}
	
	return 0;
}
