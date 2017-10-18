/*
 * Write a C  function named fcheck() that checks whether a file exists.
 * The funciton should be passed a filename. If the file exists, the
 * function should return a value of 1; otherwise, the function should
 * return a value of 0.
 *
 */

#include <stdio.h>

int
FCheck(char *fileName);

int
main()
{
	printf("Testing Available File: %d == 1\n", FCheck("./data/test.dat"));

	printf("Testing Unavailable File: %d == 0\n", FCheck("./data/test-1.dat"));

	return 0;
}

int
FCheck(char *fileName)
{
	int result = 0;
	FILE *file = fopen(fileName, "r");
	if (file)
	{
		fclose(file);
		result = 1;
	}
	return result;
}
