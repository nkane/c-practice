/*
 * Write a main() program that prints the integers -7
 * to +7, one per line.
 *
 */

#include <stdio.h>

#define global_variable static 

global_variable const int Loop = 7;

int 
main()
{
	for (int i = -7;  i <= Loop; ++i)
	{
		printf("%d\n", i);
	}

	return 0;
}
