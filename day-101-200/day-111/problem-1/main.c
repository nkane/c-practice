/*
 * Enter an execute Program 10.1 on your computer
 *
 */

#include <stdlib.h>
#include <stdio.h>

int
main()
{
	FILE *inFile;

	inFile = fopen("prices.dat", "r");

	if (inFile == NULL)
	{
		printf("\nThe file was not successfully opened.");
		printf("\nPlease check that the file currently exists.\n");
		exit(1);
	}

	printf("\nThe file has been successfully opened for reading.\n");

	return 0;
}

