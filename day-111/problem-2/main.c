/*
 * Enter and execute Program 10.2 on your computer.
 *
 */

#include <stdlib.h>
#include <stdio.h>

int
main()
{
	char response;
	FILE *outFile;

	outFile = fopen("prices.dat", "r");
	if (outFile != NULL)
	{
		printf("\nA file by the name prices.dat exists.");
		printf("\nDo you wan to continue and overwrite it");
		printf("\n with the new data (y or n): ");
		scanf("%c", &response);
		if (response == 'n')
		{
			printf("\nThe existing file will not be overwritten.\n");
			exit(1);
		}
	}
	outFile = fopen("prices.dat", "w");
	if (outFile == NULL)
	{
		printf("\nThe file was not successfully opened.\n");
		exit(1);
	}
	printf("\nThe file has been successfully opened for output.\n");

	return 0;
}
