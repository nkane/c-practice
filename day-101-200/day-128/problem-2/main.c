/*
 * Enter and execute Program 10.13 on your computer.
 *
 */

#include <stdio.h>
#include <stdlib.h>

int
main()
{
	FILE *inFile;
	char fileName[20] = "./data/prices.bin";
	int num1;
	int num2;
	double num3;

	inFile = fopen(fileName, "rb");
	if (inFile == NULL)
	{
		printf("\nThe file %s was not successfully opened.", fileName);
		printf("\nPlease check that the file currently exists.\n");
		exit(1);
	}

	fread(&num1, sizeof(num1), 1, inFile);
	fread(&num2, sizeof(num2), 1, inFile);
	fread(&num3, sizeof(num3), 1, inFile);

	fclose(inFile);
	printf("The data input from the %s file is: ", fileName);
	printf("%d %ld %lf", num1, num2, num3);
	printf("\n");

	return 0;
}
