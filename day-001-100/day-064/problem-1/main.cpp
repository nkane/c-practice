/*
 * Write a main() program that prints the integers 0 to 14 
 * one per line. Write the integers to standard output. On
 * a Windows machine, write the integers to the DOS windows. 
 * The output of the program is:
 *
 * 	0
 * 	1
 * 	2
 *	3
 *	. . .
 *	14
 *
 */

#include <stdio.h>

#define global_varaible static

global_varaible const int Loop_Size = 14;

int
main()
{
	for (int i = 0; i <= Loop_Size; ++i)
	{
		printf("%d\n", i);
	}

	return 0;
}

