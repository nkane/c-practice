/*
 * Write a program that opens a file and displays the contents of the file with associated
 * line numbers. That is, the program should print 1 before displaying the first line, 2
 * before displaying the second line, and son on for each line in the file.
 *
 * Modify the program written to list the contents of the file on the contents of the file
 * on the printer assigned to you computer.
 * 
 */

#include <stdbool.h>
#include <stdio.h>

#define error(message, args)(printf("ERROR: " message "\n", args))

#define Size 512

typedef struct _currentLineInfo
{
	int Number;
	char *TextBuffer;
} CurrentLineInfo;

void
ClearBuffer(CurrentLineInfo *lineInfo, int length);

bool
ReadLine(FILE *file, CurrentLineInfo *outLineInfo);

int
main()
{
	char *fileLocation = "./data/data.dat";
	FILE *ReadFile = NULL;
	CurrentLineInfo *LineInfo = (CurrentLineInfo *)malloc(sizeof(CurrentLineInfo)); 
	LineInfo->TextBuffer = (char *)malloc(sizeof(char) * Size);
	LineInfo->Number = 0;

	if (ReadFile = fopen(fileLocation, "r"))
	{ 
		ClearBuffer(LineInfo, Size - 1);
		while (ReadLine(ReadFile, LineInfo))
		{
			printf("%d - %s\n\n", LineInfo->Number, LineInfo->TextBuffer);
			ClearBuffer(LineInfo, Size - 1);
		}
		ClearBuffer(LineInfo, Size - 1);
		fclose(ReadFile);
	}
	else 
	{
		error("could not read file -> %s", fileLocation);
	}

	if (LineInfo)
	{
		if (LineInfo->TextBuffer)
		{
			free(LineInfo->TextBuffer);
		}
		free(LineInfo);
	}

	system("pause");

	return 0;
}

bool
ReadLine(FILE *file, CurrentLineInfo *outLineInfo)
{
	bool result = true;
	int i = 0;
	char c;
	while ((c = fgetc(file)) != '\n' && c != EOF)
	{
		*(outLineInfo->TextBuffer + i) = c;
		++i;
	}
	if (c == EOF)
	{
		result = false;
	}
	else
	{
		*(outLineInfo->TextBuffer + i) = '\0';
		++outLineInfo->Number;
	}
	return result;
}

void
ClearBuffer(CurrentLineInfo *lineInfo, int length)
{
	int i = 0;
	for (i = 0; i < length; ++i)
	{
		*(lineInfo->TextBuffer + i) = '\0';
	}
}

