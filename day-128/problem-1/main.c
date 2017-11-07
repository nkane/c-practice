/*
 * Enter and execute Program 10.12. Once the prices.bin file has been written,
 * execute Program 10.12 a second time to verify that is does not overwrite
 * the existing file without your permission.
 * 
 */

#include <stdio.h>
#include <stdlib.h>

int
main()
{
	char response;
	char fileName[20] = "./data/prices.bin";
	FILE *outFile;
	int num1 = 125;
	long num2 = -125;
	double num3 = 1.08;
	outFile = fopen(fileName, "r");
	if (outFile != NULL)
	{
		printf("\nA file by the name %s exists.", fileName);
		printf("\nDo you want to continue and overwrite it");
		printf("\nwith the new data (y or n): ");
		scanf("%c", &response);
		if (response == 'n')
		{
			printf("\nThe existing file %s will not be overwritten.\n", fileName);
			fclose(outFile);
			exit(1);
		}
	}
	outFile = fopen(fileName, "wb");
	if (outFile == NULL)
	{
		printf("\nThe file %s was not successfully opened.\n", fileName);
		exit(1);
	}
	fwrite(&num1, sizeof(num1), 1, outFile);
	fwrite(&num2, sizeof(num2), 1, outFile);
	fwrite(&num3, sizeof(num3), 1, outFile);
	fclose(outFile);
	printf("\nThe file %s has successfully been written as a binary file.\n", fileName);
	return 0;
}
