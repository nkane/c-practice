/*
 * Write a declaration to store the string "This is a sample" in an array named samtest
 * Include the declaration in a program that displays the values in samtest in a for loop
 * that uses a pointer to access each element in the array.
 *
 * Modify the program written, to display only array elements 10 through 15 (these are letters
 * s, a, m, p, l, and e)
 *
 */

#include <stdio.h>
#include <string.h>

int
main()
{
	char *stringBuffer = "This is a sample";
	int i;

	for (i = 0; i < strlen(stringBuffer); ++i)
	{
		printf("%c", *(stringBuffer + i));
	}

	printf("\n");

	for (i = 10; i < strlen(stringBuffer); ++i)
	{
		printf("%c", *(stringBuffer + i));
	}

	return 0;
}
