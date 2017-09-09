/*
 * Write a main() program that prints the integers 0, 2, 4, 
 * up to 20 one per line.
 *
 */

#include <stdio.h>

#define global_variable static

global_variable const int Loop = 20;


int
main()
{
	for (int i = 0; i <= Loop; i+= 2)
	{
		printf("%d\n", i);
	}

	return 0;
}
