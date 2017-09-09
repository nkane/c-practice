/*
 * Write a C program that selects and displays the first 20 integer numbers that are evenly
 * divisible by 3.
 *
 */

#include <stdio.h>

#define global_variable static

global_variable const int Loop_Value = 20;

int
main()
{
	for (int i = 1; i <= Loop_Value; ++i)
	{
		if ((i % 3) == 0)
		{
			printf("The value %d - is divisible by 3!\n", i);
		}
	}

	return 0;
}
