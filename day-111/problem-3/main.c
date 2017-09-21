/*
 * Enter and execute Program 10.3a on your computer.
 * Add an fclose() function to Progrma 10.3b and then execute the program.
 *
 */

#include <stdlib.h>
#include <stdio.h>

int
main()
{
	FILE *inFile;
	char fileName[13] = "prices.dat";

	inFile = fopen(fileName, "r");
	if (inFile == NULL)
	{
		printf("\nThe file %s was not successfully opened.", fileName);
		printf("\nPlease check that the file currently exist.\n");
	}
	else
	{
		printf("\nThe file has been successfully opened for reading.\n");
		if (fclose(inFile) == 0) 
		{
			printf("\nThe file has been successfully closed.\n");
		}
	}

	return 0;
}
