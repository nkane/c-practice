/*
 * using the fseek() and ftell() functions, write a C function named
 * totChars() that returns the total number of characters in a file.
 *
 */

#include <stdio.h>

long int
TotalChars(FILE *f);

int
main()
{
	FILE *file = NULL;

	if (file = fopen("./data/test.dat", "r"))
	{
		long int count = TotalChars(file);
		fclose(file);
	}

	return 0;
}

long int
TotalChars(FILE *f)
{
	long int last = 0L;
	fseek(f, 0L, SEEK_END);
	last = ftell(f);
	printf("Charcter Count: %d\n", last);
	return last;
}
