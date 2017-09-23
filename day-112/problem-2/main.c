/*
 * Using the gets() and fputs() functions, write a C program that accepts lines of
 * text from the keyboard and writes each line to a file named text.dat until
 * and empty line is entered. An empty line is a line with no text - just a new
 * line caused by pressing the Enter key.
 *
 * Replace the gets() function in the program with an equivalent call to fgets().
 *
 * Modify the program to read and display the data stored in the text.dat file.
 *
 */

#include <stdbool.h>
#include <stdio.h>

#define Size 1024

void
WriteTextToFile(char *stringBuffer, char *outputFileName);

bool
IsTerminatedString(char c);

int
main()
{
	char StringBuffer[Size] = { 0 };

	int i = 0;
	printf("*** Output will be written to ./data/text.dat ***\n");
	printf("Enter in lines of text here:\n");

	WriteTextToFile(StringBuffer, "./data/text.dat");

	return 0;
}

void
WriteTextToFile(char *stringBuffer, char *outputFileName)
{
	FILE *outputFile = fopen(outputFileName, "a+");
	if (outputFile)
	{
		do 
		{
			/*
			gets(stringBuffer);
			fputs(stringBuffer, outputFile);
			*/
			fgets(stringBuffer, Size, stdin);
			if (!IsTerminatedString(*(stringBuffer + 0)))
			{
				fputs(stringBuffer, outputFile);
			}
		} while (!IsTerminatedString(*(stringBuffer + 0)));
		fclose(outputFile);
	}
}

bool
IsTerminatedString(char c)
{
	bool result = false;
	switch (c)
	{
		case ' ': 
		case '\n':
		case '\0':
		{
			result = true;
		} break;

		default:
		{
		} break;
	}
	return result;
}

