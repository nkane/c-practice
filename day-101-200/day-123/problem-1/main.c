/*
 * Rewrite the function GetOpen() used in Program 10.9 to incorporate
 * the file-checking procedures described in the text. Specifically,
 * if the entered filename exists, an appropriate message should be
 * displayed. The user should then be presented with the option of
 * entering a new filename or allowing the program to overwrite the
 * existing file, append to it, or exit.
 *
 */

#include <stdlib.h>
#include <stdio.h>

enum FileCheckEnum
{
	None      = 0x00,
	Append    = 0x01,
	Overwrite = 0x02,
};

int
FileCheck(char *fileName);

FILE *
GetOpen();

void
InOut(FILE *f);

int
main()
{
	FILE *outFile;

	outFile = GetOpen();
	InOut(outFile);

	fclose(outFile);
	printf("\nThe file has been successfully written.\n");

	return 0;
}

int
FileCheck(char *fileName)
{
	int result = None;
	FILE *file;
	file = fopen(fileName, "r");
	if (file == NULL)
	{
		file = fopen(fileName, "w");
		result = Overwrite;
	}
	else
	{
		char c;
		printf("File Exist!\nAppend or overwrite? (a/o):");
		scanf(" %c", &c);
		getchar();
		switch (tolower(c))
		{
			case 'a':
			{
				result = Append;
			} break;

			case 'o':
			{
				result = Overwrite;
			} break;

			default:
			{
				result = Append;
			} break;
		}
	}
	fclose(file);
	return result;
}

FILE *
GetOpen()
{
	FILE *fname;
	char name[13];
	printf("Enter the file name: ");
	gets(name);
	switch (FileCheck(name))
	{
		case Append:
		{
			fname = fopen(name, "a");
		} break; 

		case Overwrite:
		{
			fname = fopen(name, "w");
		} break;
	}
	if (fname == NULL)
	{
		printf("\nFailed to open file %s.\n", name);
		exit(1);
	}
	return (fname);
}

void
InOut(FILE *f)
{
	int count;
	char line[81] = { 0 };
	printf("Please enter five lines of text:\n");
	for (count = 0; count < 5; count++)
	{
		gets(line);
		fprintf(f, "%s\n", line);
	}
}
