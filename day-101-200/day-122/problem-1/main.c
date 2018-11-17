/*
 * Write a C function named readBytes() that reads and displays a character
 * starting from any position in a file. The function should accept three
 * arguments a file pointer, the offset of the first character to read, and
 * the number of characters to be read.
 *
 * Modify the function readBytes to store the characters read into a string
 * or an array. The function should accept the address of the storage area
 * as a fourth argument.
 *
 */

#include <stdio.h>

typedef struct _fileInfo 
{
	long int Size;
	int CurrentPosition;
} FileInfo;

void
ReadBytes(FILE *file, int offset, int n, char *stringBuffer);

int
main()
{
	FILE *readFile = NULL;

	if (readFile = fopen("./data/test.dat", "r"))
	{
		int offset = 0;
		int readCharacters = 0;

		printf("Enter an offset: ");
		scanf("%d", &offset);

		printf("Enter read characters: ");
		scanf("%d", &readCharacters);

		char stringBuffer[256] = { 0 };

		ReadBytes(readFile, offset, readCharacters, stringBuffer);

		printf("%s", stringBuffer);

		fclose(readFile);
	}

	return 0;
}

void
ReadBytes(FILE *file, int offset, int n, char *stringBuffer)
{
	if (file)
	{
		FileInfo fileInfo;
		fseek(file, 0L, SEEK_END);
		fileInfo.Size = ftell(file);
		rewind(file);
		if (fileInfo.Size >= (offset + n))
		{
			fseek(file, (long int)offset, SEEK_CUR);
			int i = 0;
			for (i = 0; i < n; ++i)
			{
				*(stringBuffer + i) = fgetc(file);
			}
		}
		else
		{
			printf("error - cannot read past end of file\n");
		}
	}	
}
