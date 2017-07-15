/*
 * Write a program that has a declaration in main() to store
 * the following numbers into an array named rates:
 *
 * 	6.5, 8.2, 8.5, 8.3, 8.6, 9.4, 9.6, 9.8, 10.0
 *
 * There should be a function call to show() that accepts
 * the rate array as a parameter named rates and then
 * displays the number in the array.
 *
 */

#include <stdio.h>

void
Show(double array[]);

int
main()
{
	double rates[] = { 6.5, 8.2, 8.5, 8.3, 8.6, 9.4, 9.6, 9.8, 10.0, NULL, }; 
	Show(rates);

	return 0;
}

void
Show(double array[])
{
	printf("Array: { ");
	while (*array != NULL)
	{
		printf("%.2lf , ", *array);
		++array;
	}
	printf("} \n");
}

