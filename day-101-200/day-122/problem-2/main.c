/*
 * Assume that a data file consisting of a group of individual lines
 * has been created. Write a C function named printLine() that will
 * read and display any desired line of the file. For example, the
 * function call printLine(fileName, 5); should display the fifth
 * line of the filename passed to it.
 *
 */

#include <stdio.h>

void
PrintLine(char *fileName, int lineNumber);

int
main()
{
	int line = 0;

	printf("Enter line number to read: ");
	scanf("%d", &line);

	if (line > 0)
	{
		PrintLine("./data/test.dat", line);
	}

	return 0;
}

void
PrintLine(char *fileName, int lineNumber)
{
	int i = 0;
	FILE *file = fopen(fileName, "r");
	if (file)
	{
		char stringBuffer[256] = { 0 };
		for (i = 1; i <= lineNumber; ++i)
		{
			fgets(stringBuffer, 256, file);
			if (i == lineNumber) 
			{
				printf("%s", stringBuffer);
			}
			else
			{
				int j = 0;
				for (j = 0; j < 256; ++j)
				{
					*(stringBuffer + j) = 0;
				}
			}
		}
		fclose(file);
	}
}
